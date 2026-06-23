// Ultrasonic Sensor Distance Measurement with LED and Buzzer Control

// Define pins
const int trigPin = 9;
const int echoPin = 10;
const int greenLED = 11;
const int redLED = 12;
const int buzzer = 13;

void setup() {
  // SYSTEM CHECK
  if (!systemArmed) {
    noTone(buzzer);
    digitalWrite(trigPin, LOW);
    digitalWrite(greenLED, LOW);
    return; // skip rest
  }

  // SYSTEM ON + run sensor
  long duration;
  float distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  duration = pulseIn(echo, HIGH);
  distance = duration * 0.0343 / 2;

  if (distance < 100) {
    tone(buzzer, 1000);
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, HIGH);
    delay(200);
  } else {
    noTone(buzzer);
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    delay(200);
  }

  delay(50);
}

void loop() {
  // Main loop - add additional sensor readings or logic here
}
