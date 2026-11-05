# Object Detection Alarm

An Arduino Uno proximity alarm. An HC-SR04 ultrasonic sensor measures the distance ahead; when an object is at or within 8 cm, the LED and active buzzer turn on. The distance is also printed to the Serial Monitor.

## Tools and components

- Arduino Uno (or compatible board)
- HC-SR04 ultrasonic distance sensor
- Active buzzer (5 V logic-compatible)
- LED and 220 Ω current-limiting resistor
- Breadboard and jumper wires
- USB cable and Arduino IDE 2.x (Arduino IDE 1.8.x also works)
- `Object_Detection_Alarm.ino` (Arduino C++)

No external libraries or dataset are required. This is a threshold-based hardware project; there is no machine-learning model or sample dataset.

## Wiring

See `circuit_diagram.png` for the supplied wiring illustration. Connections used by the sketch:

| Arduino | Component pin |
| --- | --- |
| D13 | HC-SR04 TRIG |
| D12 | HC-SR04 ECHO |
| D11 | Active buzzer positive / signal |
| D10 | LED anode through 220 Ω resistor |
| 5V | HC-SR04 VCC; buzzer supply if its rating permits |
| GND | HC-SR04 GND, buzzer negative, LED cathode |

The LED and resistor are in series between D10 and GND. Ensure the sensor, Arduino, and outputs share GND. The attached image is the reference circuit supplied with the project; check its wiring against the pin table before powering, as its drawn buzzer/LED connections may not exactly match these sketch pin assignments.

## Upload and use

1. Install and open Arduino IDE.
2. Connect the Uno with USB; select **Tools → Board → Arduino AVR Boards → Arduino Uno** and the matching **Tools → Port**.
3. Open `Object_Detection_Alarm.ino` (or select the folder sketch in Arduino IDE).
4. Click **Verify** to compile, then **Upload**.
5. Place an object in front of the sensor. At 8 cm or closer, the LED and buzzer activate; beyond 8 cm they turn off.
6. Open **Tools → Serial Monitor**, set it to **9600 baud**, and read the reported distance. If there is no valid echo, it reports `no echo` and leaves the alarm off.

## Adjusting the alarm

Change `alertDistanceCm` near the top of the sketch, then upload again. This measures distance only; it does not identify or classify objects. `pulseIn` times out after 30 ms to keep the loop responsive when no echo returns.

## Project files

- `Object_Detection_Alarm.ino` — complete Arduino sketch.
- `circuit_diagram.png` — supplied breadboard wiring reference.
- `project_poster.svg` — scalable one-page project poster; open in a browser or vector editor and print/export if desired.
