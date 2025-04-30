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
- **MAX30100**: Pulse oximeter and heart rate sensor.
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
![image](https://github.com/user-attachments/assets/64c0e0fd-adbd-47e3-b508-5d0311f99275)
![image](https://github.com/user-attachments/assets/64c161c7-1afa-434d-a962-47934c8621b3)

2. Save this file as a sketch in your Arduino IDE.
![image](https://github.com/user-attachments/assets/ecd618c5-8ed0-48fe-8371-f5e6bc44e178)
![image](https://github.com/user-attachments/assets/222841af-7ae2-41e3-9a7f-4f3cbf07ab82)

3. Locate the folder(Documents in Windows) where you saved the sketch.
![image](https://github.com/user-attachments/assets/4613de71-745e-4005-86f6-9dc2d751b0f9)
![image](https://github.com/user-attachments/assets/e99131a8-0408-4014-948f-dc44f5196775)


4. Open this folder to access additional files.
![image](https://github.com/user-attachments/assets/48438dfa-aa2b-492b-9b6c-d83642ed0bb6)
5. Within the sketch folder, download the following files
   take_readings.ipynb,
   ml.ipnb,
   dataset.csv
![image](https://github.com/user-attachments/assets/1a453a5b-9fae-45c1-a81a-ce7220aaed49)

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

##### 5. Verify ESP32 Connection
1. Connect your ESP32 board to the computer via a USB cable.
2. Open Device Manager (Win + X → Device Manager).
3. Under Ports (COM & LPT), check if Silicon Labs CP210x USB to UART (COMx) appears.
4. If it appears, the driver is installed correctly. Therefore Skip Step 6
5. If it appears under Other Devices, follow Step 6.
   
##### 6. Install CP210x USB-to-Serial Driver
1. Download the CP210x Universal Windows Driver from Silicon Labs:🔗[CP210x Driver Download](https://www.silabs.com/developer-tools/usb-to-uart-bridge-vcp-drivers?tab=downloads)
2. Extract the downloaded ZIP file.
3. Right-click silabser.inf and select Install.
![image](https://github.com/user-attachments/assets/bcd159cb-f7c1-4547-a35f-80bc4818fc86)
5. Restart your computer after installation.

##### 7. Select ESP32 Board & Port in Arduino IDE
1. Open Arduino IDE.
2. Go to Tools → Board and select ESP32-WROOM-DA Module.
![image](https://github.com/user-attachments/assets/cbb33f50-b22b-4def-bf07-8d48f32c534a)
4. Go to Tools → Port and select the correct COM port (e.g., COM3, COM6).
5. Set Upload Speed to 115200 baud.
6. Open Serial Monitor (Tools → Serial Monitor) and set baud rate to 115200.
![image](https://github.com/user-attachments/assets/8b83b548-403f-49b4-9917-38c31398397c)
![image](https://github.com/user-attachments/assets/a39fe59a-cbb6-448a-8545-f6d7b390ff93)

#### 8. Final Upload
1. Click on Verify
2. After complete verification, click on upload.
3. After uploading is completed, open serial monitor and place your finger on the sensor to take readings.
   
### 3. Google Sheets Integration
##### Step 1: Enable Google Sheets API
1. Go to the Google Cloud Console
![image](https://github.com/user-attachments/assets/4d33fb2e-a5c3-4a1a-813b-5286c789f10b)
![image](https://github.com/user-attachments/assets/a7c653bd-c434-44b0-95cb-5fde7f2736e0)

2. Create a new project (or use an existing one) by clicking on the project button on right handside of Google Cloud Logo.
![image](https://github.com/user-attachments/assets/0112f438-7122-4e22-9259-864a470be2e7)
![image](https://github.com/user-attachments/assets/07ee75f3-c01b-4863-bdca-509d76633c2d)



3. Navigate to "APIs & Services" > "Library".
![image](https://github.com/user-attachments/assets/5157df0f-3176-47f5-852c-59fad58ccf4c)
![image](https://github.com/user-attachments/assets/81ed1d18-c3f7-4db1-9b37-31d2dddb1b35)
![image](https://github.com/user-attachments/assets/cd2ff018-1f19-4ad8-829f-dc9f3f0dcd95)


4. Search for "Google Sheets API" and enable it.
![image](https://github.com/user-attachments/assets/32ce435a-6951-426d-9370-acb44827928e)
![image](https://github.com/user-attachments/assets/ad52a14b-f0bc-434c-a203-ab67af914aec)
![image](https://github.com/user-attachments/assets/e8f15dec-f278-4ccd-acec-a94a53fcd315)

5. Also enable the "Google Drive API" (needed for authentication).
![image](https://github.com/user-attachments/assets/1695a4ee-8e89-4e89-939c-322e996d4feb)
![image](https://github.com/user-attachments/assets/4b92c88e-29bf-4e92-a209-9391e01b2919)

##### Step 2: Create a Service Account and Get Credentials

1. Go to "APIs & Services" > "Credentials" by clicking on Navigation Menu drawer button on the left.
![image](https://github.com/user-attachments/assets/ac708c46-a211-4ec7-9601-6a728d045abb)
![image](https://github.com/user-attachments/assets/87533256-f71d-485d-ba34-88dd7fc585b5)

2. Click "Create Credentials" > "Service Account".
![image](https://github.com/user-attachments/assets/cc9becc7-62a0-4c8b-9f03-928f39241525)
![image](https://github.com/user-attachments/assets/684de3f7-675f-49f8-808c-257b644addf2)

3. Fill in the details and click "Create".
![image](https://github.com/user-attachments/assets/3ad008f8-7196-466a-872c-aa9ab5d475c1)

4. Under "Grant this service account access to the project", assign Editor role.
![image](https://github.com/user-attachments/assets/34b7fe4d-a5f6-474d-91ad-89f71d7c39ce)
![image](https://github.com/user-attachments/assets/758fea4e-d2dd-43b8-a5af-6d4b6d5eb2a2)

5. Click "Continue", then "Done".
6. Go to "APIs & Services" > "Credentials", select your service account and click on service account link in blue.
![D17C641C-A309-4F0A-833F-009CE14A7F25_1_201_a](https://github.com/user-attachments/assets/28c95c47-1532-4aa0-995e-50827836249d)

7. Under "Keys", click "Add Key" > "Create New Key".
![image](https://github.com/user-attachments/assets/1ac0f86f-ed90-4cd4-b451-82f288588544)
![image](https://github.com/user-attachments/assets/269625b5-dd13-4b5c-ae44-d4f3d2964070)


8. Select JSON format and download the file.
![image](https://github.com/user-attachments/assets/390712fc-2033-4043-a0e8-e188634e6a75)

9. Move the JSON file to your project directory.
##### Step 3: Share Your Google Sheet with the Service Account
1. Open your Google Sheet.
2. Click "Share".
3. Copy the email from your JSON file (it looks like your-service-account@your-project.iam.gserviceaccount.com).
4. Paste this email into the "Share" field and give Editor access.Click "Send".
5. The google sheet id is there in the url section when you open the google sheet e.g "https://docs.google.com/spreadsheets/d/sheet_id/edit?gid=0#gid=0"
![image](https://github.com/user-attachments/assets/d2fa1e00-a867-4a2b-84e9-75c32a0af3d6)
6.  Configure the Jupyter notebook to log data into your Google Sheet by updating sheet id and port number.

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
