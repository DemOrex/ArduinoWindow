
//// прототип работаем с  L293D Motor Shield на четыре матора 

#include <AFMotor.h>     // подключаем библиотеку для шилда
#include <EEPROM.h>


const int addresFirstRun=1;
const int firstRun=100;
const int firstSpeedMotor=200;

const int adressM1Up=2;
const int adressM2Up=3;
const int adressM3Up=4;

 int speedM150=100;
 int speedM160=120;
 int speedM170=140;
 int speedM180=160;
 int speedM190=180;
 

AF_DCMotor motor1(1); // подключаем мотор к клеммникам M1
AF_DCMotor motor2(2); // подключаем мотор к клеммникам M2
AF_DCMotor motor3(3); // подключаем мотор к клеммникам M3
//AF_DCMotor motor4(4);
 
// Константы программы

const   int button_A0_pin =A0;// первый мотор 
const   int button_A1_pin =A1;// второй мотор 
const   int button_A2_pin =A2;// третий мотор 


const   int button_A5_pin =A5;// концевики первого мотора
const   int button_A4_pin =A4;// концевики второго мотора
const   int button_A3_pin =A3;// концевики третьего мотора

   
// переменные
char incomingbyte;
int valueA5,valueA4,valueA3,valueA2,valueA1,valueA0;
//int timeM1=0;
// Глобальные переменные

bool motor1Up=true;// при сработке концевика блокируем подьём первого мотора
bool motor1Down=true;// при сработке концевика блокируем спуск первого мотора и т.д
bool motor2Up=true;
bool motor2Down=true;
bool motor3Up=true;
bool motor3Down=true;


 
bool motor1UpBlu=false;// лог переменная для повторного нажатия кнопки
bool motor1DownBlu=false;
bool motor2UpBlu=false;
bool motor2DownBlu=false;
bool motor3UpBlu=false;
bool motor3DownBlu=false;


void setup() {
  Serial.begin(9600); 
 
 
  pinMode(button_A0_pin, INPUT);
  pinMode(button_A1_pin, INPUT);
  pinMode(button_A2_pin, INPUT);
  pinMode(button_A3_pin, INPUT);
  pinMode(button_A4_pin, INPUT);
  pinMode(button_A5_pin, INPUT);
  
 
  
  motor1.setSpeed(100); // задаем максимальную скорость мотора 1
  motor1.run(RELEASE);   // останавливаем мотор 1
  motor2.setSpeed(100); // задаем максимальную скорость мотора 2
  motor2.run(RELEASE);   // останавливаем мотор 2
  motor3.setSpeed(100); // задаем максимальную скорость мотора 3
  motor3.run(RELEASE);   // останавливаем мотор 3


// первый запуск

  if(EEPROM.read(addresFirstRun)==255){
       EEPROM.update(addresFirstRun,firstSpeedMotor);
    // Serial.println(EEPROM.read(addresFirstRun));
    EEPROM.update(adressM1Up,firstSpeedMotor);
    EEPROM.update(adressM2Up,firstSpeedMotor);
    EEPROM.update(adressM3Up,firstSpeedMotor);
    //Serial.println(EEPROM.read(adressM1Up));
  }
   
}



