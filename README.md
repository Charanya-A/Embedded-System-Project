# Real-Time LPG Leakage Detection System using MQ-5 sensor and Arduino UNO

## Overview

The LPG Leakage Detection System is a real-time gas detection and alert system using an MQ-5 sensor and Arduino UNO. It helps prevent gas-related accidents by triggering alerts when dangerous levels of LPG are detected.

## Features

- Real-time LPG detection using MQ-5 sensor
- Audible and visual alarms for leakage alerts
- Low power consumption and cost-effective design
- Easy installation and user-friendly interface

## Tech Stack & Components

- **Hardware**: MQ-5 Gas Sensor, Arduino UNO, GSM Module, LCD Display, Servo Motor

- **Software**: Arduino IDE

## Software Installation

1. Install Arduino IDE
- Download and install the Arduino IDE suitable for your operating system.

2. Download Required Libraries

- MQ-5 Gas Sensor: Install the library for the MQ-5 sensor from the Arduino Library Manager.
- LiquidCrystal: Install the LiquidCrystal library for controlling the LCD display.

3. Upload the Code to Arduino UNO

- Open the Arduino IDE and load the provided code into the editor.
- Select the appropriate board (Arduino UNO) and port.
- Click on the "Upload" button to upload the code to the Arduino.

## Usage

1. Power on the Device

- Ensure all components are properly connected.

2. Continuous Monitoring of LPG Levels

- The system will continuously monitor the LPG levels in real-time using the MQ-5 gas sensor.

3. When LPG Leakage is Detected:

- LCD Display Notification: The system will display an alert on the LCD indicating the detected leakage.

- Gas Regulator Shutdown: The servo motor will automatically turn off the gas regulator to stop the gas flow.

- Alert Notifications: The system will send an SMS and make a call to the user via the GSM module to alert them about the leakage.




