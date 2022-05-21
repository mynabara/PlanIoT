//Set up Arduino pins
#define pinDigital 13
#define pinAnalog A0
#define pinRelay 7

float analogOutput = 0;
float gauge = 0;
int soilSensor = 0;

void setup() {
  Serial.begin(9600);

  pinMode(pinDigital, INPUT);
  pinMode(pinRelay, OUTPUT);
}

void loop() {
 
  soilSensor = digitalRead(pinDigital);
  analogOutput = analogRead(pinAnalog);
  gauge = map(analogOutput, 350, 1023, 100, 0); // valores convertidos para % e ajustados com base na saída do "Valor sensor"
 
  Serial.println("Necessidade de água");
  Serial.println(soilSensor);
  Serial.println("% Umidade");
  Serial.println(gauge);
  Serial.println("Valor sensor"); // 
  Serial.println(analogOutput);

  if (soilSensor == HIGH) { // soilSensor == HIGH = 1 -> sem umidade
    digitalWrite(pinRelay, LOW); // pinRelay, LOW -> vazão de água aberta
    delay(2000); // 2000 = 2seg -> tempo para irrigar e fazer a próxima leitura
  }
  else { // soilSensor == LOW = 0 -> com umidade
    digitalWrite(pinRelay, HIGH); // pinRelay, HIGH -> vazão de água fechada
    delay(5000); // ideal 900000 = 15min; teste 50000 = 5seg -> pode-se esperar mais para a próxima leitura pois já há umidade
    
  }
}