void loop() {

if(Serial.available() > 0) // есть ли что-то в буфере
   {
    
     incomingbyte = Serial.read(); // чтение символа
       Serial.println(incomingbyte);   
     switch (incomingbyte)
       {  
         case 'A': 
         motor1UpBlu=!motor1UpBlu;
         if(motor1UpBlu ){delayM1Up(EEPROM.read(adressM1Up));}else{motor1.run(RELEASE);}
         break;

         case 'a': 
         motor1DownBlu=!motor1DownBlu;
          if(motor1DownBlu ){delayM1Down();}else{motor1.run(RELEASE);}
         break;


         case 'B': 
          motor2UpBlu=!motor2UpBlu;
         if(motor2UpBlu ){delayM2Up(EEPROM.read(adressM2Up));}else{motor2.run(RELEASE);}
         break;

         case 'b': 
          motor2DownBlu=!motor2DownBlu;
          if(motor2DownBlu ){delayM2Down();}else{motor2.run(RELEASE);}
         break;


         case 'C': 
         motor3UpBlu=!motor3UpBlu;
         if(motor3UpBlu ){delayM3Up(EEPROM.read(adressM3Up));}else{motor3.run(RELEASE);}
         break;

         case 'c':
       motor3DownBlu=!motor3DownBlu;
          if(motor3DownBlu ){delayM3Down();}else{motor3.run(RELEASE);}
         break;


         case 'D': 
        delayM1Up(EEPROM.read(adressM1Up));
        delay(50);
        delayM2Up(EEPROM.read(adressM2Up));
        delay(50);
        delayM3Up(EEPROM.read(adressM3Up));
         break;

         case 'l': 
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        motor3.run(RELEASE);
         break;

         case 'd': 
         delayM1Down();
         delay(30);
         delayM2Down();
         delay(30);
         delayM3Down();
         break;
///////////////////////////////M1
         case 'E': 
         EEPROM.update(adressM1Up,speedM150);
         break;

         case 'e':
         EEPROM.update(adressM1Up,speedM160);
         break;
         case 'F': 
         EEPROM.update(adressM1Up,speedM170);
         break;

         case 'f':
         EEPROM.update(adressM1Up,speedM180);
         break;

         case 'G': 
         EEPROM.update(adressM1Up,speedM190);
         break;
/////////////////////////////M2
         case 'g':
         EEPROM.update(adressM2Up,speedM150);
         break;

         case 'H': 
         EEPROM.update(adressM2Up,speedM160);
         break;

         case 'h':
         EEPROM.update(adressM2Up,speedM170);
         break;
         
         case 'I': 
         EEPROM.update(adressM2Up,speedM180);
         break;

         case 'i':
         EEPROM.update(adressM2Up,speedM190);
         break;
/////////////////////////////////////M3
         case 'J': 
         EEPROM.update(adressM3Up,speedM150);
         break;

         case 'j':
         EEPROM.update(adressM3Up,speedM160);
         break;

         case 'K': 
         EEPROM.update(adressM3Up,speedM170);
         break;

         case 'k':
         EEPROM.update(adressM3Up,speedM180);
         break;

         case 'L':
         EEPROM.update(adressM3Up,speedM190);
         break;

         
         
        
         default:
         break;

       }
   }



  valueA0 = analogRead(A0);// считываем показания  мотора 1
  valueA1 = analogRead(A1);// считываем показания  мотора 2
  valueA2 = analogRead(A2);// считываем показания  мотора 3

  
  valueA5 = analogRead(A5);// считываем показания концевиков мотора 1
  valueA4 = analogRead(A4);// считываем показания концевиков мотора 2
  valueA3 = analogRead(A3);// считываем показания концевиков мотора 3
// Serial.println(valueA0);



////////////////////////////////////////////////
   // кнопки первого мотора
   
   //  кнопка вверх  нажата
if(valueA0 > 50 && valueA0 < 110 ){
   motor1UpBlu=!motor1UpBlu;
         if(motor1UpBlu ){delayM1Up(EEPROM.read(adressM1Up));}
            else{motor1.run(RELEASE);} 
  
}

// кнопка вниз нажата
 
if(valueA0 > 155 && valueA0 < 190 ){
   motor1DownBlu=!motor1DownBlu;
          if(motor1DownBlu ){delayM1Down();}
            else{motor1.run(RELEASE);}
}


   // концевики первого мотора
   
   // если сработал верхний концевик 
if(valueA5 > 50 && valueA5 < 110 ){
   if(motor1Up){//останавливаем мотор однократно
   motor1.run(RELEASE);
   }
   motor1Up=false; 
  
}else{ motor1Up=true;}

  // если сработал нижний концевик 
if(valueA5 > 155 && valueA5 < 190 ){
  if(motor1Down){
    motor1.run(RELEASE);
    }
  motor1Down=false; 
  
}else{motor1Down=true;}


////////////////////////////////////////////////
   // кнопки второго мотора
  
   //  кнопка вверх  нажата
if(valueA1 > 50 && valueA1 < 110 ){
   motor2UpBlu=!motor2UpBlu;
         if(motor2UpBlu ){delayM2Up(EEPROM.read(adressM2Up));}
            else{motor2.run(RELEASE);} 
  
}

// кнопка вниз нажата
 
if(valueA1 > 155 && valueA1 < 190 ){
   motor2DownBlu=!motor2DownBlu;
          if(motor2DownBlu ){delayM2Down();}
            else{motor2.run(RELEASE);}
}


   // концевики второго мотора
   
   // если сработал верхний концевик 
if(valueA4 > 50 && valueA4 < 110 ){
  if(motor2Up){
    motor2.run(RELEASE);
    }
   motor2Up=false; 
   
}else{ motor2Up=true;}

  // если сработал нижний концевик 
if(valueA4 > 155 && valueA4 < 190 ){
  if(motor2Down){
    motor2.run(RELEASE);
    }
  motor2Down=false; 
  
}else{motor2Down=true;}

////////////////////////////////////////////////
   // кнопки третьего мотора
   
   //  кнопка вверх  нажата
if(valueA2 > 50 && valueA2 < 110 ){
   motor3UpBlu=!motor3UpBlu;
         if(motor3UpBlu ){delayM3Up(EEPROM.read(adressM3Up));}
            else{motor3.run(RELEASE);} 
  
}

// кнопка вниз нажата
 
if(valueA2 > 155 && valueA2 < 190 ){
   motor3DownBlu=!motor3DownBlu;
          if(motor3DownBlu ){delayM3Down();}
            else{motor3.run(RELEASE);}
}


   // концевики третьего мотора
   
   // если сработал верхний концевик 
if(valueA3 > 50 && valueA3 < 110 ){
   if(motor3Up){
    motor3.run(RELEASE);
   }
   motor3Up=false; 
   
}else{ motor3Up=true;}

  // если сработал нижний концевик 
if(valueA3 > 155 && valueA3 < 190 ){
  if(motor3Down){
   motor3.run(RELEASE); 
  }
  motor3Down=false; 
  
}else{motor3Down=true;}

delay(150);
  
}
//////////////////M1
void delayM1Up(int speed_M1Up){
  if(motor1Up){
     motor1.setSpeed(speed_M1Up);
     motor1.run(FORWARD);
    }
  }
  void delayM1Down(){
  if(motor1Down){
     motor1.setSpeed(90);
     motor1.run(BACKWARD);
    }
  }
  
  

/////////////////////M2
  
  void delayM2Up(int speed_M2Up){
  if(motor2Up){
     motor2.setSpeed(speed_M2Up);
     motor2.run(FORWARD);
    }
  }
  void delayM2Down(){
  if(motor2Down){
     motor2.setSpeed(90);
     motor2.run(BACKWARD);
    }
  }
  

  //////////////////M3

  void delayM3Up(int speed_M3Up){
  if(motor3Up){
     motor3.setSpeed(speed_M3Up);
     motor3.run(FORWARD);
    }
  }
  void delayM3Down(){
  if(motor3Down){
     motor3.setSpeed(90);
     motor3.run(BACKWARD);
    }
  }
  
