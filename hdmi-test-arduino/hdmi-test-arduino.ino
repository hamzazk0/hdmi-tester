int ledIndex = 22;

const int analogInputPins[] = {A0, A1, A2};//, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};
const int numAnalogInputs = sizeof(analogInputPins) / sizeof(analogInputPins[0]);

void setup() {
  // put your setup code here, to run once:
  // Initialize pins 22 to 41 as digital outputs
  for (int pin = 22; pin <= 41; pin++) {
    pinMode(pin, OUTPUT);
  }

  Serial.begin(115200);
  for (int pin = 0; pin < numAnalogInputs; pin++) {
    pinMode(analogInputPins[pin], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  switch (ledIndex) {
    case 22:
      digitalWrite(22, HIGH);
      digitalWrite(41, LOW);
      ledIndex++;
      break;
    case 41:
      digitalWrite(ledIndex, HIGH);
      digitalWrite(ledIndex-1, LOW);
      ledIndex = 22;
      break;
    default:
      digitalWrite(ledIndex, HIGH);
      digitalWrite(ledIndex-1, LOW);
      ledIndex++;
      break;
  }

  for (int pin = 0; pin < numAnalogInputs; pin++) {
    int value = analogRead(analogInputPins[pin]);
    Serial.print("Analog Input ");
    Serial.print(pin);
    Serial.print(": ");
    Serial.println(value);
    delay(10); // Optional delay for stability
  }
  delay(200);
}
