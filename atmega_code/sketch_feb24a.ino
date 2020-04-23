const int buttonOne = 65;
const int buttonTwo = 67;

void setup() {
  Serial.begin(9600);

  for(int i = 2; i <= 37; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(buttonOne, INPUT_PULLUP);
  pinMode(buttonTwo, INPUT_PULLUP);
}

void loop() {
  if (Serial.available()) {
    digitalWrite(37, HIGH);
    int inByte = Serial.read();
    
    if (inByte == 0xA1) {
      for(int i = 2; i <= 9; i++) {
        if ((i % 2) == 0) {
          digitalWrite(i, HIGH);
          delay(600);
          digitalWrite(i, LOW);
        }
      }
      for(int i = 2; i <= 9; i++) {
        if ((i % 2) != 0) {
          digitalWrite(i, HIGH);
          delay(600);
          digitalWrite(i, LOW);
        }
      }
    } else if (inByte == 0xB1) {
      digitalWrite(37, LOW);
    }
  }
}
