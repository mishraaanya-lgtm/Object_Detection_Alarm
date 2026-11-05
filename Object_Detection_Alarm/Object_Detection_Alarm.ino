/* Object Detection Alarm
 * Arduino Uno + HC-SR04 + active buzzer + LED
 */
const byte trigPin = 13;
const byte echoPin = 12;
const byte buzzerPin = 11;
const byte ledPin = 10;
const int alertDistanceCm = 8;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Timeout avoids waiting indefinitely when no echo is received.
  unsigned long duration = pulseIn(echoPin, HIGH, 30000UL);
  if (duration == 0) {
    Serial.println("Distance: no echo");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
    delay(60);
    return;
  }

  float distanceCm = duration * 0.0343f / 2.0f;
  bool detected = distanceCm <= alertDistanceCm;
  digitalWrite(buzzerPin, detected ? HIGH : LOW);
  digitalWrite(ledPin, detected ? HIGH : LOW);

  Serial.print("Distance: ");
  Serial.print(distanceCm, 1);
  Serial.println(" cm");
  delay(60);
}
