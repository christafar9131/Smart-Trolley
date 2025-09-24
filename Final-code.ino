String inputString = "";
const int pwm1 = 6;  
const int pwm2 = 3;  
const int pwm3 = 4; 
const int pwm4 = 5; 

const int dir1 = 30;  
const int dir2 = 31;  
const int dir3 = 32; 
const int dir4 = 33; 

void setup() {

  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  pinMode(pwm3, OUTPUT);
  pinMode(pwm4, OUTPUT);
  pinMode(dir1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(dir3, OUTPUT);
  pinMode(dir4, OUTPUT);
  Serial.begin(250000);
  
}


void moveForward() {
  digitalWrite(dir2, HIGH);
  analogWrite(pwm2, 100);
  digitalWrite(dir4, LOW);
  analogWrite(pwm4, 100);
}

void moveBackward(){
  digitalWrite(dir2, LOW);
  analogWrite(pwm2, 100);
  digitalWrite(dir4, HIGH);
  analogWrite(pwm4, 100);
}

void turnLeft() {
  digitalWrite(dir1, LOW);
  analogWrite(pwm1, 100);
  digitalWrite(dir2, LOW);
  analogWrite(pwm2, 100);
  digitalWrite(dir3, LOW);
  analogWrite(pwm3, 100);
  digitalWrite(dir4, LOW);
  analogWrite(pwm4, 100);
}

void turnRight() {
  digitalWrite(dir1, HIGH);
  analogWrite(pwm1, 100);
  digitalWrite(dir2, HIGH);
  analogWrite(pwm2, 100);
  digitalWrite(dir3, HIGH);
  analogWrite(pwm3, 100);
  digitalWrite(dir4, HIGH);
  analogWrite(pwm4, 100);
}

void stopMotors() {
  digitalWrite(pwm1, 0);
  digitalWrite(pwm2, 0);
  digitalWrite(pwm3, 0);
  digitalWrite(pwm4, 0);
}

void loop() {
  
  if (Serial.available()) 
  {
    String input = Serial.readStringUntil('!');
    float velx, vely;  
    int xPos = input.indexOf('x');
    int yPos = input.indexOf('y');

    String velxStr = input.substring(0, xPos);
    String velyStr = input.substring(xPos + 1, yPos);
  
    velx = velxStr.toFloat();
    vely = velyStr.toFloat();

    if(velx){
      if(velx>4){
        turnRight();
        }
      else if(velx<-4){
        turnLeft();
        }
      else
        stopMotors();
    }
    if(vely){
      if(vely>4){
        moveForward();
        }
      else if(vely<-4){
        moveBackward();
        }
      else
        stopMotors();
    }

    if (input == ""){
      stopMotors();
      }
    input = "";
        
//    else if(inputString.endsWith("o"))
//    {
//      stopMotors();
    
    
    }}