#define TRIG_PIN 12
#define ECHO_PIN 14

#define LED_VERMELHO 13      // Vaga ocupada
#define LED_VERDE_VAGA 27    // Vaga livre
#define LED_AMARELO 22       // Moto em manutenção
#define LED_VERDE_MOTO 4     // Moto em bom estado

#define BOTAO 23             // Botão manutenção

long duracao;
float distancia;
bool motoEmManutencao = false;   
bool ultimoEstadoBotao = HIGH;  

void setup() {
  Serial.begin(115200);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE_VAGA, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE_MOTO, OUTPUT);

  pinMode(BOTAO, INPUT_PULLUP); 

  digitalWrite(LED_VERDE_MOTO, HIGH);
  digitalWrite(LED_AMARELO, LOW);

  Serial.println("Sistema iniciado!");
}

void loop() {
  
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duracao = pulseIn(ECHO_PIN, HIGH);
  distancia = (duracao * 0.0343) / 2; 

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  
  if (distancia < 10 && distancia > 0) {  
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_VERDE_VAGA, LOW);
  } else {                                
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE_VAGA, HIGH);
  }

  
  bool estadoBotao = digitalRead(BOTAO);

  
  if (ultimoEstadoBotao == HIGH && estadoBotao == LOW) {
    motoEmManutencao = !motoEmManutencao;  
    delay(200); 
  }

  ultimoEstadoBotao = estadoBotao; 

  if (motoEmManutencao) {
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERDE_MOTO, LOW);
    Serial.println("Moto em MANUTENCAO");
  } else {
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE_MOTO, HIGH);
    Serial.println("Moto em BOM ESTADO");
  }

 
  Serial.print("Vaga: ");
  Serial.print(distancia < 10 ? "OCUPADA" : "LIVRE");
  Serial.print(" | Moto: ");
  Serial.println(motoEmManutencao ? "MANUTENCAO" : "BOM ESTADO");

  delay(200);
}
