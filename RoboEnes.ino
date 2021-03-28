#include <SoftwareSerial.h>
SoftwareSerial mySerial(9, 10); // RX, TX
char data;

#define sol_motor_1 A2
#define sol_motor_2 A1
#define sag_motor_1 A3
#define sag_motor_2 A4
#define trig 2
#define echo 3
#define sol_motor_en 6
#define sag_motor_en 5
 
void setup() {
pinMode(A1,OUTPUT);   //Sol Motor 2
pinMode(A2,OUTPUT);   //Sol Motor 1
pinMode(A3,OUTPUT);   //Sağ Motor 1
pinMode(A4,OUTPUT);   //Sağ Motor 2
pinMode(5,OUTPUT);   //Sağ Motor EN
pinMode(6,OUTPUT);   //Sol Motor EN
pinMode(2,OUTPUT);   //TrigPin
pinMode(3,INPUT);   //EchoPin
pinMode(4,OUTPUT);  //Mesafe sönsörü 5V
pinMode(11,OUTPUT);  //Işık 5V
pinMode(5,OUTPUT);  //Işık 5V
pinMode(8,OUTPUT);  //Işık 5V
pinMode(12, OUTPUT); //Arka Işık 5V
pinMode(A5, OUTPUT); //Arka Işık 5V
pinMode(1, OUTPUT); //Arka Işık GND
pinMode(13, OUTPUT); //Arka Işık GND

analogWrite(5,170);
analogWrite(6,170);
digitalWrite(4,HIGH);
digitalWrite(1,LOW);
digitalWrite(13,LOW);
digitalWrite(8,LOW);

Serial.begin(9600);
mySerial.begin(9600);
}

void ileri(){
  if(!engel()){
    digitalWrite(sol_motor_1, LOW);
    digitalWrite(sol_motor_2, HIGH);
    digitalWrite(sag_motor_1, HIGH);
    digitalWrite(sag_motor_2, LOW);
  }
  else{
    dur();
  }
  
}

void geri(){


  digitalWrite(sol_motor_1, HIGH);
  digitalWrite(sol_motor_2, LOW);
  digitalWrite(sag_motor_1, LOW);
  digitalWrite(sag_motor_2, HIGH);

  
}

void sol(){
  digitalWrite(sol_motor_1, HIGH);
  digitalWrite(sol_motor_2, LOW);
  digitalWrite(sag_motor_1, HIGH);
  digitalWrite(sag_motor_2, LOW);
  
}


void sag(){
  
    digitalWrite(sol_motor_1, LOW);
  digitalWrite(sol_motor_2, HIGH);
  digitalWrite(sag_motor_1, LOW);
  digitalWrite(sag_motor_2, HIGH);
  
}

bool engel(){
  long duration, distance;
  digitalWrite(trig, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration/2) / 29.1;
  
  if(distance < 15){
    return true;
  }
  else{
    return false;
  }
}

void dur(){

  digitalWrite(sol_motor_1, LOW);
  digitalWrite(sol_motor_2, LOW);
  digitalWrite(sag_motor_1, LOW);
  digitalWrite(sag_motor_2, LOW);
  
}
 
void loop() {
  
if(mySerial.available()){
  data = mySerial.read();
  Serial.println(data);
}
 
if(data == 'F'){            
 ileri();
}
 
else if(data == 'B'){      
  geri();
}
 
else if(data == 'L'){      
  sag();
}
 
else if(data == 'R'){     
   sol();
}
else if(data == '1'){
    analogWrite(5,100);
    analogWrite(6,100);
}
else if(data == '2'){
    analogWrite(5,125);
    analogWrite(6,125);
}
else if(data == '3'){
    analogWrite(5,150);
    analogWrite(6,150);
}
else if(data == '4'){
    analogWrite(5,175);
    analogWrite(6,175);
}
else if(data == '5'){
    analogWrite(5,185);
    analogWrite(6,185);
}
else if(data == '6'){
    analogWrite(5,200);
    analogWrite(6,200);
}
else if(data == '7'){
    analogWrite(5,215);
    analogWrite(6,215);
}
else if(data == '8'){
    analogWrite(5,230);
    analogWrite(6,230);
}
else if(data == '9'){
    analogWrite(5,255);
    analogWrite(6,255);
}
else if(data == 'W'){
    digitalWrite(11, HIGH);
    digitalWrite(7, HIGH);
}
else if(data == 'w'){
    digitalWrite(11, LOW);
    digitalWrite(7, LOW);
}

else if(data == 'U'){
    digitalWrite(12, HIGH);
    digitalWrite(A5, HIGH);
}
else if(data == 'u'){
    digitalWrite(12, LOW);
    digitalWrite(A5, LOW);
}
else if (data == 'X'){
    digitalWrite(12, HIGH);
    digitalWrite(A5, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(7, HIGH);
}
else if (data == 'x'){
  digitalWrite(12, LOW);
    digitalWrite(A5, LOW);
    digitalWrite(11, LOW);
    digitalWrite(7, LOW);
}
else if(data == 'S'){      
  dur();
}

}
