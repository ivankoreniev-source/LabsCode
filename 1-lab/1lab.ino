const int PIN_AND_OUT = 5;
const int LED_PINS[3] = {4, 3, 2};

int highCount = 0;
int activeLed = -1;

void setup() {
  pinMode(PIN_AND_OUT, INPUT);

  for (int i = 0; i < 3; i++) {
    pinMode(LED_PINS[i], OUTPUT);
    digitalWrite(LED_PINS[i], LOW);
  }
}

void loop() {
  if (digitalRead(PIN_AND_OUT) == HIGH) {
    highCount++;

    if (highCount >= 10) {
      highCount = 0;

      if (activeLed >= 0) {
        digitalWrite(LED_PINS[activeLed], LOW);
      }

      activeLed = (activeLed + 1) % 3;
      digitalWrite(LED_PINS[activeLed], HIGH);
    }
  }

  delay(1000);
}