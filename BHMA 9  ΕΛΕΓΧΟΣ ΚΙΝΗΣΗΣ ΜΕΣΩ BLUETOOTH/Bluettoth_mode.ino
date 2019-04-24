//Ορισμός μεταβλητών(variables)
//Σχετικά με τα μοτέρ:
//Motor A 
const int motorR1  = 9;  //ΔΕΞΙ ΜΠΡΟΣΤΑ
const int motorR2  = 10;//ΔΕΞΙ ΠΙΣΩ
//Motor B
const int motorL1  = 5; //ΑΡΙΣΤΕΡΟ ΜΠΡΟΣΤΑ
const int motorL2  = 6;//ΑΡΙΣΤΕΡΟ ΠΙΣΩ 
 

//Led
const int led = 12;

//Speaker
const int speaker = 13;

int i=0;
int j=0;

//Μεταβλητές για το bluetooth
int state; 

char mode='m';

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

    
  // Χωρίς ήχο αρχικά(no sound in the begining)
  noTone(speaker);
  
  //Διάρκεια αρχικοποίησης 1sec, time for the setup is 1sec
  delay(1000);
   }
   
void loop(){
 //αν η σειριακή επικοινωνία είναι δυνατή 
if (Serial.available() > 0) {
 // read the incoming byte:
 state = Serial.read();
 if (state == 'A'){mode = 'a'; }
 if (state == 'M'){mode = 'm'; }
    
    //Bluetooth mode
    if (mode == 'm'){
    
    if (state=='F'){
      forward();
    }
    else if (state=='B'){
      backward();
    }
    else if (state=='R'){
      right();
    }
    else if (state=='L'){
      left();
    }
    else if (state=='S'){
     stop();
    }
    //If state is equal with letter 'W', turn leds on or of off
    else if (state == 'W') {
      if (i==0){  
         digitalWrite(led, HIGH); 
         i=1;
      }
      else {
         digitalWrite(led, LOW); 
         i=0;
      }
      state='n';
  }
     //If state is equal with letter 'V', play (or stop) horn sound
    else if (state == 'V'){
      if (j==0){  
         tone(speaker, 1000);//Speaker on 
         j=1;
      }
      else {
         noTone(speaker);    //Speaker off 
         j=0;
      }
      state='n'; }
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
