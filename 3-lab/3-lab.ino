int PullReset = 2;      
int TriggerButton = 3;   

int TriggerPin = 5;     
int TriggerPinNotQ = 4;  

int LedForbidden = 13;   

void setup() {
  pinMode(PullReset, INPUT);      
  pinMode(TriggerButton, OUTPUT);
  digitalWrite(TriggerButton, LOW);
  
  pinMode(TriggerPin, INPUT);
  pinMode(TriggerPinNotQ, INPUT);

  pinMode(LedForbidden, OUTPUT);
  digitalWrite(LedForbidden, LOW);

  Serial.begin(9600);
}

void loop() {
  int resetBtn = digitalRead(PullReset);

  if (resetBtn == HIGH) {
    digitalWrite(TriggerButton, HIGH);
  } else {
    digitalWrite(TriggerButton, LOW);
  }

  int qState = digitalRead(TriggerPin);
  int notQState = digitalRead(TriggerPinNotQ);

  int forbidden = 0;

  if (qState == LOW && notQState == LOW) {
    forbidden = 1;
    digitalWrite(LedForbidden, HIGH);
  } else {
    forbidden = 0;
    digitalWrite(LedForbidden, LOW);
  }
  Serial.print("Q:");
  Serial.print(qState);
  Serial.print(" notQ:");
  Serial.print(notQState);
  Serial.print(" Forbidden:");
  Serial.println(forbidden);

  delay(25);
}
