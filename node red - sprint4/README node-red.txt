Node-RED Dashboard

Descrição
Fluxo Node-RED responsável por receber os dados do ESP32 via MQTT e exibi-los em tempo real.

Componentes principais:
- MQTT In: Recebe mensagens do tópico esp32/status
- Function Node: Processa e organiza os dados
- UI Text / Template / Chart: Exibem informações e gráficos no dashboard

Como usar
1. Copie o conteúdo de flow.json
2. No Node-RED → Importar → Colar JSON → Importar
3. Dê Deploy

