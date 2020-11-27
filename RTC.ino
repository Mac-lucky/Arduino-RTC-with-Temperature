#include <LiquidCrystal_I2C.h>
#include <Adafruit_BME280.h>
#include <DS3231.h>

#define PIR 11

Adafruit_BME280 bme; // use I2C interface

int r;
int numbers[6];

// Pins definition for Time Set Buttons
int but1=8;// pin 0 for Hours Setting
int but2=9;// pin 1 for Minutes 

DS3231  rtc(A4, A5);

LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() { 
    lcd.init();  
    lcd.backlight();
    pinMode(PIR, INPUT);
    randomSeed(analogRead(A0));
    bme.begin();
    rtc.begin();
    //rtc.setTime(17, 31, 30);     // Set the time to 12:00:00 (24hr format)
    //rtc.setDate(11, 11, 2020);   // Set the date to January 1st, 2014
    //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY

    pinMode(but1,INPUT_PULLUP);// Button 1
    pinMode(but2,INPUT_PULLUP);// and Button 2
}
void loop() { 
for (int a=0; a<8; a++)         //display for 8s and updat evry 1s
{
    but2press();
    turnonpir();
    lcd.setCursor(0,0);
    lcd.print(rtc.getDOWStr(FORMAT_SHORT));     //read day fo the week
    lcd.print(" ");
    lcd.print(rtc.getTimeStr());                //read time
    lcd.setCursor(0,1);
    lcd.print("Data: ");
    lcd.print(rtc.getDateStr());                //read date
    delay(500);             //better reaction
    but2press();            //check if button is pressed
    turnonpir();            //check if signal from motion is high
    delay(500);
}
lcd.clear();

for (int b=0; b<8; b++)
{
    but2press();            //check if button is pressed
    turnonpir();            //check if signal from motion is high
    lcd.setCursor(0,0);
    lcd.print(bme.readTemperature());       //read temperature
    lcd.print("*C   ");
    lcd.print(bme.readHumidity());          //read humidity
    lcd.print("%");
    lcd.setCursor(3,1);
    lcd.print(bme.readPressure()/100.0);    //read pressure
    lcd.print("hPa ");
    delay(500);             //better reaction
    but2press();            //check if button is pressed
    turnonpir();            //check if signal from motion is high
    delay(500);
}
lcd.clear();
}


void lottery(){             
lcd.clear();
for (int i=0; i<30; i++){       //print numbers over to make the lottery effect 
lcd.setCursor(3, 0);
    for (int i=0; i<6; i++){
        if (i == 3){
            lcd.setCursor(3, 1);
        }
        numbers[i] = r;
        r = random(1, 50);
        if (r<10){              //make numbers below 10 to have 0 before the actual number generated
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

void turnonpir(){       //turn on screen if motion sensor signal is high
    if (digitalRead(PIR) == HIGH){
        lcd.backlight();
    }
    else{
        lcd.noBacklight();
    }
}

void but2press(){       //check if button is pressed
    if(digitalRead(8) == LOW){
        lcd.backlight();
        lottery();
    }
}

void but1press(){       //chck if button is pressed
    if(digitalRead(9) == LOW){
        lcd.backlight();
        lottery();
    }
}
