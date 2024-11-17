# IoT-Based Pulse Oximeter with CAD Prediction

An IoT-based project that measures BPM (Beats Per Minute) and SpO2 (Oxygen Saturation) levels using a custom-built hardware setup. The collected data is logged into Google Sheets and analyzed with a machine learning model to predict the likelihood of Coronary Artery Disease (CAD).

---

## Table of Contents
- [Introduction](#introduction)
- [Hardware Components](#hardware-components)
- [Software Components](#software-components)
- [Hardware Connections](#hardware-connections)
- [Setup Instructions](#setup-instructions)
  - [1. Hardware Setup](#1-hardware-setup)
  - [2. Arduino Code](#2-arduino-code)
  - [3. Google Sheets Integration](#3-google-sheets-integration)
  - [4. Machine Learning Model](#4-machine-learning-model)
- [Features](#features)
- [How It Works](#how-it-works)
- [Video Demonstration](#video-demonstration)
- [Folder Structure](#folder-structure)
- [Results](#results)
- [Future Enhancements](#future-enhancements)
- [Acknowledgments](#acknowledgments)
- [License](#license)

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

### 2. Arduino Code
1. Install the necessary Arduino libraries in the `/libraries` folder.
2. Open the `Pulse_Oximeter.ino` file in Arduino IDE.
3. Upload the code to the ESP32.

### 3. Google Sheets Integration
1. Enable the Google Sheets API.
2. Download your Service Account JSON key and save it as `ml-project-441108-d4e5cf52b0af.json`.
3. Configure the Jupyter notebook to log data into your Google Sheet.

### 4. Machine Learning Model
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
[![Watch the video](https://img.youtube.com/vi/your-video-id/hqdefault.jpg)](https://youtu.be/your-video-id)

> Click on the thumbnail to watch the project demo on YouTube.

---

## Folder Structure
📁 IoT-Pulse-Oximeter ├── 📂 Libraries # Arduino libraries required ├── 📂 ML_Model # Jupyter Notebook for ML model ├── 📄 Pulse_Oximeter.ino # Arduino code for ESP32 ├── 📄 Google_Sheets_Logger.ipynb # Jupyter Notebook for data logging ├── 📄 dataset.csv # Dataset for ML training ├── 📄 README.md # Project documentation


---

## Results
The trained ensemble ML model achieved:
- **Accuracy**: 95%
- **Precision**: 93%
- **Recall**: 94%

> The prediction model reliably identifies potential CAD cases based on SpO2 and BPM levels.

---

## Future Enhancements
- Add a mobile app for real-time monitoring.
- Integrate more sensors for additional health metrics.
- Improve battery life for standalone operation.

---

## Acknowledgments
Special thanks to the open-source community and the contributors of libraries for:
- MAX30100 Sensor
- Google Sheets API

---

## License
This project is licensed under the MIT License. See the LICENSE file for details.
