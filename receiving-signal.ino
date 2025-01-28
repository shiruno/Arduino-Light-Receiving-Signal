void setup() {
  pinMode(13, OUTPUT); // LED on pin 13
  Serial.begin(9600); // Start serial communication
}
void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read(); // Read the incoming byte
    if (command == '1') {
      digitalWrite(13, HIGH); // Turn LED on
    } else if (command == '0') {
      digitalWrite(13, LOW); // Turn LED off
    }
  }
}