# 8051-Based Gas Leakage Detection System

An educational gas-detection prototype built around the AT89C51 (8051) microcontroller and an MQ-6 gas sensor module.

## Project overview

The circuit is designed to use the gas sensor's digital output as an input to the AT89C51 and drive an indicator LED and buzzer through the output circuitry.

## Hardware and tools

- Microcontroller: AT89C51 (8051)
- Gas sensor: MQ-6 module
- Firmware language: Embedded C
- Firmware IDE: Keil µVision
- Schematic and PCB design: EasyEDA
- Circuit simulation: Proteus

## Firmware files

- `firmware/gas.c` — reconstructed Embedded C source. It has not yet been compiled or hardware-verified in this repository.
- `firmware/Gas_Detection_ACTIVE_LOW.hex` — supplied compiled HEX file.

The reconstructed source is intended to reflect the observed active-LOW input behavior. It should be compiled in Keil and checked against the actual circuit before being treated as a verified replacement for the original firmware.

## Hardware design files and photos

The `hardware/` folder is intended for EasyEDA schematic/PCB exports and Proteus project files. The `images/` folder contains project reference photos.

## Pin information from the schematic

- Sensor digital input: P3.2 (physical pin 12)
- LED output: P2.0 (physical pin 21)
- Buzzer transistor-driver control: P2.1 (physical pin 22)

Verify these connections against the assembled board before use.

## Safety note

This is an educational prototype, not a certified gas safety device. Do not use it as a replacement for a certified gas detector or life-safety system.
