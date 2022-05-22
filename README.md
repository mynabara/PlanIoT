# PlanIoT

## About
PlanIoT is an IoT Project to irrigate plants using Arduino, written by Myna Obara.

Made for UNIVERSIDADE PRESBITERIANA MACKENZIE - Faculdade de Computação e Informática (FCI).

I would like to thank professor Wallace Rodrigues de Santana for his support in this project - PlanIoT is my first IoT project and I am proud of what I
have accomplished.


## Components
The components used in this project can be seen in this Fritzing model:

![PlanIoT_Myna_bb](https://user-images.githubusercontent.com/26822745/169669718-bad9fbea-d507-4554-b044-3bce204752d7.png)


## Versions
PlanIoT_v1 file contains the first Arduino code I made to test the components used in this project.

PlanIoT_v2 file contains the Arduino code using Adafruit IO MQTT Broker, which enables to use Node-RED as a reader and trigger of PlanIoT.

## Steps
First of all, it is necessary to upload PlanIoT_v2 and Firmata to Arduino R3 UNO.

Once it is done, open your computer's terminal and execute the comand "node-red" (it is necessary to install Node-RED previously).

After that, you access in your browser this URL: http://localhost:1880/ 

You can make your own flows or use flows.json that is available in this repository.

Friendly reminder: in this project, WhatsApp Callmebot is using my personal credentials, which means that the messages are sent to my number; if you want to receive these messagens in your WhatsApp, access: https://www.callmebot.com/blog/free-api-whatsapp-messages/

## Contact
If you enjoyed this project or need some help, say "hi":

mynabara@gmail.com

https://www.linkedin.com/in/myna-obara/
