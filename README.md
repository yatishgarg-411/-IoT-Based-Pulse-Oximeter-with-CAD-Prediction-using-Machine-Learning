# IoT-Based Pulse Oximeter with CAD Prediction using Machine Learning

Overview

This project presents a complete solution for capturing BPM (Beats Per Minute) and SpO2 (Oxygen Saturation) readings from a person using an IoT-based wearable device. The data is processed and stored in a Google Spreadsheet and subsequently analyzed using a trained machine learning model to predict whether the person has Coronary Artery Disease (CAD).
The project integrates hardware components, IoT functionalities, and machine learning to deliver a seamless end-to-end system.
Features

Real-time monitoring of BPM and SpO2 using MAX30100 Sensor.
Bluetooth-enabled ESP32 microcontroller for wireless data transfer.
Automatic data logging in a Google Spreadsheet using Python.
CAD prediction using an ensemble ML model comprising ANN, SVM, and Logistic Regression.
Comprehensive visualization of hardware, software, and data flow.

Hardware Requirements

ESP32: Microcontroller for data processing and communication.
MAX30100 / MAX30102: Pulse oximeter and heart-rate sensor.
I2C Display (Optional): For real-time display of readings.
Power Source: Rechargeable Li-Po battery with a battery management module.
Miscellaneous: Resistors, jumper wires, and a breadboard for prototyping.
Hardware Connections
ESP32 Pin	MAX30100 Pin
3.3V	VIN
GND	GND
GPIO 22 (I2C SCL)	SCL
GPIO 21 (I2C SDA)	SDA
Software Components

Arduino IDE:
Code for capturing sensor readings and transmitting data via Bluetooth.
File: Pulse_Oximeter.ino
Python (Jupyter Notebook):
Google Sheets integration for data logging.
File: Spreadsheet_Logger.ipynb
Machine Learning Model:
Ensemble model (ANN, SVM, Logistic Regression) for CAD prediction.
File: CAD_Prediction_Model.ipynb
Dataset: Dataset.csv
Installation and Setup

1. Clone the Repository
git clone https://github.com/YourUsername/IoT-Pulse-Oximeter.git
cd IoT-Pulse-Oximeter
2. Install Required Libraries
Arduino Libraries:
Install the following libraries in the Arduino IDE:
LiquidCrystal_I2C
MAX30100_PulseOximeter
BluetoothSerial
Place the provided libraries/ folder in your Arduino libraries directory.
Python Libraries:
Install Python dependencies using pip:
pip install gspread oauth2client pyserial
3. Google Sheets API
Download your Google Service Account JSON file and place it in the root directory.
Replace SERVICE_ACCOUNT_FILE and sheet_id in Spreadsheet_Logger.ipynb with your credentials and Google Sheet ID.
Usage

1. Hardware Setup
Assemble the hardware as per the connections mentioned above.
Power the ESP32 module.
2. Upload Code
Open Pulse_Oximeter.ino in Arduino IDE.
Select the appropriate board (ESP32) and port, then upload the code.
3. Start Data Logging
Run the Jupyter notebook Spreadsheet_Logger.ipynb to log data into Google Sheets.
4. CAD Prediction
Use CAD_Prediction_Model.ipynb to predict CAD based on collected readings.
Project Workflow

Hardware Integration:
The ESP32 captures BPM and SpO2 using the MAX30100 sensor.
Readings are displayed on the I2C display and sent to the Python script via Bluetooth.
Data Logging:
The Python script reads data from ESP32, processes it, and logs it in a Google Spreadsheet.
Machine Learning:
The collected data is fed into the ML model for CAD prediction.
Repository Structure

.
├── Pulse_Oximeter.ino             # Arduino code for ESP32
├── Spreadsheet_Logger.ipynb       # Jupyter Notebook for Google Sheets logging
├── CAD_Prediction_Model.ipynb     # Jupyter Notebook for ML-based CAD prediction
├── Dataset.csv                    # Dataset used for training the ML model
├── libraries/                     # Necessary Arduino libraries
├── video.mp4                      # Demonstration video
└── README.md                      # Project documentation
Demonstration Video

A detailed video showcasing the hardware setup, software functionality, and data analysis process is available: Watch Video.
Future Enhancements

Integration of additional health parameters for prediction.
Development of a mobile application for real-time monitoring and alerts.
Cloud integration for long-term data storage and analytics.
Acknowledgments

This project was developed as a blend of IoT and machine learning technologies, emphasizing real-world healthcare solutions. Special thanks to the open-source libraries and frameworks that made this project possible.
