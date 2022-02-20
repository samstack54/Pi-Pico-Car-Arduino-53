 // Line tracer code: Use TB6612 motor driver 
 //  Written by Se H. Yang
 
 #define PWMA  8 // A motor speed
 #define AIN2  9  // A motor
 #define AIN1  10  // A motor
 
 #define BIN1  11  // B motor speed
 #define BIN2  12  // B motor
 #define PWMB  13  // B motor
 #define SensorL  27 // Left side sensor
 #define SensorR  26 // Right side sensor
  
  void setup() {
  pinMode(SensorR, INPUT) ;
  pinMode(SensorL, INPUT) ;
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);   
  }
  
 void loop() { 

  if ( !digitalRead(SensorL) == 1 &&  !digitalRead(SensorR) == 1 )
  
  { Control(250, 250, 1, 0, 1, 0) ; } // Forward(속도A, 속도B,우직진,직진)  

  if ( digitalRead( SensorL) == 1 && !digitalRead(SensorR) == 1) 
  { Control(250, 150, 0, 1, 1, 0) ; } // Right turn (A Backward, B Forward) 

  else if ( !digitalRead(SensorL) == 1 &&  digitalRead(SensorR) == 1 )
   { Control(150, 250, 1, 0, 0, 1) ; } // Left turn (A Forward, B Backward) }

  else if ( digitalRead(SensorL) == 1 &&  digitalRead(SensorR) == 1 )
   { Control(0, 0, 0, 0, 0, 0) ; } // STOP (A Stop, B Stop)   
 } // end of Loop

 void Control(int SpeedL, int SpeedR, int A1HL, int A2HL, int B1HL, int B2HL )
 {  
  analogWrite(PWMA, SpeedL) ;
  digitalWrite(AIN1, A1HL) ; 
  digitalWrite(AIN2, A2HL) ; 
  analogWrite(PWMB, SpeedR) ;
  digitalWrite(BIN1, B1HL) ; 
  digitalWrite(BIN2, B2HL) ;  
 }
