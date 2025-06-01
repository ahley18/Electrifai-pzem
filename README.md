ESP8266 + PZEM-004T v3.0 Power Monitor
======================================

A simple project to interface the PZEM-004T v3.0 energy monitoring module with an ESP8266 (e.g., NodeMCU).
Reads voltage, current, power, energy, frequency, and power factor, and prints results to the Serial Monitor.

------------------------------------------------------------
📦 REQUIREMENTS
------------------------------------------------------------
- ESP8266 board (NodeMCU, Wemos D1 Mini, etc.)
- PZEM-004T v3.0 module
- Arduino IDE
- PZEM004Tv30 library (by Oleksii Taran)
- Dupont wires

------------------------------------------------------------
🔌 WIRING
------------------------------------------------------------
PZEM-004T v3.0     →    ESP8266 (e.g., NodeMCU)
-----------------------------------------------
TX                 →    D1 (GPIO 5)
RX                 →    D2 (GPIO 4)
VCC (5V)           →    5V (external)
GND                →    GND

⚠️ NOTE: Use level shifter if needed; ESP8266 is 3.3V logic.

------------------------------------------------------------
📦 LIBRARY INSTALLATION
------------------------------------------------------------
In Arduino IDE:
> Tools → Manage Libraries → Search "PZEM004Tv30" → Install

Or using CLI:
> arduino-cli lib install "PZEM004Tv30"

------------------------------------------------------------
💻 USAGE
------------------------------------------------------------
1. Open `Arduino IDE` or `arduino-cli`.
2. Select your ESP8266 board.
3. Upload the provided sketch.
4. Open Serial Monitor (baud: 74880).
5. Observe real-time electrical measurements.

------------------------------------------------------------
📄 CODE BEHAVIOR
------------------------------------------------------------
- Initializes PZEM on D1 (RX) and D2 (TX).
- Reads sensor values every 2 seconds.
- Checks for `NaN` (invalid) readings.
- Prints values in human-readable format.

------------------------------------------------------------
🔁 LOOP OUTPUT EXAMPLE
------------------------------------------------------------
Custom Address: 0x12345678
Voltage: 229.1V
Current: 0.15A
Power: 34.3W
Energy: 0.012kWh
Frequency: 60.0Hz
PF: 0.98

------------------------------------------------------------
🛠 DEBUGGING TIPS
------------------------------------------------------------
- Check wiring: TX ↔ RX must be cross-connected.
- Make sure the sensor is powered with 5V.
- Confirm the module is PZEM-004T v3.0 (v3.0 only!).
- Use external power source if needed.
- Try different baud rates if garbage appears on Serial Monitor.

------------------------------------------------------------
📜 LICENSE
------------------------------------------------------------
This project is released under the MIT License.

------------------------------------------------------------
🔗 REFERENCES
------------------------------------------------------------
- PZEM004Tv30 GitHub: https://github.com/olehs/PZEM004T-v30
