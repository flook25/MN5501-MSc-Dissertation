# MN5501: MSc Dissertation

[![Arduino](https://img.shields.io/badge/Arduino-Mega_2560-00979D?logo=arduino)](https://www.arduino.cc/)
[![MATLAB](https://img.shields.io/badge/MATLAB-Data_Analysis-orange?logo=mathworks)](https://www.mathworks.com/)
[![Status](https://img.shields.io/badge/Status-Completed-brightgreen)]()

---

<div align="center">

<img src="assets/brunel.png" height="100" alt="Brunel University London Logo"/>

## MN5501: Dissertation
### Brunel University London
### Department of Mechanical and Aerospace Engineering

</div>

---

## Project Overview

**Design and Development of an Algorithm for Object Shape Detection Based on Optoelectronic Technology**  
This repository contains the hardware firmware and data analysis algorithms developed for my MSc dissertation. The project explores the use of a 4-channel Time-of-Flight (ToF) sensor array (VL6180X) combined with mathematical polynomial curve fitting to perform real-time, color-independent object shape detection. It is designed to provide a computationally lightweight alternative to high-resolution vision systems for industrial edge-computing applications.

---

## Key Engineering Objectives

The project is divided into four key analytical phases:

1. **Hardware Integration & Dynamic I²C:** Developing an Arduino-based firmware that bypasses traditional hardware multiplexers by using hardware Enable (`EN`/`XSHUT`) pins to dynamically reassign unique operational addresses to four identical VL6180X sensors on a single I²C bus.
2. **Data Acquisition:** Transmitting real-time linear distance measurements via serial communication to Microsoft Excel Data Streamer for signal averaging and stabilization.
3. **Coordinate Transformation:** Mathematically mapping 1D raw distance readings into a 2D Cartesian spatial coordinate system based on the geometric parameters of the custom 3D-printed sensor fixture.
4. **Surface Reconstruction & Shape Classification:** Utilizing **MATLAB** to perform 2nd-order polynomial curve fitting ($y = ax^2 + bx + c$). The algorithm evaluates the quadratic coefficient to autonomously classify target geometries (e.g., convex surfaces).

---

## System Architecture

<div align="center">
<img src="assets/experimental_setup.png" width="800" alt="Physical Experimental Setup"/>
<br/>
<i>Physical implementation of the 4-channel VL6180X ToF sensor array and the custom 3D-printed linear guide mechanism.</i>
</div>
<br/>

The core engineering logic and hardware setups include:
* **Microcontroller:** Arduino Mega 2560 (`main.ino` for dynamic addressing and data polling).
* **Sensors:** 4x STMicroelectronics VL6180X Optoelectronic ToF Modules.
* **Actuation:** Micro servo motors controlled via a PCA9685 16-channel 12-bit PWM controller.
* **Analytical Software:** MATLAB (`surface_reconstruction.m` for polynomial boundary extraction and graphical plotting).

---

## Project Advisor

<div align="center">
<img src="assets/Yohan.jpeg" height="160" alt="Dr. Yohan Noh"/>
<br/>
<b>Dr. Yohan Noh</b>  
Academic Supervisor 
</div>

---

## File Structure

```bash
├── firmware/
│   └── main.ino                  # Arduino Mega 2560 dynamic I2C firmware
├── analysis/
│   └── surface_reconstruction.m  # MATLAB script for polynomial curve fitting
├── assets/
│   ├── brunel.png                # University Logo
│   ├── Yohan.jpeg                # Advisor Image
│   ├── experimental_setup.png    # Physical hardware setup image
│   ├── circuit_diagram.png       # Hardware schematic layout
│   └── coordinate_model.png      # Geometric transformation model
├── Dissertation_Kittitouch.pdf   # Full MSc Dissertation Report
└── README.md                     # Project Documentation (This file)
```