# a07g-exploring-the-CLI

* Team Number:
* Team Name:
* Team Members:
* GitHub Repository URL:
* Description of test hardware: (development boards, sensors, actuators, laptop + OS, etc)

1. Hardware Requirements Specification (HRS)

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

2. Software Requirements Specification (SRS)

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
