# a07g-exploring-the-CLI

* Team Number:
* Team Name:
* Team Members:
* GitHub Repository URL:
* Description of test hardware: (development boards, sensors, actuators, laptop + OS, etc)

1. Hardware Requirements Specification (HRS)
1.1 Overview
The Badminton Assist Device is a lightweight, IoT-enabled training tool that attaches to the base of a badminton racket handle. It is designed to monitor key performance metrics (such as hit count, stroke force, and time between hits) using a combination of sensors. The device processes data with a microcontroller and provides feedback through visual (LED) and auditory (buzzer) signals. It wirelessly transmits data to a companion mobile app for detailed analysis.

1.2 Definitions, Abbreviations
MCU: Microcontroller Unit
I2C: Inter-Integrated Circuit, a communication protocol used by the sensors
MPU6050: A type of accelerometer and gyroscope sensor used for motion and vibration detection
LED: Light Emitting Diode, used for visual feedback
Li-ion Battery: Lithium-ion Battery, the power source for the device
Wi-Fi: Wireless communication technology for data transmission
SAMW25: The primary microcontroller and Wi-Fi module for the device
1.3 Functionality
HRS 01
The project shall be based on the SAMW25 microcontroller, which integrates the SAMD21 microcontroller core and the WINC1500 Wi-Fi IC. This microcontroller will handle data processing, sensor integration, and wireless communication.

HRS 02
An MPU6050 accelerometer and gyroscope sensor shall be used to detect racket movements and vibrations. This sensor will measure stroke force, hit detection, and movement patterns. It shall communicate with the SAMW25 via the I2C protocol.

HRS 03
A vibration sensor shall be included to detect shocks transmitted through the racket handle when the shuttlecock is hit. This sensor will improve the accuracy of hit detection and confirm successful shots.

HRS 04
The device shall include a small LED that lights up after every successful hit, providing immediate visual feedback to the user. The LED shall be controlled by the SAMW25 microcontroller.

HRS 05
A buzzer shall be integrated into the device to sound when the player reaches their target hit count, providing auditory feedback. The buzzer shall also be controlled by the SAMW25.

HRS 06
The device shall be powered by a **single-cell Li-ion battery **. It must include a charging circuit to allow for convenient recharging via a USB port.

HRS 07
The entire device, including sensors, actuators, and the microcontroller, shall weigh less than 50 grams to ensure it does not affect the balance or feel of the badminton racket during play.

2. Software Requirements Specification (SRS)
2.1 Overview
The Badminton Assist Device software processes data collected from sensors, provides real-time feedback via actuators, and wirelessly transmits performance metrics to a mobile application. The software is designed to monitor hit count, stroke force, and playing duration, while enabling users to set training goals through the companion app. It ensures efficient power management and seamless IoT integration.

2.2 Users
The primary users of this device include:

Casual Players: Individuals who play badminton recreationally and wish to track their performance for improvement.
Amateur Competitors: Players preparing for local or school-level tournaments who want to measure and refine their skills.
Coaches and Trainers: Professionals who want to monitor player progress and provide data-driven feedback.
2.3 Definitions, Abbreviations
MCU: Microcontroller Unit
I2C: Inter-Integrated Circuit communication protocol
MPU6050: Accelerometer and gyroscope sensor
LED: Light Emitting Diode
Wi-Fi: Wireless Fidelity, used for data transmission
App: The mobile application that interfaces with the device for data visualization and configuration
SRS: Software Requirements Specification
2.4 Functionality
SRS 01
The software shall read 3-axis acceleration and gyroscope data from the MPU6050 sensor every 10 milliseconds via the I2C protocol. This data will be used to calculate stroke force, movement patterns, and vibration analysis.

SRS 02
The software shall detect vibrations from the vibration sensor to accurately confirm a hit when the shuttlecock impacts the racket.

SRS 03
The software shall calculate and store the following performance metrics:

Total hit count during the session.
Time intervals between consecutive hits (for rhythm analysis).
Stroke force based on accelerometer and gyroscope data.
SRS 04
The software shall control the LED to light up after each confirmed hit, providing immediate visual feedback to the user.

SRS 05
The software shall activate the buzzer when the target hit count, set by the user in the companion app, is reached.

SRS 06
The software shall transmit the collected and processed data (e.g., hit count, stroke force, time intervals) to the mobile app in real-time via Wi-Fi using the SAMW25 module.

SRS 07
The software shall enable users to set training goals (e.g., target hit count) through the companion app and configure the feedback mechanisms (e.g., turning LED or buzzer on/off).

SRS 08
The software shall implement a power-saving mode that minimizes battery usage by entering a low-power state when no activity is detected for a predefined duration (e.g.30 seconds).

SRS 09
The software shall provide error handling for sensor data inconsistencies or communication failures. If an error occurs, it shall notify the user via the app.
