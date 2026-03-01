# Bike-Lamp
An interactive Arduino project featuring 8 distinct lighting modes, an RGB LED status indicator, and an LDR (Light Dependent Resistor) for automatic darkness-sensing.

🚀 Key Feature: Non-Blocking Code
Unlike standard beginner projects that use delay(), this project is built using millis() for timing. This allows the Arduino to "multitask," ensuring that button presses are detected instantly even during complex LED animations.

🛠 Hardware Components
Arduino Uno (or compatible board)

5x Red LEDs (connected to Pins 3, 4, 5, 6, 7)

1x RGB LED (Pins 9, 10, 11)

1x LDR (Photoresistor) (Analog Pin A0)

1x Push Button (Digital Pin 2)

Resistors: 220Ω for LEDs and 10kΩ for the LDR/Button pull-down circuits.

🕹 Lighting Modes
The project cycles through 8 modes with each button press, but only if the environment is dark (LDR < 250):

Mode 0: System Off

Mode 1: All LEDs Static On

Mode 2: Sequential Chase (Left to Right)

Mode 3: All LEDs Blinking

Mode 4: "Knight Rider" / Cylon Back-and-Forth

Mode 5: Alternating Pattern (Odds vs. Evens)

Mode 6: Build Up / Build Down (Stacking Effect)

Mode 7: RGB Student ID Mode (Displays a custom color based on ID: 95260)

🔌 Circuit Diagram
To replicate this project, ensure your wiring matches the following configuration:

Button: Wired with a 10kΩ pull-down resistor to Pin 2.

LDR: Wired in a voltage divider circuit with a 10kΩ resistor to A0.

RGB LED: Common Cathode (longest leg) must be connected to Ground.

Power: Bridge the top and bottom power rails of the breadboard to ensure all components receive 5V/GND.

<img width="1031" height="780" alt="Screenshot 2026-03-01 165501" src="https://github.com/user-attachments/assets/bd9648af-133b-4481-9c8c-a72157d931da" />


💻 Installation
Clone this repository.

Open Project_Code.ino in the Arduino IDE.

Connect your Arduino Uno.

Select the correct Port and Board, then click Upload.
