
int triggerPin = 8;
int echoPin = 7;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  long dist = getDistInCm();

  Serial.println("the distance is" + String(dist) + " cm");

  delay(1000);
}

long getDistInCm() {
  long duration_in_ms, dist_in_cm;
  duration_in_ms = ultrasonicPingMs();
  //340 m/s => 0.034 cm/microsec
  dist_in_cm = (duration_in_ms / 2) * 0.034;
  return dist_in_cm;
}

long ultrasonicPingMs() {
  long duration_in_ms;
  // reset before new trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(5);
  // trigger sensor by setting pin high for 10ms
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  //reading the length incoming echo pulse
  duration_in_ms = pulseIn(echoPin, HIGH);
  return duration_in_ms;
}
