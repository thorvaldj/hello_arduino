void setup() {
  Serial.begin(9600);
}

void loop() {

  String input = readSerial();

  if (input == "hello arduino") {
    Serial.println("hello user");
  }

  delay(1000);
}


String readSerial() {
  String serial_in = "";

  if (Serial.available() > 0) {
    serial_in = Serial.readStringUntil('\\');
  }
  return serial_in;
}
