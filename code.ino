#include <SoftwareSerial.h>
#include "Adafruit_FONA.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Servo.h> 
#define FONA_RX            2
#define FONA_TX            3
#define FONA_RST           4
#define Sensor A1
int buzzer = 11;  //not in use
Servo myservo; 
#define FONA_RI_INTERRUPT  0
SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
 
Adafruit_FONA fona = Adafruit_FONA(FONA_RST);


char PHONE_1[21] = "9141272788"; // Enter your Number here.

 
char gasalertmessage[141]= "GAS ALERT: Please check immediately";


void setup()
{
  //pinMode(5,INPUT);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  randomSeed(analogRead(0));
  pinMode(buzzer, OUTPUT);
  myservo.attach(9);

  Serial.begin(115200);
  Serial.println(F("Initializing....(May take 3 seconds)"));
  delay(5000);
  fonaSS.begin(9600); // if you're using software serial
  if (! fona.begin(fonaSS)) {           // can also try fona.begin(Serial1) 
    Serial.println(F("Couldn't find FONA"));
    while (1);
  }

   fona.print ("AT+CSMP=17,167,0,0\r");
    Serial.println(F("FONA is OK")); 
}

void loop(){  
   int value = analogRead(Sensor);
  lcd.setCursor(0, 0);
  lcd.print("Value :");
  lcd.print(value);
  lcd.print("  ");

    if (value < 400)
  { 
    digitalWrite(buzzer, HIGH);
    myservo.write(90);    
     Serial.println("GAS Alert");
     lcd.setCursor(0, 1);
    lcd.print("GAS Detected!");
     make_multi_call();
     send_multi_sms();
     
    
  }
  else  
  { 
   
   digitalWrite(buzzer, LOW);
    Serial.println("Safe");
    myservo.write(0);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("GAS normal"); 
    
    delay(500);
  }
 
  
 }

void send_multi_sms()
{
  if(PHONE_1 != ""){
    Serial.print("Phone 1: ");
    fona.sendSMS(PHONE_1,gasalertmessage);
    delay(20000);
  } 
}
void make_multi_call()
{
  if(PHONE_1 != ""){
    Serial.print("Phone 1: ");
    make_call(PHONE_1);
    delay(5000);
  } 
}

void make_call(String phone)
{
    Serial.println("calling....");
    fona.println("ATD"+phone+";");
    delay(20000); //20 sec delay
    fona.println("ATH");
    delay(1000); //1 sec delay
}