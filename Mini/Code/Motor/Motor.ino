#define fw1Pin 2
#define fw2Pin 3
#define bk1Pin 4
#define bk2Pin 5
#define dirPin 10
#define trgPin 12
#define ecoPin 11 

long duration;
long distance;

void setup() {
  Serial.begin(115200);
  pinMode(fw1Pin, OUTPUT);
  pinMode(fw2Pin, OUTPUT);
  pinMode(bk1Pin, OUTPUT);
  pinMode(bk2Pin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(trgPin, OUTPUT);
  pinMode(ecoPin, INPUT);
}

void loop() {
  Serial.println("Starting engine...");
  delay(1000);
  while (true) {
    // -- Evita que os motores estejam a trabalhar quando liga os ultrasons
    // -- por tentar garantir alguma estabilidade elétrica 
    stop();
    // -- Ativa os ultrasons para detetar obstaculos 
    digitalWrite(trgPin, LOW); 
    delayMicroseconds(2);
    digitalWrite(trgPin, HIGH);
    delayMicroseconds(100);
    digitalWrite(trgPin, LOW);
    duration = pulseIn(ecoPin, HIGH);
    distance = (duration/2)/29.1;
    Serial.println(distance);
    if (distance < 30) {
      back();
    } else {
      forward();
      // -- Dá algum tempo ao motor para avançar
      delay(100);
    }
  }
}

void forward() {
  Serial.println("Forward");
  
  digitalWrite(bk1Pin, LOW);
  digitalWrite(bk2Pin, LOW);

  digitalWrite(fw1Pin, HIGH);
  digitalWrite(fw2Pin, HIGH);
}

void back() {
  Serial.println("Back");
  
  digitalWrite(fw1Pin, LOW);
  digitalWrite(fw2Pin, LOW);

  digitalWrite(bk1Pin, HIGH);
  digitalWrite(bk2Pin, HIGH);
  
  digitalWrite(dirPin, LOW);
  delay(1500);
  digitalWrite(dirPin, HIGH);
}

void stop() {
  Serial.println("Stop");
  
  digitalWrite(fw1Pin, LOW);
  digitalWrite(fw2Pin, LOW);

  digitalWrite(bk1Pin, LOW);
  digitalWrite(bk2Pin, LOW);
  
  digitalWrite(dirPin, HIGH);
}

