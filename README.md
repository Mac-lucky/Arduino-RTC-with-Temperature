# Arduino RTC BME280 LM35 PIR activated
 
I made RTC clock with weather station

I used DS3231 as a RTC and BME280 to read the temperature, humidity and pressure.
LCD backlight is activated, when motion sensor sends signal. I used HC-SR501 for this.

The LCD is using I2C connector to minimize the use of cables.

Everything is using I2C to send and receive data. Every SDA is connected to PIN A4 (yellow cable) and SCL (orange cable) to PIN A5.
![alt text](https://github.com/gryzmol98/Arduino-RTC-with-Temperature/blob/master/images/analogpins.jpg?raw=true)
![alt text](https://github.com/gryzmol98/Arduino-RTC-with-Temperature/blob/master/images/bme280.jpg?raw=true)

I used digital PIN D11 as a receiver of the signal from motion sensor. 

PINs D8 and D7 are used to recognise and receive the signal if button is pressed. I used 2 pins, because I have 2 buttons.

![alt text](https://github.com/gryzmol98/Arduino-RTC-with-Temperature/blob/master/images/digitalpins.jpg?raw=true)

I soldered all cables (5V, GND, SDA, SCL) separately and used heat shrinkable tubing to make it more elegant.

![alt text](https://github.com/gryzmol98/Arduino-RTC-with-Temperature/blob/master/images/cablecombined.jpg?raw=true)

In the end everything looks like this and is programmed to update the seconds every 1000ms for 8s and then show weather, humidity and pressure (updated every 1000ms) for 8s.

![alt text](https://github.com/gryzmol98/Arduino-RTC-with-Temperature/blob/master/images/Weather.jpg?raw=true)
![alt text](https://github.com/gryzmol98/Arduino-RTC-with-Temperature/blob/master/images/RTC.jpg?raw=true)

One of the is programmed to turn on lottery function, that shows 6 numbers for the LOTTO lottery. Arduino is checking every 1s, if the button is pressed then activates the function that prints numbers using random(). The numbers are printed in loop over the prefious ones, that looks like it's really drawing the numbers.

![alt text](https://github.com/gryzmol98/Arduino-RTC-with-Temperature/blob/master/images/lottery.gif?raw=true)

I made box for the electronics in Fusion 360. Files are in 3D print files folder. Downthre you can see how it looks like already printed.

![alt text](https://github.com/gryzmol98/Arduino-RTC-with-Temperature/blob/master/images/boxmodel.gif?raw=true)
![alt text](https://github.com/gryzmol98/Arduino-RTC-with-Temperature/blob/master/images/box.jpg?raw=true)

I want to program the other button, but for now I don't have any idea.
