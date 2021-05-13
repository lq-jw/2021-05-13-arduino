byte seven_seg_digits[10][7]={
{0,0,0,0,0,0,1},
{1,0,0,1,1,1,1},
{0,0,1,0,0,1,0},
{0,0,0,0,1,1,0},
{1,0,0,1,1,0,0},
{0,1,0,0,1,0,0},
{0,1,0,0,0,0,0},
{0,0,0,1,1,1,1},
{0,0,0,0,0,0,0},
{0,0,0,1,1,0,0}
  };

  const int buttonpin = 12;
  const int Buttonpin = 11;
  const int buttonPin = 9;
  int num = 0;
  int oldbtn=0;

void sevenSegWrite(byte digit){
  byte pin = 2;
  for(byte seg = 0;seg < 7;seg++){
    digitalWrite(pin,seven_seg_digits[digit][seg]);
    pin++;
  }
}

void setup() {
  Serial.begin(9600);

    pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
   
    pinMode(buttonPin,INPUT);
    digitalWrite(buttonpin,HIGH);
    digitalWrite(Buttonpin,HIGH);
    sevenSegWrite(num);
}



void loop() {
  //第二題
  int buttonState = digitalRead(buttonPin);
  if(buttonState == HIGH && oldbtn==0 ){
    Serial.println(num);
    num++;
      if(num>9){
        num=0;}
 
      sevenSegWrite(num);}

  oldbtn=buttonState;
  delay(2);
  
  //第一題
  //if(buttonState == LOW ){
    //Serial.println(num);
    //num++;
      //if(num>9){num=0;}
  //}
      //sevenSegWrite(num);
    // put your main code here, to run repeatedly:
  //oldbtn=buttonState;
  //delay(1000);
}
