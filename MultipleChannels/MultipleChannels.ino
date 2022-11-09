#include <dht.h>
#include <LiquidCrystal.h>

dht DHT;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define DHT11_PIN 7

#include "LedStripController.h"

//24 key remote
#define	IR_BRIGHNTESS_UP           0xF700FF //világossabá teszi
#define	IR_BRIGHNTESS_DOWN         0xF7807F //halvánnyabá teszi
#define	IR_OFF                     0xF740BF //a led ki kapcsol
#define	IR_ON                      0xF7C03F //a led bekapcsol
#define	IR_RED                     0xF720DF //piros
#define	IR_GREEN                   0xF7A05F //sötét zöld
#define	IR_DEEP_BLUE               0xF7609F //sötét kék
#define	IR_WHITE                   0xF7E01F //fehér
#define	IR_DEEP_ORANGE             0xF710EF //sötét / mély narancssárga
#define	IR_GREENIS_BLUE            0xF7906F //zöldes kék
#define	IR_BLUE_WITH_PURPLE        0xF750AF //kék lilás beütéssel
#define	IR_FLASH                   0xF7D02F //szivárvány szineveil gyorsan villog
#define	IR_ORANGE               0xF730CF //narancs sárga
#define	IR_CYAN                    0xF7B04F //sötétebb cián kék
#define	IR_BRIGHT_PURPLE           0xF7708F //világos lila
#define	IR_STROBE                  0xF7F00F //ki be blinkelo szivárvány
#define	IR_BRIGHT_ORANGE           0xF708F7 //világos narancssárga
#define	IR_BRIGHT_CYAN             0xF78877 //világos kék / cián kék
#define	IR_BRIGHT_PURPLE_WITH_PINK 0xF748B7 //világos lila rozsaszin beütéssel
#define	IR_FADE                    0xF7C837 //fadel szivárvány
#define	IR_YELLOW_WITH_GREEN       0xF728D7 //citrom sárga zöldesebb beütéssel
#define	IR_BRIGHT_BLUE             0xF7A857 //világos kék
#define	IR_MAGENTA                 0xF76897 //magenta, lila/rózaszin
#define	IR_SMOOTH                  0xF7E817 //blinking szivárvány

#define RGB_CHANNEL_0 13

LedStripController led_channel_0;

void setup() 
{
   // Initialise the output channels.
   led_channel_0.begin(RGB_CHANNEL_0);
   Serial.begin(9600);    //HDT
   lcd.begin(16, 2); //Display
  lcd.print("hello, world!");
}

void brightnessDown(int wait){
  led_channel_0.writeCommand(IR_BRIGHNTESS_DOWN);
  delay(wait);
}

void brightnessUp(int wait){
  led_channel_0.writeCommand(IR_BRIGHNTESS_UP);
  delay(wait);
}

void storm(){
  led_channel_0.writeCommand(IR_DEEP_BLUE);
  delay(1000);
  led_channel_0.writeCommand(IR_BRIGHNTESS_DOWN);
  delay(500);
  led_channel_0.writeCommand(IR_BRIGHNTESS_DOWN);
  delay(500);
  led_channel_0.writeCommand(IR_BRIGHNTESS_DOWN);
  delay(500);
   led_channel_0.writeCommand(IR_BRIGHNTESS_DOWN);
  delay(500);
   led_channel_0.writeCommand(IR_BRIGHNTESS_DOWN);
  delay(500);
  led_channel_0.writeCommand(IR_BRIGHNTESS_DOWN);
  delay(5000);
  led_channel_0.writeCommand(IR_WHITE);
  delay(60);
   led_channel_0.writeCommand(IR_DEEP_BLUE);
  delay(200);
  led_channel_0.writeCommand(IR_WHITE);
  delay(60);
}

void snow(){
 led_channel_0.writeCommand(IR_WHITE);
  delay(60);
   brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
   brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessUp(100);
  brightnessUp(100);
  brightnessUp(100);
  brightnessUp(100);
  brightnessUp(100);
  brightnessUp(100);
  brightnessUp(100);  
}

void sunnrise(){
  led_channel_0.writeCommand(IR_DEEP_BLUE);
  delay(200);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
   brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(20000);
  brightnessUp(2000);
  brightnessUp(2000);
  brightnessUp(2000);
  brightnessUp(2000);
  brightnessUp(2000);
  brightnessUp(2000);
  brightnessUp(2000);
  led_channel_0.writeCommand(IR_WHITE);
  delay(5000);
   led_channel_0.writeCommand(IR_BRIGHT_ORANGE);
  delay(10000);
  led_channel_0.writeCommand(IR_ORANGE);
  delay(10000);
  led_channel_0.writeCommand(IR_DEEP_ORANGE);
  delay(10000);
  led_channel_0.writeCommand(IR_RED);
  delay(500);  
  brightnessDown(500);
  brightnessDown(500);
  brightnessDown(500);
  brightnessDown(500);
  brightnessDown(500);
  brightnessDown(500);
  brightnessDown(500);
  brightnessDown(500);
  led_channel_0.writeCommand(IR_DEEP_ORANGE);
  delay(100000);
}

void sunny(){
led_channel_0.writeCommand(IR_DEEP_ORANGE);  
}

void hot(){
led_channel_0.writeCommand(IR_RED);
  delay(60);
   brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
   brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessDown(100);
  brightnessUp(100);
  brightnessUp(100);
  brightnessUp(100);
  brightnessUp(100);
  brightnessUp(100);
  brightnessUp(100);
  brightnessUp(100);   
}

void loop() {
   int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(1000);  
  if(DHT.temperature < 0 & DHT.temperature > -99){
    snow();
  }
  if(DHT.humidity < 60 & DHT.humidity > -1){
    sunny();
  }  
  if(DHT.humidity > 60 & DHT.humidity > -1){
   storm();
  }  
  if(DHT.temperature > 29 & DHT.temperature > -1){
    hot();
  }
 lcd.print("hello, world!");
}
