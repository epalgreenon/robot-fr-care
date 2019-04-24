//Αποφυγή εμποδίων με analogWrite
//Ορισμός μεταβλητών(variables)
//Σχετικά με τα μοτέρ:
//Motor A 
const int motorR1  = 9;  //ΔΕΞΙ ΜΠΡΟΣΤΑ
const int motorR2  = 10;//ΔΕΞΙ ΠΙΣΩ
//Motor B
const int motorL1  = 5; //ΑΡΙΣΤΕΡΟ ΜΠΡΟΣΤΑ
const int motorL2  = 6;//ΑΡΙΣΤΕΡΟ ΠΙΣΩ 
 
 //Σχετικά με τον αισθητήρα απόστασης:
 #include <Ultrasonic.h>
 //Ultrasonic       (Trig,Echo)
  Ultrasonic sensor (A0,A1);
  // μεταβλητές για να αποθηκεύεται η απόσταση που μετρά ο αισθητήρας απόστασης 
  int  distance=100;
  int leftDistance;
  int rightDistance;
  
  //Σχετικά με τον servo που χρησιμοποιούμε ως "λαιμό" του ρομπότ
 #include <Servo.h>  
 Servo myservo1;  // create servo object to control a servo                
 int pos1 =90;   // μεταβλητή για να αποθηκεύεται η θέση του  servo  

//Led
const int led = 12;

//Speaker
const int speaker = 13;


void setup(){
   //Ξεκινά η σειριακή επικοινωνία,Start serial communication
  Serial.begin(9600);
    //θέτω ως εξόδους τους παρακάτω ακροδέκτες(Set pins as outputs)
    pinMode(motorR1, OUTPUT);
    pinMode(motorR2, OUTPUT);
    pinMode(motorL1, OUTPUT);
    pinMode(motorL2, OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(speaker, OUTPUT);

  //Σχετικά με την αρχική θέση του servo1(positioning servo1)
  myservo1.attach(8);  // συνδέεται ο servo 1  με το pin 8 του arduino 
  myservo1.write(pos1);// ο servo 1 κοιτάζει μπροστά
  
  // Χωρίς ήχο αρχικά(no sound in the begining)
  noTone(speaker);
  
  //Διάρκεια αρχικοποίησης 1sec, time for the setup is 1sec
  delay(1000);
   }
   
void loop(){     
    distance = sensor.Ranging(CM);
    Serial.print("Objectforward found at: ");
    Serial.println(distance);
    delay(20);
    //If an object detected at 10cm, stop the robot and find a way out
    if (distance <= 20){
     stop();
     tone(speaker, 1000);
     digitalWrite(led,HIGH);
     delay(1000);
     noTone(speaker);
     digitalWrite(led,LOW);
     //Look left
     for (pos1 = 90; pos1 <= 160; pos1 += 1) { // goes from 0 degrees to 180 degrees
     myservo1.write(pos1);               // tell servo to go to position in variable 'pos'
     delay(15);                         // waits 15ms for the servo to reach the position
     }
     leftDistance = sensor.Ranging(CM);
     Serial.print("Object leftfound at: ");
     Serial.println(leftDistance);
     delay(20);
     
      //Now look right
      for (pos1 = 160; pos1 >= 20; pos1 -= 1) { // goes from 180 degrees to 0 degrees
      myservo1.write(pos1);               // tell servo to go to position in variable 'pos'
      delay(15);                         // waits 15ms for the servo to reach the position
        }
     rightDistance = sensor.Ranging(CM);
     Serial.print("Object right found at: ");
     Serial.println(rightDistance);
    delay(20);
     
     pos1 = 90; // look forward again
     myservo1.write(pos1);
     delay(20);
        
     //Finally compare left and right distances and make the best turn decision
     if (leftDistance > rightDistance){
     left();
     delay(350); // Change the time to make 90 deg. turn
        }
    else if (leftDistance < rightDistance){
    right();
   delay(350);
        }
   else{ //that means that two distances are equal
   backward();
   delay(1000);// Go back for 1 sec 
   left();   // and turn left
   delay(350);
        }
    }
    //All crear, move forward!
    else {
      forward();
    }
    }



//Movement functions

void forward(){
  analogWrite(motorR1, 150);
  analogWrite(motorR2, 0);
  analogWrite(motorL1, 150);
  analogWrite(motorL2, 0);
}

void backward(){
  analogWrite(motorR1, 0);
  analogWrite(motorR2, 150);
  analogWrite(motorL1, 0);
  analogWrite(motorL2, 150);
}

void right(){
  analogWrite(motorR1, 0);
  analogWrite(motorR2, 150);
  analogWrite(motorL1, 150);
  analogWrite(motorL2, 0);
  }

void left(){
  analogWrite(motorR1, 150);
  analogWrite(motorR2, 0);
  analogWrite(motorL1,0 );
  analogWrite(motorL2, 150);
  
}

void stop(){
  analogWrite(motorR1, 0);
  analogWrite(motorR2, 0);
  analogWrite(motorL1, 0);
  analogWrite(motorL2, 0);
  
  
}
