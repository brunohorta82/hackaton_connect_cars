#define trigPin 12
#define echoPin 11
#define dirPin 10
#define MOTOR_FRONT1 2
#define MOTOR_FRONT2 3
#define MOTOR_BACK1 4
#define MOTOR_BACK2 5
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(MOTOR_FRONT1, OUTPUT);
  pinMode(MOTOR_FRONT2, OUTPUT);
  pinMode(MOTOR_BACK1, OUTPUT);
  pinMode(MOTOR_BACK2, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 30) {  
    Serial.println("MOTOR BACK"); 
    back();
  }else {
    Serial.println("MOTOR FRONT");
    front();    
  }
 Serial.print(distance);
 Serial.println(" cm");
 delay(10);
}

void front(){
  digitalWrite(MOTOR_BACK1,LOW);  
  digitalWrite(MOTOR_BACK2,LOW);  

  digitalWrite(MOTOR_FRONT1,HIGH);
  digitalWrite(MOTOR_FRONT2,HIGH);
}

void back(){
  digitalWrite(MOTOR_FRONT1,LOW);
  digitalWrite(MOTOR_FRONT2,LOW);

  digitalWrite(MOTOR_BACK1,HIGH);  
  digitalWrite(MOTOR_BACK2,HIGH);

  digitalWrite(dirPin, LOW);
  delay(500);
  digitalWrite(dirPin, HIGH);
}
