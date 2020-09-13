#include <Adafruit_BME280.h>
#include <DS3231.h>
#include <LiquidCrystal.h>
#define PIR 11

Adafruit_BME280 bme; // use I2C interface

int r;
int numbers[6];
int button1;
int button2;

// Pins definition for Time Set Buttons
int but1=0;// pin 0 for Hours Setting
int but2=1;// pin 1 for Minutes 

DS3231  rtc(SDA, SCL);
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int bl=10; // Backlight pin
const int backlight=120; // no more then 7mA !!!


void setup() {   
    pinMode(PIR, INPUT);
    bme.begin();
    rtc.begin();
    //rtc.setTime(12, 0, 0);     // Set the time to 12:00:00 (24hr format)
    //rtc.setDate(1, 1, 2014);   // Set the date to January 1st, 2014
    //rtc.setDOW(SATURDAY);     // Set Day-of-Week to SUNDAY

    lcd.begin(16,2);
    pinMode(but1,INPUT_PULLUP);// avoid external Pullup resistors for Button 1
    pinMode(but2,INPUT_PULLUP);// and Button 2
    analogWrite(bl,0);// Turn on Backlight
}
void loop() { 
for (int a=0; a<8; a++) 
{
    but2press();
    turnonpir();
    lcd.setCursor(0,0);
    lcd.print(rtc.getDOWStr(FORMAT_SHORT));
    lcd.print(" ");
    lcd.print(rtc.getTimeStr());
    lcd.setCursor(0,1);
    lcd.print("Data: ");
    lcd.print(rtc.getDateStr());
    delay(1000);
}
lcd.clear();

for (int b=0; b<8; b++)
{
    but2press();
    turnonpir();
    lcd.setCursor(0,0);
    lcd.print(bme.readTemperature());
    lcd.print("*C   ");
    lcd.print(bme.readHumidity());
    lcd.print("%");
    lcd.setCursor(3,1);
    lcd.print(bme.readPressure()/100.0);
    lcd.print("hPa ");
    delay(1000);
}
lcd.clear();
}


void lottery(){
lcd.clear();
for (int i=0; i<30; i++){
lcd.setCursor(3, 0);
    for (int i=0; i<6; i++){
        if (i == 3){
            lcd.setCursor(3, 1);
        }
        numbers[i] = r;
        r = random(1, 49);
        if (r<10){
            lcd.print("0");
            lcd.print(r);
            lcd.print("  ");
        }
        else{    
            lcd.print(r);
            lcd.print("  ");
        }
        
        
    }
delay(50);    
}    
delay(7000);
}

void turnonpir(){
    if (digitalRead(PIR) == HIGH){
        analogWrite(bl,backlight);
    }
    else{
        analogWrite(bl,0);
    }
}

void but2press(){
    if(digitalRead(1) == LOW){
        analogWrite(bl,backlight);
        lottery();
    }
}

void but1press(){
    if(digitalRead(0) == LOW){
        analogWrite(bl,backlight);
        lottery();
    }
}

