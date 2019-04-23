v//L298D ΤΕΣΤ
//Motor A 
const int motorPin1  = 9;  //ΔΕΞΙ ΜΠΡΟΣΤΑ
const int motorPin2  = 10;//ΔΕΞΙ ΠΙΣΩ
//Motor B
const int motorPin3  = 5; //ΑΡΙΣΤΕΡΟ ΜΠΡΟΣΤΑ
const int motorPin4  = 6;//ΑΡΙΣΤΕΡΟ ΠΙΣΩ  


void setup(){
    //Set pins as outputs
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4
    //FORWARD
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    delay(1000);
    
    //BACKWARD
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);
    delay(1000);
    //LEFT
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);
    delay(1000); 
    //RIGHT
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    delay(1000); 
    
    //And this code will stop motors
   analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0); 
}
void loop(){
  
}
