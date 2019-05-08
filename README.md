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
      - [Load cell](#load_cell)
      - [Thermocouples](#thermocouples)
      - [LoRa module](#lora_module)
      - [Pin map](#pin_map)
  * [Arduino Code](*arduino_code)
  * [STM32 Code](stm32_code)



## PCB
Circut board is designed in Eagle

### Schema
 Rocket test stend consist of two board.
 - First board is a shield for Arduino Uno or STM32 Nucelo board. On this board is located a adpter for SD-card, amplifire for load cell and thermometr, and also a LoRa module.<br/>
[schema of rocket test stand board](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Schema/hamownia.sch)

- Second board is used to collecting signals from sensors and ignite the engine.<br/>
[schema of input rocket test stand board](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Schema/hamownia_output.sch)

### Board
links for downloading a board file.
- [link for rocket_test_stend.brd](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Board/hamownia.brd)
- [link for rocket_test_stend_input.brd](https://github.com/WiciuTyraka/Rocket-test-stand/blob/master/PCB/Board/hamownia_output.brd)

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
Save date to txt file
<details>
<summary>details</summary>
</br>

#### Wireing schema
This is the schema for all the wireing with arduino
![alt text](https://github.com/Tyraka/Rocket-test-stand/blob/master/MicroSD%20Card%20Adapter/fritzing_bb.png)

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
[the necessary code is here](https://github.com/Tyraka/Rocket-test-stand/blob/master/MicroSD%20Card%20Adapter/save_to_file.ino)
</details>

### Load cell

<details>
<summary>details</summary>
</br>
#### Load cell wireing
| HX711 | Load cell |
|-------|----------:|
| E+    | white     |
| E-    | red       |
| S+    | black     |
| S-    | green     |

#### Basic load resistance checks
| Resistance check | Typical 350 Ω |
|------------------|--------------:|
| Ex+ to Ex-       | ~410Ω         |
| S+ to S-         | 350Ω          |
| Ex+ to S+        | ~315Ω         |
| Ex+ to S-        | ~315Ω         |
| Ex- to S+        | ~280Ω         |
| Ex- to S-        | ~280Ω         |
</details>
