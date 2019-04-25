//Τελικό με τον κοκκινο βραχιονα χωρίς βάση
#include <Ultrasonic.h>
//Ultrasonic       (Trig,Echo)
  Ultrasonic sensor (A0,A1);
  int  distance=100;
  
 int state;
 char mode='m';
 int i=0;
 int j=0;

//L298 pins 
  const int motorR1 = 3; //right forthward
  const int motorR2 = 4; //right backward
  const int motorL1= 7;//left forthward
  const int motorL2= 8; //left backward

#include <Servo.h>
//Για τον servo λαιμό
Servo neck;
int pos;
int leftDistance;
int rightDistance;
//Led
const int led = 12;
//Speaker
const int speaker = 13;

//Για τον κόκκινο βραχίονα 
Servo gripper, forth_back, up_down;//Δαγκάνα, δεξιός, αριστερός servo


int pos1 = 0; //for gripper
int pos2 = 60;//for right
int pos3 = 160;//for left
void setup(){
    Serial.begin(9600);   
    // Set pins as outputs, inputs:
    pinMode(motorR1, OUTPUT);
    pinMode(motorR2, OUTPUT);
    pinMode(motorL1, OUTPUT);
    pinMode(motorL2, OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(speaker,OUTPUT);
    
   noTone(speaker);
   
   neck.attach(9);
   gripper.attach(6);
   forth_back.attach(10);
   up_down.attach(11); 
   gripper.write(pos1);
   forth_back.write(pos2);
   up_down.write(pos3);
   neck.write(90);
   delay(5000);
  }   
  void loop(){
  if(Serial.available() > 0){     
  state = Serial.read();
  if(state==1){ mode='a';}
  if(state==2){mode='m';}
  stop();}  
  //***********************************************************MANUAL ΛΕΙΤΟΥΡΓΙΑ******************************************************
  if( mode=='m'){
  // If the "state" is '3', robot will go forward
     if (state == 3) {
       forward();}
       
  // If the "state" is '4', robot will go backward
   else if (state == 4) {
         backward();}
       
   // If the "state" is '5', robot will turn left
   else if (state == 5) {  
            left();}       
       
   // If the "state" is '6', robot will turn right
   else if (state == 6) {  
         right();}
       
  // If the "state" is 'S', robot will stop
    else if (state == 7) {  
      stop();}       
       
       
  if (state >=10 && state <=80){
    int pos1 = state;
    pos1 = map(pos1,10,80,0,100);
    gripper.write(pos1);
    //Serial.println("gripper ON");
    //Serial.println(pos1);
    delay(15); }
    
    if (state >=80 && state <=180){
      int pos2 = state;
      pos2 = map(pos2,80,180,20,160);
      forth_back.write(pos2);
      Serial.println(" Rightservo  On");
      Serial.println(pos2);
      delay(15);
          }
    
    if (state >=180 && state <=250){
      int pos3 = state;
      pos3 = map(pos3, 180,250,100,180);
      up_down.write(pos3);
      Serial.println("Leftservo  On");
      Serial.println(pos3);
      delay(15);
          }
    
  //If state is equal with letter '8', turn leds on or of off
    else if (state == 8) {
      if (i==0){  
         digitalWrite(led, HIGH); 
         i=1;}
      else if (i==1){
         digitalWrite(led, LOW); 
         i=0;}
      state='n';}
  
  //If state is equal with letter '9', play (or stop) speaker sound
    else if (state == 9){
      if (j==0){  
         tone(speaker, 1000);//Speaker on 
         j=1;}
      else if (j==1){
         noTone(speaker);    //Speaker off 
         j=0; }
      state='n'; }       
    }
         //***********************************************************ΑΥΤΟ ΛΕΙΤΟΥΡΓΙΑ******************************************************
     else if(mode=='a'){
    distance=sensor .Ranging(CM);  
    Serial.print("Distance ");
    Serial.println(distance);
    delay(10);
    if(distance>=20){   
       forward();
    }
    if(distance<20){
    
  //If an object detected at 20cm, stop the robot and find a way out
  stop();
  tone(speaker,500);
  delay(1000);
  noTone(speaker);
  //Now look right
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 90 degrees to 0 degrees
        neck.write(pos);               // tell servo to go to position in variable 'pos'
        delay(5);                         // waits 5ms for the servo to reach the position
      }
      //Read new distance from the right side
     rightDistance = sensor.Ranging(CM);
      delay(10);
      
      //Now look left
      for (pos =0; pos <= 180; pos+= 1) { // goes from 0 degrees to 0 degrees 180 
        neck.write(pos);               // tell servo to go to position in variable 'pos'
        delay(5);                         // waits 5ms for the servo to reach the position
      }
      //Read new distance from the left side
      leftDistance = sensor.Ranging(CM);
      delay(10);
      pos = 90; // look forward again
      neck.write(pos);
      
      //Finally compare left and right distances and make the best turn decision
      if (leftDistance > rightDistance){
       left();
       delay(150); // Change the time to make 90 deg. turn
      }
      else if (leftDistance < rightDistance){
        
        right();
       delay(150);
      }
      else{ //that means that two distances are equal
        
        //back for 0.5sec 
        
  digitalWrite(led,HIGH); // turn the led on
  backward();
  delay(500);      
  left();   // and turn left
 delay(150);
      }
      
  }
 
        }
    }

//Movement functions

void forward(){
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
}

void backward(){
 digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
}

void right(){
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
  }

void left(){
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1,LOW );
  digitalWrite(motorL2, HIGH);
  
}

void stop(){
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, LOW);
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, LOW);
  
  
}


    
        
       
         
