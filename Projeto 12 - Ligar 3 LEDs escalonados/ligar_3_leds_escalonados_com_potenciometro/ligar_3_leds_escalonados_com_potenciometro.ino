//Declaração de variáveis globais
//Valor que armazena a leitura da tensão do potenciômetro
int valorPot = 0;

//pino do potenciômetro
int pinoPot = A0;

//pino do LED vermelho
int pinoLedVermelho = 3;

//pino do LED amarelo
int pinoLedAmarelo = 5;

//pino do LED verde
int pinoLedVerde = 6;

void setup()
{
  pinMode(pinoPot, INPUT);
  pinMode(pinoLedVermelho, OUTPUT);
  pinMode(pinoLedAmarelo, OUTPUT);
  pinMode(pinoLedVerde, OUTPUT);
  
}

void loop()
{
  
  valorPot = analogRead(pinoPot);

  //Verifica se o valor de leitura do potenciometro é menor que 340 para acionar o LED vermelho
  if (valorPot <= 340) {

    //aciona o LED vermelho com brilho variável
    analogWrite(pinoLedVermelho, map(valorPot, 0, 340, 0, 255));

    //Deixa os outros LEDs desligados
    digitalWrite(pinoLedVerde,LOW);
    digitalWrite(pinoLedAmarelo,LOW);
  }

  //Verifica se o valor de leitura do potenciometro é maior que 340 e menor que 680 para acionar os LEDs vermelho e amarelo
  else if (valorPot <= 680 && valorPot>340) {
    //aciona o LED amarelo com brilho variável
    analogWrite(pinoLedAmarelo, map(valorPot, 340, 680, 0, 255));

    //Deixa o LED amarelo desligado e LED vermelho ligado
    digitalWrite(pinoLedVermelho,HIGH);
    digitalWrite(pinoLedVerde,LOW);
  }

  //Verifica se o valor de leitura do potenciometro é maior que 340 e menor que 680 para acionar os LEDs vermelho, amarelo e verde
  else if (valorPot > 680) {
    //aciona o LED verde com brilho variável
    analogWrite(pinoLedVerde, map(valorPot, 680, 1023, 0, 255));

    //Deixa os LEDs vermelho e LED amarelo ligado
    digitalWrite(pinoLedVermelho,HIGH);
    digitalWrite(pinoLedAmarelo,HIGH);
  }
  
  delay(100); 
}
