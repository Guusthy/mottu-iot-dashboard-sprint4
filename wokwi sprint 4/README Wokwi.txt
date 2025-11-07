Wokwi ESP32 Simulação

 Descrição
Simulação do circuito IoT com ESP32, sensor ultrassônico, LEDs e botão.

 Componentes usados:
- ESP32
- HC-SR04 (TRIG: 12, ECHO: 14)
- Botão (pino 23)
- LEDs:
  - Vermelho (pino 13)
  - Verde Vaga (pino 27)
  - Amarelo (pino 22)
  - Verde Moto (pino 4)

 Conexão MQTT
Broker: `test.mosquitto.org`  
Tópico: `esp32/status`

 Como rodar
1. Acesse [https://wokwi.com](https://wokwi.com)
2. Importe diagram.json e sketch.ino
3. Execute o projeto e veja a saída no Serial Monitor.
