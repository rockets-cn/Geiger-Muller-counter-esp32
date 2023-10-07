# DIY Geiger Counter with ESP32 and E-Ink Display

![Project Image](image-link-here)

## Introduction

This project outlines the steps to create a DIY Geiger Counter using a Geiger-Muller tube, an ESP32 module and an E-Ink display, all encased in a custom 3D-printed enclosure. This portable device is capable of detecting and measuring ionizing radiation in real-time, displaying the data on a user-friendly, low-power E-Ink display.

## Features

- Real-time radiation measurement
- Portable and lightweight design
- User-friendly E-Ink display for low power consumption and clear visibility under sunlight
- Custom 3D-printed enclosure for durability and aesthetics
- Easy to use and maintain with modular components

## Hardware Components

- Geiger-Muller Tube
- ESP32 Module
- E-Ink Display
- 3D Printer (for the enclosure)

## Software Dependencies

- Arduino IDE
- Required Libraries:
    - Geiger Library
    - GxEPD2 Library for E-Ink Display

## Getting Started

1. **3D Printing the Enclosure**
    - Design and 3D print the enclosure using the provided STL files.
2. **Setting up the ESP32**
    - Install the Arduino IDE and configure it for ESP32.
    - Install the required libraries through the Library Manager in Arduino IDE.
3. **Wiring**
    - Follow the wiring diagram provided to connect the Geiger-Muller tube, ESP32, and E-Ink display.
4. **Software Configuration**
    - Load the provided Arduino sketch onto the ESP32.
    - Configure any necessary settings such as the Wi-Fi credentials if remote monitoring is desired.
5. **Testing**
    - Power on the Geiger Counter and verify that it's functioning as expected.

## Usage

- The Geiger Counter will begin measuring radiation levels immediately upon powering on.
- The E-Ink display will update with the current radiation level, and historical data can be accessed via the built-in buttons.

## Contributing

Feel free to fork this repository and submit Pull Requests for any improvements or additional features you create. All contributions are welcome!

## License

This project is open-source and is licensed under the MIT License. See the LICENSE file for more details.

## Contact

For any inquiries, issues, or contributions, please open an issue on this GitHub repository.

## Acknowledgements

- DFRobot for providing the ESP32 module and E-Ink Display
- The open-source community for their invaluable resources and support

