# a07g-exploring-the-CLI

* Team Number:
* Team Name:
* Team Members:
* GitHub Repository URL:
* Description of test hardware: (development boards, sensors, actuators, laptop + OS, etc)

# 1 Software Architecture 
## 1. Hardware Requirements Specification (HRS)

1.1 Overview
The Badminton Assist Device is a lightweight, IoT-enabled training tool that attaches to the base of a badminton racket handle. It is designed to monitor key performance metrics, including hit count, stroke force, and time intervals between hits. The device achieves this using a combination of motion and vibration sensors.

The SAMW25 microcontroller serves as the central processing unit, handling sensor data processing, feedback mechanisms, and wireless communication. Real-time feedback is provided through LED indicators and a buzzer, while performance data is transmitted wirelessly to a companion mobile app for in-depth analysis.

1.2 Definitions, Abbreviations

MCU: Microcontroller Unit
I²C: Inter-Integrated Circuit, a communication protocol for sensor communication
LIS2DS12TR: A low-power 3-axis accelerometer used for step counting and movement detection
MPU6000: A motion-tracking sensor with an accelerometer and gyroscope for stroke force detection
LED: Light Emitting Diode, used for visual feedback
Li-ion Battery: Lithium-ion Battery, the power source for the device
Wi-Fi: Wireless communication technology for data transmission
SAMW25: The primary microcontroller integrating the SAMD21 core and WINC1500 Wi-Fi IC for data processing and wireless communication

1.3 Functionality

HRS 01: The device shall be built around the SAMW25 microcontroller, which integrates the SAMD21 core and WINC1500 Wi-Fi module. This microcontroller will handle sensor integration, data processing, and wireless communication.

HRS 02: A LIS2DS12TR accelerometer shall be used for motion detection and step counting. It will measure movement patterns, estimate stroke force, and track hit counts. Communication with the SAMW25 shall be via the I2C protocol.

HRS 03: A MPU6000 accelerometer and gyroscope sensor shall be included to detect precise racket movements and vibrations. This sensor will improve stroke force estimation and impact accuracy. It shall also communicate with the SAMW25 via I2C.

HRS 04: The device shall include an LED indicator that lights up after each successful hit, providing immediate visual feedback. The SAMW25 shall control the LED.

HRS 05: A buzzer shall be integrated to provide auditory feedback when the player reaches their target hit count. The SAMW25 shall control the buzzer.

HRS 06: The device shall be powered by a single-cell Li-ion battery and include a charging circuit for USB recharging.

HRS 07: The total weight of the device, including all components, shall be less than 50 grams to maintain racket balance and feel.

