//Declaração de variáveis globais
//Valor de armazenamento do PWM
int valorPwm = 0;

//Pino do potenciometro
int pinoPot = A0;

//Pino do LED
int pinoLed = 3;

void setup()
{
  pinMode(pinoPot, INPUT);
  pinMode(pinoLed, OUTPUT);
}

void loop()
{
  //Função map converte o valor de um intervalo para outro intervalo
  valorPwm = map(analogRead(pinoPot), 0, 1023, 0, 255);

  //Aciona LED com brilho variável relacionado a resistência do potenciometro
  analogWrite(pinoLed, valorPwm);

  //Contagem de tempo entre leitura de tensão do potenciômetro
  delay(100); 
}
