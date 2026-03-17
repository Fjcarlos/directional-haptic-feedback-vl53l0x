float distance2;
float distance1;
void setup(){
 Serial.begin(9600);
 pinMode(2, OUTPUT);//motor
 pinMode(3, OUTPUT);//buzzer
 pinMode(5,OUTPUT);
 pinMode(10,OUTPUT);
}
void loop()
{
  ultrasonic1();
  Serial.println(distance1);
  while(distance1<5){
    ultrasonic1();
    ultrasonic2();
    Serial.println(distance2);
    if(distance2<4){
    while(distance2<4){
    ultrasonic2();
    Serial.println(distance2);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    delay(1000);
     }
    }else{
      digitalWrite(3,LOW);
      digitalWrite(2, HIGH);
    }
  }
  digitalWrite(3,LOW);
  digitalWrite(2,LOW);
}
void ultrasonic1(){
  digitalWrite(10, LOW);
  delayMicroseconds(5);
  digitalWrite(10, HIGH);
  delayMicroseconds(10);
  digitalWrite(10, LOW);
  distance1 = pulseIn(11, HIGH);
  distance1 = distance1*0.0176;
  delay(50);
}
void ultrasonic2(){
  digitalWrite(5, LOW);
  delayMicroseconds(5);
  digitalWrite(5, HIGH);
  delayMicroseconds(10);
  digitalWrite(5, LOW);
  distance2 = pulseIn(6, HIGH);
  distance2 = distance2*0.0176;
  delay(50);
}
