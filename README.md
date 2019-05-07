# Rocket test stand

## About
This is a project of rocket test stand to measure the trust and temperature of the engine and to save the data on SD-card. In nearly future I will add a wireless communication with computer to collect and proces data in real time. To wireless communication i will use a LoRa module.

- [Rocket test stand](#rocket-test-stand)
  * [About](#about)
  *  [PCB](#pcb)
      - [Schema](#schema)
      - [Board](#board)
      - [Libraries](#libraries)




## PCB
Circut board is designed in Eagle

### Schema
 Rocket test stend consist of two board.
 - First board is a shield for Arduino Uno or STM32 Nucelo board. On this board is located a adpter for SD-card, amplifire for load cell and thermometr, and also a LoRa module.
[schema of rocket test stand board]()

- Second board is used to collecting signals from sensors and ignite the engine.    
[schema of input rocket test stand board]()

### Board
links for downloading a board file.
- [link for rocket_test_stend.brd]()
- [link for rocket_test_stend_input.brd]()

### Libraries
Here are a necessary libraries for elements thats are used in project.
- [ark 8.5mm]()
- [hx711]()
- [LoRa module]()
- [max6675]()
- [microsd]()
