# Mini-Digital-Oscilloscope
A compact digital oscilloscope built using an ESP32 microcontroller to visualize analog voltage signals over time. The system samples real-time ADC data, buffers time-ordered samples, and renders voltage-vs-time waveforms on a 128×64 OLED display with adjustable time scaling.
## Overview
This project implements a compact digital oscilloscope using an ESP32 microcontroller.
The system samples analog voltage signals using the onboard ADC, buffers time-ordered samples,
and renders real-time waveforms on a 128×64 OLED display. An adjustable time-base control allows
users to scale the waveform horizontally, similar to professional oscilloscopes.
## Features
- Real-time ADC sampling and waveform visualization
- Adjustable time-base (time/div) control via potentiometer
- Internal PWM test signal for validation and debugging
- Buffered data acquisition mapped to display resolution
## Hardware
- ESP32 microcontroller
- 128×64 OLED display (SPI)
- Potentiometer (time-base control)
## Hardware Design
This project includes a custom ESP32-based PCB designed in KiCad to support
a mini digital oscilloscope application. The board integrates an SPI OLED
display, analog input circuitry, and onboard power distribution.

Key hardware features:
- 2-layer PCB designed in KiCad (schematic + layout)
- Solid bottom-layer ground plane with stitching vias
- ESP32 antenna keep-out region for reliable Wi-Fi operation
- SPI interface for OLED display
- Analog input sampled via ESP32 ADC
### RF & Grounding Considerations
The top-layer ground plane is intentionally split to maintain a copper-free
keep-out region beneath the ESP32 antenna. A continuous ground reference is
preserved using a solid bottom-layer ground plane and multiple ground stitching
vias to ensure low-impedance return paths.
## Software
- Language: C / C++
- Framework: Arduino (ESP32 core)
- Libraries: Adafruit_GFX, Adafruit_SH110X
## How It Works
1. The ESP32 samples analog input voltage using its onboard ADC.
2. Samples are stored in a fixed-length buffer corresponding to the OLED's horizontal resolution.
3. ADC values are mapped to screen coordinates.
4. Successive samples are connected to render a waveform.
5. A potentiometer dynamically adjusts sampling delay to control the time scale.
6. An internal PWM signal provides a known test waveform for validation.
## What I Learned
- Relationship between sampling rate and signal frequency
- Causes and effects of aliasing
- Real-time data visualization on embedded systems
- Debugging hardware and firmware interactions
## Future Improvements
- Rising-edge trigger detection
- Automatic voltage scaling
- External signal input selection
- Wireless waveform streaming via ESP32 Wi-Fi
