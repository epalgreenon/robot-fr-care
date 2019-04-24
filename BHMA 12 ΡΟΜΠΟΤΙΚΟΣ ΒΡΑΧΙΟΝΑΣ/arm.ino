v#include <Servo.h> 
Servo gripper, forth_back, up_down,Base;

int realservo;

int pos1 = 0; //for gripper
int pos2 = 60;//for right
int pos3 = 160;//for left
int pos4=90;//for base
  

void setup()
{ //Setup Bluetooth serial connection to android
 // bluetooth.begin(9600);
  Serial.begin(9600);
  gripper.attach(9);
  forth_back.attach(10);
  up_down.attach(11);
  Base.attach(5);
    
   
  gripper.write(pos1);
  forth_back.write(pos2);//right servo
  up_down.write(pos3);//left servo
  Base.write(pos4);
  delay(100);  
    
  }

void loop()
{
  //Read from bluetooth and write to usb serial
 if(Serial.available() > 0) {
 realservo = Serial.read();
    
 //Serial.println(realservo); 
 //delay(10);
    
    if (realservo >=0 && realservo <=60){
    int pos1 = realservo;
    pos1 = map(pos1,0,60,0,100);
    gripper.write(pos1);
    //Serial.println("gripper ON");
    //Serial.println(pos1);
    delay(15);

    }
    
    if (realservo >=60 && realservo <=140){
      int pos2 = realservo;
      pos2 = map(pos2,60,140,20,160);
      forth_back.write(pos2);
      //Serial.println(" Rightservo  On");
      //Serial.println(pos2);
      delay(15);
      
    }
    
    if (realservo >=140 && realservo <=180){
      int pos3 = realservo;
      pos3 = map(pos3, 140,180,100,180);
      up_down.write(pos3);
      //Serial.println("Leftservo  On");
      //Serial.println(pos3);
      delay(15);
      
    }
    
    if (realservo >=180 && realservo <=250){
      int pos4 = realservo;
      pos4 = map(pos4, 180, 250,0,180);
      Base.write(pos4);
      //Serial.println("Base On");
      //Serial.println(pos4);
      delay(15);
      
    }
    
    
  }


}
