# Arduino RTC BME280 LM35 PIR activated
 
I made RTC clock with weather station

I used DS3231 as a RTC and BME280 to read the temperature, humidity and pressure.
LCD backlight is activated, when motion sensor sends signal. I used HC-SR501 for this.

The LCD is using I2C connector to minimize the use of cables.

Everything is using I2C to send and receive data. Every SDA is connected to PIN A4 (yellow cable) and SCL (orange cable) to PIN A5.

I used digital PIN D11 as a receiver of the signal from motion sensor. 

PINs D8 and D7 are used to recognise and receive the signal if button is pressed. I used 2 pins, because I have 2 buttons.

![alt text](https://github.com/gryzmol98/Arduino-RTC-with-Temperature/blob/master/images/digitalpins.jpg?raw=true)