2.Block digram
![image](https://github.com/user-attachments/assets/b5d4d32f-531d-45fa-b027-35dd82bba2dc)

3.flow digram
![image](https://github.com/user-attachments/assets/64574ee2-96a3-42f4-a320-dd189f2f0074)


## 2. Software Requirements Specification (SRS)

2.1 Overview

The Badminton Assist Device software processes real-time data from sensors, provides immediate feedback via LEDs and a buzzer, and transmits performance metrics to a mobile application. It enables users to monitor hit counts, stroke force, and session duration, while also allowing them to set training goals and configure device feedback settings.

Additionally, the software incorporates power management features to maximize battery life and ensures error handling for sensor inconsistencies.

2.2 Users
The primary users of this device include:

Casual Players – Recreational players who wish to track their performance.
Amateur Competitors – Players training for local or school tournaments seeking data-driven improvement.
Coaches and Trainers – Professionals monitoring player progress to provide structured feedback.

2.3 Definitions, Abbreviations
MCU: Microcontroller Unit
I²C: Inter-Integrated Circuit communication protocol
LIS2DS12TR: Low-power accelerometer for step counting and movement detection
MPU6000: Motion sensor with accelerometer and gyroscope for stroke force analysis
LED: Light Emitting Diode
Wi-Fi: Wireless Fidelity, used for data transmission
App: Mobile application interfacing with the device for data visualization and configuration
SRS: Software Requirements Specification

2.4 Functionality

SRS 01 The software shall read 3-axis accelerometer and gyroscope data from the MPU6000 sensor at 10-millisecond intervals using I²C or SPI protocol to calculate stroke force, movement patterns, and vibration analysis.

SRS 02 The software shall read step count and movement data from the LIS2DS12TR accelerometer to provide real-time motion tracking and refined hit detection.

SRS 03: The software shall detect vibrations from the vibration sensor to confirm a successful shuttlecock impact.

SRS 04 The software shall process sensor data to compute and store the following performance metrics:
Total hit count during the session
Time intervals between consecutive hits for rhythm analysis
Stroke force intensity based on accelerometer and gyroscope data

SRS 05 The software shall control the LED indicator to light up immediately after a successful hit is detected.

SRS 06 The software shall activate the buzzer when the user reaches their target hit count, as set in the mobile app.

SRS 07 The software shall transmit real-time performance data (e.g., hit count, stroke force, time intervals) to the mobile app via Wi-Fi using the SAMW25 module. The data transmission rate shall be optimized to minimize latency.

SRS 08 The software shall allow users to set training goals (e.g., target hit count) and configure feedback mechanisms (e.g., turning LED or buzzer on/off) through the companion app.

SRS 09 The software shall implement a power-saving mode that enters low-power sleep state when no activity is detected for 30 seconds, reducing unnecessary battery drain.

SRS 10 The software shall include error handling for:
Sensor data inconsistencies (e.g., missing or noisy readings).
Communication failures between the MCU and sensors.
Wi-Fi transmission errors (e.g., lost connection).
When an error occurs, the device shall notify the user via the app and optionally trigger an LED or buzzer alert.

# 2. Understanding the starter code

1. What does InitializeSerialConsole() do? What is cbufRx and cbufTx? What type of data structure is it?

InitializeSerialConsole() sets up the UART interface and registers its read/write callbacks. Specifically, it:

Initializes two circular buffers: cbufRx for receiving and cbufTx for transmitting.

Configures the SERCOM module (USART) to 115200 baud, 8N1 format.

Sets up the interrupt callbacks for reading and writing.

Begins an asynchronous read operation to capture the first UART character.
cbufRx and cbufTx are both of type cbuf_handle_t. They are handles to circular (ring) buffers, which are data structures that efficiently store and manage continuous streams of data in a FIFO manner.

2. How are cbufRx and cbufTx initialized? Where is the library that defines them? (Please list the .c file they come from.)

They are initialized using the function circular_buf_init() in InitializeSerialConsole():
cbufRx = circular_buf_init((uint8_t *)rxCharacterBuffer, RX_BUFFER_SIZE);
cbufTx = circular_buf_init((uint8_t *)txCharacterBuffer, TX_BUFFER_SIZE);

These buffers are implemented via a custom circular buffer library. The function circular_buf_init() is defined in the file:
circular_buffer.c

3. Where are the character arrays where the RX and TX characters are being stored at the end? Please mention their name and size.

The character arrays used as backing stores for the circular buffers are:

rxCharacterBuffer[512] — for storing received UART characters.

txCharacterBuffer[512] — for storing characters to be transmitted.

Each buffer is 512 bytes in size.

4. Where are the interrupts for UART character received and UART character sent defined?

The USART interrupt callbacks are registered in the function configure_usart_callbacks() in SerialConsole.c:
usart_register_callback(&usart_instance, usart_write_callback, USART_CALLBACK_BUFFER_TRANSMITTED);
usart_register_callback(&usart_instance, usart_read_callback, USART_CALLBACK_BUFFER_RECEIVED);

The actual callback functions are defined as:

void usart_read_callback(struct usart_module *const usart_module);

void usart_write_callback(struct usart_module *const usart_module);

5. What are the callback functions that are called when:

a. A character is received (RX)?

usart_read_callback(struct usart_module *const usart_module)

b. A character has been sent (TX)?

usart_write_callback(struct usart_module *const usart_module)

6. Explain what is being done on each of these two callbacks and how they relate to cbufRx and cbufTx.

usart_read_callback (RX):
This function is currently marked as TODO in the starter code, but it is meant to be called when a character has been received via UART. In the complete version, it should:

Store latestRx into the cbufRx buffer using circular_buf_put().

Restart the usart_read_buffer_job() to continuously receive the next character.

Optionally notify the CLI thread (via semaphore or task notification) that a new character is available.

usart_write_callback (TX):
This function is already implemented. It:

Checks if there are more characters in cbufTx.

If so, pops the next character using circular_buf_get() and restarts the UART transmission using usart_write_buffer_job().

This mechanism ensures a seamless circular buffer-based UART system where RX characters are added to cbufRx and TX characters are pulled from cbufTx.

7.
![image](https://github.com/user-attachments/assets/28a7c194-45a7-4f12-9105-f085093f706a)

8.
![image](https://github.com/user-attachments/assets/4c11f962-8ed1-4f2e-aeff-606adbdcf2d2)


9. What is done on the function `StartTasks()` in `main.c`? How many threads are started?

The `StartTasks()` function is responsible for initializing FreeRTOS tasks. In the current starter code:

- It prints the amount of heap memory available before starting any tasks.
- It starts the CLI task by calling `xTaskCreate()` with the function `vCommandConsoleTask`.
- It checks if the task was created successfully; if not, it prints an error.
- It then prints the remaining heap after task creation.

Only one thread is started in `StartTasks()`: the CLI task.

# 3. Debug Logger Module
Code uploaded.

# 4. Wiretap the convo
1. TX and GND
2. Just attach to the exposed header pins 
3. Protocol: UART<br>
Baud Rate: 115200 <br>
Data Bits: 8<br>
Parity: None<br>
Stop Bits: 1<br>
Bit Order: LSB first<br>
Capture Edge: Falling edge<br>

