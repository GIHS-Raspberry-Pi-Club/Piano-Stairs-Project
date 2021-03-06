const int sound = 8;
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup() {
  pinMode(sound, OUTPUT);
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  Serial.begin(9600);  // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;  // Calculating the distance
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance); 
  if (distance < 35) {
    Serial.print("Dist > 35");
    tone(sound, 1000, 500);
  } else {
    noTone(sound);
  }
}
