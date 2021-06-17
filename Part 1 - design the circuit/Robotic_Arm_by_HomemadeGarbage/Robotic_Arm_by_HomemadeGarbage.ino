/**
 * Robotic Arm with Controller by HomeMadeGarbage 
 * 
 * In this project the 
 */

 #include <Servo.h>

Servo myservo1, myservo2, myservo3;

float th1=90.0,th2=90.0,th3=90.0;
float val1, val2, val3;

void setup() {
    Serial.begin(9600);
    myservo1.attach(9, 500, 2420);  //MG995
    myservo2.attach(10, 820, 2140); //DS3115
    myservo3.attach(11, 820, 2140); //DS3115
    set_servo();
}

void loop() {
    val1 = analogRead(A1);
    val2 = analogRead(A2);
    val3 = analogRead(A3);

    th1 = map(val1, 170.0, 880.0, 0.0, 180.0);
    if(th1 >= 180.0){
        th1 = 180.0;
    }else if(th1 <= 0.0){
        th1 = 0.0;
    }

    th2 = map(val2, 150.0, 860.0, 0.0, 180.0);
    if(th2 >= 180.0){
        th2 = 180.0;
    }else if(th2 <= 0.0){
        th2 = 0.0;
    }

    th3 = map(val3, 860.0, 160.0, 0.0, 180.0);
    if(th3 >= 180.0){
        th3 = 180.0;
    }else if(th3 <= 45.0){
        th3 = 45.0;
    }

    set_servo();
}

void set_servo(){
    myservo1.write(th1);
    myservo2.write(th2);
    myservo3.write(th3);
}
