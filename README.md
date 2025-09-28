# Arduino Color Detector

This is an Arduino-based color detection project using the TCS3200 color sensor and an I2C LCD display. It identifies basic colors (Red, Green, Blue, etc.) and displays the RGB values and color name on an LCD.

# Hardware Components Used

- Arduino Uno (or compatible board)
- TCS3200 color sensor
- 16x2 LCD with I2C module
- Jumper wires
- Breadboard
- USB Cable for programming

# Project Purpose

This project demonstrates how to use the TCS3200 color sensor to detect RGB values and classify colors based on their intensity ranges. It introduces basic embedded programming, sensor calibration, and serial + LCD display output.

# Skills Acquired

- Interfacing sensors with Arduino
- Using LiquidCrystal_I2C library for LCD
- Reading and averaging sensor data
- Conditional logic to classify colors
- Serial communication and debugging

# How to Compile and Upload

1. Open Arduino IDE.
2. Make sure the following libraries are installed:
   - `Wire.h`
   - `LiquidCrystal_I2C.h`
3. Connect your Arduino board via USB.
4. Copy the code from `color_detector.ino` into the Arduino IDE.
5. Select the correct board and COM port.
6. Upload the sketch.

# Notes

- Place a colored object in front of the TCS3200 sensor to detect it.
- Adjust the RGB ranges in the `getColor()` function if necessary for better accuracy based on your sensor's output.

# LCD Output Example

```
R52   G74   B48
Color: GREEN
```

---

