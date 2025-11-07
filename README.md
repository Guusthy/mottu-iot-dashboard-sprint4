# mottu-iot-dashboard-sprint4

Mottu IoT Dashboard - Controle de Pátio com ESP32 + Node-RED

Este projeto faz parte da disciplina **Disruptive Architectures: IoT, IoB & Generative AI**, e simula o **controle de pátio de motos da empresa Mottu**, utilizando **IoT, MQTT e Node-RED**.

## Visão Geral

O sistema monitora vagas de motos e o estado de manutenção de cada uma.  
A comunicação é feita via **protocolo MQTT** e os dados são exibidos em um **dashboard do Node-RED**.

**Tecnologias utilizadas:**
- ESP32 (simulado no [Wokwi](https://wokwi.com))
- Sensor ultrassônico HC-SR04
- LEDs e botão
- Node-RED Dashboard
- Broker MQTT

Estrutura do Projeto

| Pasta | Descrição |
|-------|------------|
| `wokwi/` | Contém o código do ESP32 e o circuito da simulação |
| `node-red/` | Contém o fluxo e dashboard do Node-RED |

## Fluxo de Funcionamento

1. O **ESP32** detecta distância via sensor ultrassônico (vaga livre/ocupada).  
2. Um **botão** alterna entre “Moto em bom estado” e “Moto em manutenção”.  
3. O ESP32 envia os dados via **MQTT** para o **Node-RED**.  
4. O **Node-RED** processa e exibe os dados na dashboard com indicadores e gráficos.

## Como Executar

###  1. Simulação no Wokwi
1. Acesse [https://wokwi.com](https://wokwi.com)
2. Importe os arquivos da pasta `wokwi/`
3. Execute o projeto e observe as mensagens publicadas no Serial Monitor.

### 2. Dashboard no Node-RED
1. Abra o Node-RED localmente
2. Vá em **Menu → Importar → Colar o conteúdo de `flow.json`**
3. Configure o broker como `test.mosquitto.org` (porta 1883)
4. Clique em **Deploy**

##  Resultados Parciais

- Indicadores de vaga (livre/ocupada)
- Estado da moto (bom estado/manutenção)
- Gráfico histórico com as variações
- Dashboard responsiva e visualmente agradável


