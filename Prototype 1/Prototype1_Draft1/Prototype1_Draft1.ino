/**
 * Programmable Robotic Arm - Prototype 1 - Draft 1
 * 
 * this is the first draft of the programmable robotic arm prototype 1. the main goal of
 * prototype 1 is to be able to make the basic movement fo a robotic arm and to be able to
 * repeat the positions so that in future projects the arm can hold circuit boards and hold them 
 * in specific positions. 
 * 
 * note: this code will follow closely with Ryan Chans programmable robotic arm. 
 * 
 * @author Antonio Jimenez
 * @version 1 (12/21/2020)
 */

 // import the servo library and define the servo objects

 #include <Servo.h>

 Servo servo1; // define the servo objects
 Servo servo2;
 Servo servo3;

 // define the LED's
 const int LED1 = 2;
 const int LED2 = 3;
 const int LED3 = 4;
 const int LED4 = 7;
 const int LED5 = 8;

 //define the buttons
 const int button1 = 12; // record button
 const int button2 = 13;

 // Define the button states and define the boolean
 int button1Presses = 0; 
 boolean button2Pressed = false;

 // Define the pins that the potentiometers will be attached to 
 const int pot1 = A0;
 const int pot2 = A1;
 const int pot3 = A2;

 // intialize the potentiometer variables that will soon be holding the
 // values the Arduino pins reads from such potentiometers.
 int pot1Val;
 int pot2Val;
 int pot3Val;

 // initialize variables that will hold the angle as an integer
 int pot1Angle;
 int pot2Angle;
 int pot3Angle;

 // make arrays for all three servos that will hold 5 positions 
 int servo1PosSaves [] = {1,1,1,1,1}; 
 int servo2PosSaves [] = {1,1,1,1,1};
 int servo3PosSaves [] = {1,1,1,1,1};

 void setup(){
    servo1.attach(5); // here we attach the servos to certain pins. 
    servo2.attach(6);
    servo3.attach(9); 

    pinMode(LED1, OUTPUT); // 5 LED's will give the status that the 
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(LED5, OUTPUT);
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);

    Serial.begin(9600);
 }

 void loop(){
     // read potentiometer values and store them...
     pot1Val = analogRead(pot1);
     pot1Angle = map(pot1Val, 0, 1023, 0, 179); 
     pot2Val = analogRead(pot2);
     pot2Angle = map(pot2Val, 0, 1023, 0, 179);
     pot3Val = analogRead(pot3);
     pot3Angle = map(pot3Val, 0, 1023, 0, 179);

     // use the write() function to make the servos move. 
     servo1.write(pot1Angle);
     servo2.write(pot2Angle);
     servo3.write(pot3Angle);

     if(digitalRead(button1) == HIGH){ // This will check how many times button1 is pressed and save the positions to an array depending on how many times it is pressed; switch/case works like a if statement
        button1Presses++;
        switch(button1Presses){
          case 1:
            servo1PosSaves[0] = pot1Angle;
            servo2PosSaves[0] = pot2Angle;
            servo3PosSaves[0] = pot3Angle;
            digitalWrite(LED1, HIGH);
            Serial.println("Pos 1 Saved");
            break;
          case 2:
            servo1PosSaves[1] = pot1Angle;
            servo2PosSaves[1] = pot2Angle;
            servo3PosSaves[1] = pot3Angle;
            digitalWrite(LED2, HIGH);
            Serial.println("Pos 2 Saved");
            break;
          case 3:
            servo1PosSaves[2] = pot1Angle;
            servo2PosSaves[2] = pot2Angle;
            servo3PosSaves[2] = pot3Angle;
            digitalWrite(LED3, HIGH);
            Serial.println("Pos 3 Saved");
            break;
          case 4:
            servo1PosSaves[3] = pot1Angle;
            servo2PosSaves[3] = pot2Angle;
            servo3PosSaves[3] = pot3Angle;
            digitalWrite(LED4, HIGH);
            Serial.println("Pos 4 Saved");
            break;
          case 5:
            servo1PosSaves[4] = pot1Angle;
            servo2PosSaves[4] = pot2Angle;
            servo3PosSaves[4] = pot3Angle;
            digitalWrite(LED5, HIGH);
            Serial.println("Pos 5 Saved");
            break;
        }
      }

      if(digitalRead(button2) == HIGH){ // Pretty self-explnatory here
        button2Pressed = true;   
      }
  
      if(button2Pressed){ // if the boolean button2Press is true, then the servos will run though all their saved positions
        for(int i = 0; i < 5; i++){
          servo1.write(servo1PosSaves[i]);
          servo2.write(servo2PosSaves[i]);
          servo3.write(servo3PosSaves[i]);
          Serial.println(" potentimeter Angles: ");
          Serial.println(servo1PosSaves[i]);
          Serial.println(servo2PosSaves[i]);
          Serial.println(servo3PosSaves[i]);
          delay(1050);
        }
      }
      delay(300);
     
 }







 
