# PlanIoT

## About
PlanIoT is an IoT Project to irrigate plants using Arduino, written by Myna Obara.

Made for UNIVERSIDADE PRESBITERIANA MACKENZIE - Faculdade de Computação e Informática (FCI).

I would like to thank professor Wallace Rodrigues de Santana for his support in this project, which is my first IoT project.

For more details about this project, access this document (it is in Portuguese): 
https://docs.google.com/document/d/1xpW0xN1MINzceFFudWUqfyrf_Rl9AdYH/edit?usp=sharing&ouid=112598686229944193808&rtpof=true&sd=true

## Components
The components used in this project can be seen in this Fritzing model:

![PlanIoT_Myna_bb](https://user-images.githubusercontent.com/26822745/169669718-bad9fbea-d507-4554-b044-3bce204752d7.png)

Components used in this prototype:

- Arduino UNO R3
- Umidity soil sensor
- Solenoid valve
- Relay module
- Protoboard
- Jumper wires
- USB A-B cable
- Power supply 12V/1A
- P4 female plug connector
- 12V 20 AWG cable

## Versions
PlanIoT_v1 file contains the first Arduino code I made to test the components used in this project.

PlanIoT_v2 file contains the Arduino code using Adafruit IO MQTT Broker, which enables to use Node-RED as a reader and trigger of PlanIoT.

## Steps
First of all, it is necessary to upload PlanIoT_v2 and Firmata to Arduino R3 UNO.

Once it is done, open your computer's terminal and execute the comand "node-red" (it is necessary to install Node-RED previously).

After that, you access in your browser this URL: http://localhost:1880/ 

You can make your own flows or use flows.json that is available in this repository.

Friendly reminder: in this project, Adafruit needs personal credential, which is blocked when they found it on the open web. That made me change those infos since I made this repository public. 

You can access https://io.adafruit.com/ to use Adafruit MQTT and to receive messages in your WhatsApp, access https://www.callmebot.com/blog/free-api-whatsapp-messages/

This image can help you to understand the whole function of PlanIoT:
![MACK - Myna (15)](https://user-images.githubusercontent.com/26822745/170808312-241fd492-c537-4f69-a731-78249ebb597f.jpg)

To see how the prototype works, you can watch the videos of each version of this project:
- v1: https://youtu.be/WYapYRavuXY
- v2: https://youtu.be/_y0NBFvDmj0

## Contact
If you enjoyed this project, need some help or have any suggestions, say "hi":

mynabara@gmail.com

https://www.linkedin.com/in/myna-obara/
