# INA228 Variable‑Load Testbench

Adjustable 100 Ω / 100 W resistive load, monitored by a TI INA228 precision power‑monitor IC and driven by a Raspberry Pi Pico V1. Output goes to  
* a 0.96 " I²C OLED (SSD1306) for stand‑alone viewing, and  
* a 115'200 baud USB‑CDC serial console for logging/automation.


---

## What it does

1. **Set the load** - Dial the wire‑wound rheostat (100 W, 100 Ω) to the desired resistance.  
2. **Measure in real time** - The Pico polls the INA228 and computes voltage, current and power.  
3. **Display + stream** - Instant read‑out on the OLED; identical data streamed over USB.  
4. **Power** - Runs off the USB port *or* a single LiFePO₄ cell via the Pico’s VSYS pin.

---

## Quick specs

| Item                     | Spec / Part            |
|--------------------------|------------------------|
| MCU board                | Raspberry Pi Pico (RP2040) |
| Shunt monitor            | TI INA228 (±85 V, 20‑bit) |
| Load                     | 100 Ω, 100 W wire‑wound rheostat |
| Display                  | 0.96 " I²C OLED, 128 × 64 |
| Supply options           | USB‑5 V *or* 1 × LiFePO₄ (protected) |
| Firmware build system    | PlatformIO + C++17 |
| Hardware CAD             | KiCad 9 |


---

## Repository layout

