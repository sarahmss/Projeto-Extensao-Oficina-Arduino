//Declaração de variáveis globais
//Pinos do RGB
int pinoLedVermelho = 6;
int pinoLedAzul = 5;
int pinoLedVerde = 3;

int tempo = 1000;

void setup()
{
  pinMode(pinoLedVermelho, OUTPUT);
  pinMode(pinoLedAzul, OUTPUT);
  pinMode(pinoLedVerde, OUTPUT);
}

void loop()
{
  //Função que aciona o vermelho do RGB através do PWM
  //Cor vermelha
  analogWrite(pinoLedVermelho, 255);
  analogWrite(pinoLedVerde, 0);
  analogWrite(pinoLedAzul, 0);
  delay(tempo); 

  //Função que aciona o azul do RGB através do PWM
  //Cor azul
  analogWrite(pinoLedVermelho, 0);
  analogWrite(pinoLedVerde, 0);
  analogWrite(pinoLedAzul, 255);
  delay(tempo);

  //Função que aciona o verde do RGB através do PWM
  //Cor verde
  analogWrite(pinoLedVermelho, 0);
  analogWrite(pinoLedVerde, 255);
  analogWrite(pinoLedAzul, 0);
  delay(tempo); 

  //Função que aciona o vermelho e verde do RGB através do PWM
  //Cor amarela
  analogWrite(pinoLedVermelho, 255);
  analogWrite(pinoLedVerde, 255);
  analogWrite(pinoLedAzul, 0);
  delay(tempo); 

  //Função que aciona o vermelho e azul do RGB através do PWM
  //Cor magenta
  analogWrite(pinoLedVermelho, 255);
  analogWrite(pinoLedAzul, 255);
  analogWrite(pinoLedVerde, 0);  
  delay(tempo); 

  //Função que aciona o azul e verde do RGB através do PWM
  //Cor ciano
  analogWrite(pinoLedVermelho, 0);
  analogWrite(pinoLedVerde, 255);
  analogWrite(pinoLedAzul, 255);
  delay(tempo); 

  //Função que aciona o vermelho, verde e azul do RGB através do PWM
  //Cor branca
  analogWrite(pinoLedVermelho, 255);
  analogWrite(pinoLedVerde, 255);
  analogWrite(pinoLedAzul, 255);
  delay(tempo); 

  //Função que apaga o vermelho, verde e azul do RGB através do PWM
  //Apagado
  analogWrite(pinoLedVermelho, 0);
  analogWrite(pinoLedVerde, 0);
  analogWrite(pinoLedAzul, 0);
  delay(tempo); 
}
