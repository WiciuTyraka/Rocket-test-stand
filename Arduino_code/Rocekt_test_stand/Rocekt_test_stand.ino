
#include <Arduino.h>
#include <SPI.h>
#include <SD.h>                                    // biblioteka do karty SD
#include "HX711.h"                                 // biblioteka do hamowni

#define DOUT  3
#define CLK  2
#define LED 15
#define PYRO 16
#define BUZZER 17

///////////////////   --------------   SETTING !!!   -----------------    ///////////////////////////

#define CALIB_FACTOR 9600   // <----------- tu musisz wpisac wspolczynnik kalibracji

#define TIME_FOR_RUN 5000      // czas na ucieczke liczony w [ms]

#define FIRE 5000             // czas przez ktorey bedzie sie palic grzala w [ms]

//////////////////------------------------------------------------------------/////////////////////////////

HX711 scale(DOUT, CLK);
File plik;

int temp_time = 0;
float trust = 0;


void logger(float);

void setup()
{
  Serial.begin(56650);                                    //uruchom UART o prędkości 9600 baud

  pinMode(LED, OUTPUT);                   // definicja leda
  digitalWrite(LED, LOW);                 // led wylaczony

  pinMode(PYRO, OUTPUT);                  //definicja zapalnika
  digitalWrite(PYRO, LOW);                //zapalnik wylaczony

  pinMode(BUZZER, OUTPUT);               //definicja buzzera

  scale.set_scale(CALIB_FACTOR);                       // ustawienie wspolczynnika kalibracji
  scale.tare();                                        //taruj wage

  Serial.begin(9600);                                    //uruchom UART o prędkości 9600 baud



  if (!SD.begin(4))                                       //sprawdź czy nie ma karty na pinie ChipSelect 4
  {
     Serial.println("Nie wykryto karty(ERR)");            //błąd wykrycia karty
     while(1);                                              // zatrzymaj program
  }

  Serial.println("Karta Wykryta (3/3))");                 //Karta wykryta
  digitalWrite(LED, HIGH);

  if (SD.exists("readouts.txt"))                               //sprawdź czy istnieje plik o nazwie readouts.txt
  {

   Serial.println("Plik o podanej nazwie istnieje !");

  }

  else                                                   //jeżeli nie istnieje to
  {

   plik = SD.open("readouts.txt", FILE_WRITE);                //utwórz plik
   Serial.println("Utworzono plik o nazwie readouts.txt");

  }
  //delay(3000);

  while(millis() < TIME_FOR_RUN)
  {
     tone(17, 2000,500);      // wlacz buzzer na 0.5s
     delay(1000);

  }

  temp_time = millis();
  digitalWrite(PYRO,HIGH);
}


void loop()
{
  if((millis() - temp_time) > FIRE)
  {
    digitalWrite(PYRO,LOW);
  }

  trust = scale.get_units();
  Serial.print("trust: ");
  Serial.print(trust);
  Serial.println(" N");
  Serial.println();


  logger(trust);                            //zapisz na karte

}

void logger(float trust)
{

  plik = SD.open("readouts.txt", FILE_WRITE);                   //otwórz plik readouts.txt
  plik.println(trust);                                         //zapisz dane
  plik.close();                                            //zamknij/zapisz plik
  delay(150);
  Serial.println("Zapisano !");                            //poinformuj o zapisaniu pliku

}
