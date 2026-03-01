// Button and LED pins
const int button = 2;
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
const int led4 = 6;
const int led5 = 7;

// RGB LED pins
const int rgbRed = 11;
const int rgbGreen = 9;
const int rgbBlue = 10;

// LDR pin
const int ldrPin = A0;

// Variables
int buttonState = 0;
int buttonCheck = 0;
int lightMode = 0;
int ldrValue = 0;

// Student number
const int studentNumber = 95260;
const int rgbValue = 159;

// --- Timing Variables ---
unsigned long previousMillis = 0;
int step = 0; // Keeps track of which "frame" of the animation we are in

void setup() {
  pinMode(button, INPUT); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(rgbRed, OUTPUT);
  pinMode(rgbGreen, OUTPUT);
  pinMode(rgbBlue, OUTPUT);
  Serial.begin(9600);
}

// Helper to clear LEDs quickly
void allOff() {
  digitalWrite(led1, LOW); digitalWrite(led2, LOW); digitalWrite(led3, LOW);
  digitalWrite(led4, LOW); digitalWrite(led5, LOW);
  analogWrite(rgbRed, 0); analogWrite(rgbGreen, 0); analogWrite(rgbBlue, 0);
}

void loop() {
  ldrValue = analogRead(ldrPin);
  buttonState = digitalRead(button);
  unsigned long currentMillis = millis();

  // Button logic (Now works instantly!)
  if (buttonState != buttonCheck) {
    if (buttonState == HIGH) {
      lightMode++; 
      if (lightMode == 8) lightMode = 0; 
      step = 0; // Reset animation step
      allOff();
      Serial.print("Lightmode = "); Serial.println(lightMode);
      delay(50); // Small debounce is fine here
    }
  }
  buttonCheck = buttonState;

  if (ldrValue < 250) {
    
    // Mode 0: Off
    if (lightMode == 0) {
      allOff();
    }
    
    // Mode 1: On
    else if (lightMode == 1) {
      digitalWrite(led1, HIGH); digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH); digitalWrite(led4, HIGH); digitalWrite(led5, HIGH);
    }

    // Mode 2: Left and Back
    else if (lightMode == 2) {
      if (currentMillis - previousMillis >= 200) {
        previousMillis = currentMillis;
        allOff();
        step++;
        if (step > 5) step = 0;
        if (step == 1) digitalWrite(led1, HIGH);
        if (step == 2) digitalWrite(led2, HIGH);
        if (step == 3) digitalWrite(led3, HIGH);
        if (step == 4) digitalWrite(led4, HIGH);
        if (step == 5) digitalWrite(led5, HIGH);
      }
    }

    // Mode 3: Blinking
    else if (lightMode == 3) {
      if (currentMillis - previousMillis >= 350) {
        previousMillis = currentMillis;
        step = !step; // Toggle between 0 and 1
        int val = step ? HIGH : LOW;
        digitalWrite(led1, val); digitalWrite(led2, val); digitalWrite(led3, val);
        digitalWrite(led4, val); digitalWrite(led5, val);
      }
    }

    // Mode 4: Left to Right (Knight Rider style)
    else if (lightMode == 4) {
      if (currentMillis - previousMillis >= 200) {
        previousMillis = currentMillis;
        allOff();
        step++;
        if (step > 7) step = 0;
        if (step == 0 || step == 0) digitalWrite(led1, HIGH);
        if (step == 1 || step == 7) digitalWrite(led2, HIGH);
        if (step == 2 || step == 6) digitalWrite(led3, HIGH);
        if (step == 3 || step == 5) digitalWrite(led4, HIGH);
        if (step == 4) digitalWrite(led5, HIGH);
      }
    }

    // Mode 5: Alternating
    else if (lightMode == 5) {
      if (currentMillis - previousMillis >= 200) {
        previousMillis = currentMillis;
        step = !step;
        allOff();
        if (step) {
          digitalWrite(led1, HIGH); digitalWrite(led3, HIGH); digitalWrite(led5, HIGH);
        } else {
          digitalWrite(led2, HIGH); digitalWrite(led4, HIGH);
        }
      }
    }

    // Mode 6: Build Up, Build Down
    else if (lightMode == 6) {
      if (currentMillis - previousMillis >= 200) {
        previousMillis = currentMillis;
        step++;
        if (step > 10) step = 0;
        digitalWrite(led1, step >= 1 && step <= 9 ? HIGH : LOW);
        digitalWrite(led2, step >= 2 && step <= 8 ? HIGH : LOW);
        digitalWrite(led3, step >= 3 && step <= 7 ? HIGH : LOW);
        digitalWrite(led4, step >= 4 && step <= 6 ? HIGH : LOW);
        digitalWrite(led5, step == 5 ? HIGH : LOW);
      }
    }

    // Mode 7: RGB Student Number Mode
    else if (lightMode == 7) {
      allOff();
      analogWrite(rgbRed, rgbValue);
      analogWrite(rgbGreen, rgbValue);
      analogWrite(rgbBlue, rgbValue);
    }
  } 
  else {
    allOff();
  }
}
