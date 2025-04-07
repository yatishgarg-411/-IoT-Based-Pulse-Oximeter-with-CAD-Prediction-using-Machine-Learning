# IoT-Based Pulse Oximeter with CAD Prediction using Machine Learning

An IoT-based project that measures BPM (Beats Per Minute) and SpO2 (Oxygen Saturation) levels using a custom-built hardware setup. The collected data is logged into Google Sheets and analyzed with a machine learning model to predict the likelihood of Coronary Artery Disease (CAD).

---

## Table of Contents
- [Introduction](#introduction)
- [Hardware Components](#hardware-components)
- [Software Components](#software-components)
- [Hardware Connections](#hardware-connections)
- [Setup Instructions](#setup-instructions)
  - [1. Hardware Setup](#1-hardware-setup)
  - [2. Arduino Setup](#2-arduino-setup)
  - [3. Google Sheets Integration](#3-google-sheets-integration)
  - [4. Determining Port Number](#4-determining-port-number)
  - [5. Machine Learning Model](#5-machine-learning-model)
- [Features](#features)
- [How It Works](#how-it-works)
- [Video Demonstration](#video-demonstration)
- [Folder Structure](#folder-structure)
- [Results](#results)

---

## Introduction

This project integrates IoT, real-time data monitoring, and machine learning to predict CAD (Coronary Artery Disease). The hardware collects heart rate and oxygen saturation data, which is logged to Google Sheets and processed by an ensemble ML model for prediction.

---

## Hardware Components
- **ESP32**: Microcontroller for data processing and Bluetooth communication.
- **MAX30100/MAX30102**: Pulse oximeter and heart rate sensor.
- **I2C Display** *(Optional)*: To display BPM and SpO2 in real-time.
- **Power Source**: Rechargeable Li-Po battery and battery management module.
- **Breadboard, Resistors, and Jumper Wires**: For circuit prototyping.

---

## Software Components
- **Arduino IDE**: For programming the ESP32.
- **Python Jupyter Notebook**: For data logging and machine learning.
- **Google Sheets API**: For automatic data storage.
- **Machine Learning Libraries**: Scikit-learn, TensorFlow, etc., for prediction.

---

## Hardware Connections
| MAX30100 Pin | ESP32 Pin  |
|--------------|------------|
| VIN          | 3.3V       |
| GND          | GND        |
| SCL          | GPIO 22    |
| SDA          | GPIO 21    |

> If using an I2C display, connect its **SCL** and **SDA** to GPIO 22 and GPIO 21 respectively.

---

## Setup Instructions

### 1. Hardware Setup
1. Assemble the ESP32 and MAX30100 sensor as per the above connections.
2. Optional: Connect the I2C display for real-time data visualization.
3. Power the setup with a Li-Po battery or USB connection.

### 2. Arduino Setup
##### 1. Install Arduino IDE
1. Download and install Arduino IDE from the official site:🔗 [Arduino IDE Download](https://support.arduino.cc/hc/en-us/articles/360019833020-Download-and-install-Arduino-IDE) or Microsoft/App Store
2. Open Arduino IDE after installation.

##### 2. Downloading files 
1. Copy the code of pulse_oximeter.ino file into a new arduino sketch file
2. Save this file as a sketch in your Arduino IDE.
3. Locate the folder where you saved the pulse_oximeter.ino sketch.
4. Open this folder to access additional files.
5. Within the sketch folder, download the following files
   take_readings.ipynb
   ml.ipnb
   dataset.csv
##### 3. Install ESP32 Board Support
1. Open Arduino IDE.
2. Go to File → Preferences.
3. In the Additional Boards Manager URLs, add the following URLs:
https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json,
https://dl.espressif.com/dl/package_esp32_index.json
![WhatsApp Image 2025-03-29 at 14 28 05](https://github.com/user-attachments/assets/5fa67db2-faa9-498c-9a8a-02a7a0a66038)
5. Click OK.
6. Go to Tools → Board → Boards Manager.
7. Search for ESP32 by Espressif Systems and click Install.
![image](https://github.com/user-attachments/assets/9a7bffb4-193b-4d5a-a65e-5d8effc99449)


##### 4. Install Required Libraries
1. Open Arduino IDE.
2. Go to Sketch → Include Library → Manage Libraries.
3. Search for LiquidCrystal I2C by Macro Schwartz and click Install.
4. Search for Max30100_milan by Gabriel Gazola Milan and click Install.

##### 5. Install CP210x USB-to-Serial Driver
1. Download the CP210x Universal Windows Driver from Silicon Labs:🔗[CP210x Driver Download](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads)
2. Extract the downloaded ZIP file.
3. Right-click silabser.inf and select Install.
![image](https://github.com/user-attachments/assets/bcd159cb-f7c1-4547-a35f-80bc4818fc86)
5. Restart your computer after installation.

##### 6. Verify ESP32 Connection
1. Connect your ESP32 board to the computer via a USB cable.
2. Open Device Manager (Win + X → Device Manager).
3. Under Ports (COM & LPT), check if Silicon Labs CP210x USB to UART (COMx) appears.
4. If it appears, the driver is installed correctly.
5. If it appears under Other Devices, repeat Step 4.

##### 7. Select ESP32 Board & Port in Arduino IDE
1. Open Arduino IDE.
2. Go to Tools → Board and select ESP32-WROOM-DA Module.
![image](https://github.com/user-attachments/assets/cbb33f50-b22b-4def-bf07-8d48f32c534a)
4. Go to Tools → Port and select the correct COM port (e.g., COM3, COM6).
5. Set Upload Speed to 115200 baud.
6. Open Serial Monitor (Tools → Serial Monitor) and set baud rate to 115200.

### 3. Google Sheets Integration
##### Step 1: Enable Google Sheets API
1. Go to the Google Cloud Console
2. Create a new project (or use an existing one).
3. Navigate to "APIs & Services" > "Library".
4. Search for "Google Sheets API" and enable it.
5. Also enable the "Google Drive API" (needed for authentication).
##### Step 2: Create a Service Account and Get Credentials
1. Go to "APIs & Services" > "Credentials".
2. Click "Create Credentials" > "Service Account".
3. Fill in the details and click "Create".
4. Under "Grant this service account access to the project", assign Editor role.
5. Click "Continue", then "Done".
6. Go to "APIs & Services" > "Credentials", select your service account.
7. Under "Keys", click "Add Key" > "Create New Key".
8. Select JSON format and download the file.
9. Move the JSON file to your project directory.
##### Step 3: Share Your Google Sheet with the Service Account
1. Open your Google Sheet.
2. Click "Share".
3. Copy the email from your JSON file (it looks like your-service-account@your-project.iam.gserviceaccount.com).
4. Paste this email into the "Share" field and give Editor access.Click "Send".
5. The google sheet id is there in the url section when you open the google sheet e.g "https://docs.google.com/spreadsheets/d/sheet_id/edit?gid=0#gid=0"
6.  Configure the Jupyter notebook to log data into your Google Sheet.

### 4. Determining Port Number
##### How to Find the Correct Serial Port Number on Mac & Windows?
###### 🔹 On Windows (Find COM Port)
1. Open Device Manager
2. Press Win + X → Click Device Manager.
3. Expand "Ports (COM & LPT)"
4. Look for "USB Serial Device (COMx)".
5. Example: COM3, COM5, etc.
6. Use the COM number in your Python code
7. If you see USB Serial Device (COM3), set: SERIAL_PORT = 'COM3'
###### 🔹 On Mac/Linux (Find /dev/ Port)
1. Open Terminal (Cmd + Space → Type Terminal → Enter).
2. Run this command to list all serial devices: ls /dev/cu.*
3. Look for your device
4. You should see something like:
/dev/cu.usbserial-0001
5. Use that in your Python script:
SERIAL_PORT = '/dev/cu.usbserial-0001'

### 5. Machine Learning Model
1. Train the provided dataset (`dataset.csv`) using the ensemble ML model in the notebook.
2. Use the trained model to predict CAD from SpO2 and BPM values.

---

## Features
- Real-time monitoring of BPM and SpO2.
- Bluetooth functionality for wireless data transfer.
- CAD prediction using an ensemble ML model (ANN, SVM, Logistic Regression).

---

## How It Works
1. The hardware collects BPM and SpO2 readings for 20 seconds per person.
2. Data is sent via Bluetooth as well as serial monitor and logged into Google Sheets using a Python script.
3. The ML model processes the data to predict the likelihood of CAD.
4. The results are displayed and stored for further analysis.

---

## Video Demonstration
[![Watch the video](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRJwINi_84-ocdpyqzvjPI2Yybfn4OCsiMT7A&s)](https://drive.google.com/file/d/1QrqLgvT4xKvINX6XmW9WXsrvykU7lZfL/view?usp=sharing)

> Click on the thumbnail to watch the project demo on YouTube.

---

## Results
The trained ensemble ML model achieved:
- **Accuracy**: 92.56%
- **Precision**: 91.85%
- **Recall**: 93.21%
- **F1 Score**: 92.52%

> The prediction model reliably identifies potential CAD cases based on SpO2 and BPM levels.

---
