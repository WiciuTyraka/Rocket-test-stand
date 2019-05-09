# Rocket test stand

## About
This is a project of rocket test stand to measure the trust and temperature of the engine and to save the data on SD-card. In nearly future I will add a wireless communication with computer to collect and proces data in real time. To wireless communication i will use a LoRa module.

- [Rocket test stand](#rocket-test-stand)
  * [About](#about)
  *  [PCB](#pcb)
      - [Schema](#schema)
      - [Board](#board)
      - [Libraries](#libraries)
  * [Sensors](#sensors)
      - [SD-card](#sd-card)
      - [Load cell and HX711](#load-cell-and-hx711)
      - [Thermocouples and max6675](#thermocouples-and-max6675)
      - [LoRa module](#lora-module)
      - [Pin map](#pin-map)
  * [Arduino Code](#arduino-code)
  * [STM32 Code](#stm32-code)



## PCB
Circut board is designed in Eagle

### Schema
 Rocket test stend consist of two board.
 - First board is a shield for Arduino Uno or STM32 Nucelo board. On this board is located a adpter for SD-card, amplifire for load cell and thermometr, and also a LoRa module.<br/>
[schema of rocket test stand board](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Schema/Rocekt_test_stand.sch)
![alt text](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Schema/Rocekt_test_stand.png)


- Second board is used to collecting signals from sensors and ignite the engine.<br/>
[schema of input rocket test stand board](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Schema/Rocekt_test_stand_input.sch)
![alt text](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Schema/Rocekt_test_stend_input.png)


### Board
links for downloading a board file.
- [link for rocket_test_stend.brd](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Board/Rocekt_test_stand.brd)
- [link for rocket_test_stend_input.brd](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Board/Rocekt_test_stand_input.brd)

### Libraries
Here are a necessary libraries for elements thats are used in project.
- [ark 8.5mm](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Lib/111_ark_8.5mm.lbr)
- [hx711](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Lib/111_hx711.lbr)
- [LoRa module](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Lib/111_LORA.lbr)
- [max6675](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Lib/111_max6675.lbr)
- [microsd](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Lib/111_microsd.lbr)

## Sensors
In this project are used few sensors and device, here you can find a exemple code, libraries and datasheet for them.

### SD-card
---
Micro sd-card adapter is used for saving all data in txt file or as a json.
<details>
<summary>details</summary>
</br>

#### Wireing schema
This is the schema for all the wireing with arduino
![alt text](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/Sensors/SD-card/sd-card_schema.png)

#### Adapter wireing
| MicroSD Card Adapter | Adruino UNO Pin |
|----------------------|----------------:|
|          CS          |        4        |
|          SCK         |        13       |
|          MOSI        |        11       |
|          MISO        |        12       |
|          VCC         |        5V       |
|          GND         |        GND      |

#### Arduino code
[the necessary code is here](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/Sensors/SD-card/save_to_file/save_to_file.ino)
</details>

### Load cell and HX711
---
Load cell id used for measuring a engine thrust. Analog signal form load cell is converting to digital by HX711 amplifier
<details>
<summary>details</summary>
</br>
I cant find a datasheet for my chinese load cell so made this table

#### Basic load resistance checks
| Resistance check | Typical 350 Ω |
|------------------|--------------:|
| Ex+ to Ex-       | ~410Ω         |
| S+ to S-         | 350Ω          |
| Ex+ to S+        | ~315Ω         |
| Ex+ to S-        | ~315Ω         |
| Ex- to S+        | ~280Ω         |
| Ex- to S-        | ~280Ω         |

#### Load cell wireing
| HX711 | Load cell |
|-------|----------:|
| E+    | white     |
| E-    | red       |
| S+    | black     |
| S-    | green     |

#### Amplifer schema
This is a schema for all the wireing with arduino
![alt text](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/Sensors/Load_cell/amplifier_schema.png)

#### HX711 library
You can download the necessary library here:
[download](https://halckemy.s3.amazonaws.com/uploads/attachments/392655/HX711-master.zip)

#### Arduino code
All the code necessary for calibration the load cell and measuring the force:
- calibration:
[the code is here](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/Sensors/Load_cell/calibration/calibration.ino)
- measurment:
[the code is here](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/Sensors/Load_cell/measurment/measurment.ino)

#### Datasheet
[link](https://circuits4you.com/wp-content/uploads/2016/11/hx711_datasheet_english.pdf)
</details>


### Thermocouples and max6675
---
To measure a temperature of the combustion chember and nozzle I'm using a thermocouple. Analog signal from this sensor is converting to digital by max6675 amplifier

<details>
<summary>details</summary>
</br>


#### Specifications of max6675
|                        |                    |
|------------------------|-------------------:|
| Suply Voltage          | 3.3 to 5 VDC       |
| Operating Current      | ~50mA              |
| Measurement Range      | 0 - 1024^∘C        |
| Measurement Resolution | +/- 0.25^∘C        |
| Output                 | Uses SPI interface |
| Required sensor        | K Thermocouple     |

#### Thermocouples schema
This is the schema for all the wireing with arduino
![alt text](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/Sensors/Thermocouple/thermocouples_schema.png)

#### MAX6675 library
You can download the necessary library here:
[download](https://github.com/adafruit/MAX6675-library)

#### Arduino code
Basic code for reading temperature
[the necessary code is here](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/Sensors/Thermocouple/thermocouples/thermocouples.ino)

#### Datasheet
[link](http://henrysbench.capnfatz.com/wp-content/uploads/2015/05/MAX6675-Datasheet.pdf)

</details>



### LoRa module
---
I used LoRa transceiver to ignite the engine from safe distance also wireless communication allows me to watch data in real time.

<details>
<summary>details</summary>
</br>

The chip I used in project is a RFM95W transceiver.
The  RFM95W transceivers  feature  the  LoRaTM  long range modem that provides ultra-long range spread spectrum communication and high interference immunity whilst minimising current consumption.

#### RFM95W schema
This is the schema for all the wireing with arduino
![alt text](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/Sensors/LoRa/LoRa_schema.png)

#### RFM95W library
You can download the necessary library here:
[download]()

#### Arduino code
Here is a code for a transmiter and reciver(in fact both of them are transceivers) :
- transmiter:
[the code is here](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/Sensors/LoRa/transmiter/transmiter.ino)
- reciver:
[the code is here](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/Sensors/LoRa/reciver/reciver.ino)

#### Datasheet
[link](https://www.hoperf.com/modules/lora/RFM95.html)

</details>


### Pin map
---
This table contains information abaout all pins to witch are connected device

| Pin number |Device    |
|------------|----------|
| 15         |led       |
| 16         |ignite    |
| 17         |buzzer    |
| 2          |HX711 CLK |
| 3          |HX711 DOUT|
| 4          |SD card   |
|   |   |


## Arduino code
This version of code not include a wireless communication
- here you can find a [code](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/Arduino_code/Rocekt_test_stand/Rocekt_test_stand.ino)

## STM32 code
cause i'm very busy right now, i'll back to this task in nearly future.

by Wiktor Tasarek
