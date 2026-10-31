const int PULL_RESET_PIN = 2;
const int TRIGGER_BUTTON_PIN = 3;
const int TRIGGER_NOT_Q_PIN = 4;
const int TRIGGER_Q_PIN = 5;
const int LED_FORBIDDEN_PIN = 13;

const int SERIAL_RATE = 9600;
const int LOOP_DELAY = 25;

void initPins()
{
  pinMode(PULL_RESET_PIN, INPUT);
  pinMode(TRIGGER_BUTTON_PIN, OUTPUT);
  digitalWrite(TRIGGER_BUTTON_PIN, LOW);

  pinMode(TRIGGER_Q_PIN, INPUT);
  pinMode(TRIGGER_NOT_Q_PIN, INPUT);

  pinMode(LED_FORBIDDEN_PIN, OUTPUT);
  digitalWrite(LED_FORBIDDEN_PIN, LOW);
}

void setup()
{
  initPins();
  Serial.begin(SERIAL_RATE);
}

void updateTriggerButton()
{
  int resetBtn = digitalRead(PULL_RESET_PIN);
  digitalWrite(TRIGGER_BUTTON_PIN, resetBtn == HIGH ? HIGH : LOW);
}

int checkForbiddenState(int qState, int notQState)
{
  bool isForbidden = (qState == LOW && notQState == LOW);
  digitalWrite(LED_FORBIDDEN_PIN, isForbidden ? HIGH : LOW);
  return isForbidden ? 1 : 0;
}

void printTriggerStatus(int qState, int notQState, int forbidden)
{
  Serial.print("Q:");
  Serial.print(qState);
  Serial.print(" notQ:");
  Serial.print(notQState);
  Serial.print(" Forbidden:");
  Serial.println(forbidden);
}

void loop()
{
  updateTriggerButton();

  int qState = digitalRead(TRIGGER_Q_PIN);
  int notQState = digitalRead(TRIGGER_NOT_Q_PIN);
  int forbidden = checkForbiddenState(qState, notQState);

  printTriggerStatus(qState, notQState, forbidden);
  delay(LOOP_DELAY);
}
