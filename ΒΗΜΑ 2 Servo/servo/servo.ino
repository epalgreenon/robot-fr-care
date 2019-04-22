#include <Servo.h>  
Servo myservo;  // create servo object to control a servo                
int pos ;   // μεταβλητή για να αποθηκεύεται η θέση του  servo  
void setup() { 
  myservo.attach(8);  // συνδέεται ο servo  με το pin 8 του arduino 
  myservo.write(90);// ο servo κοιτάζει μπροστά
  //για να στρίψει αριστερά
  for(pos = 90; pos <= 180; pos += 1) // η μεταβλητή pos μεταβάλλεται από  0 έως 180 με βήμα 1 
  {                                  
myservo.write(pos);  //ο servo τοποθετείται στη θέση της μεταβλητής  'pos' 
    delay(15);    // περιμένει 15ms ο servo για να αλλάξει θέση 
  } 
  //για να στρίψει δεξιά
  for(pos = 180; pos>=0; pos-=1)     // η μεταβλητή pos μεταβάλλεται από  180 έως 0 με βήμα 1  
  {                                
    myservo.write(pos); // ο servo τοποθετείται στη θέση της μεταβλητής  'pos' 
 delay(15); // περιμένει 15ms ο servo για να αλλάξει θέση 
}
// επανέρχεται στην αρχική του θέση
myservo.write(90);
} 
  
 
void loop() 
{ 
}
