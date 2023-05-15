/*
 * Neste projeto, tem o acionamento de um LED piscante com PWM
 * Inicia o sistema com o acendimento gradual do LED e após o apagamento gradual do LED, e repete este ciclo
 * O tempo entre cada variação de brilho está em 30 milissegundos
 * A variação do dutycicle está de 5 em 5.
 */


//Declaração de variáveis globais
//Pino de acionamento do LED
int pinoLed = 11;

//Variável que armazena o valor do dutycicle do PWM.
int dutyPwm = 0;

////Variável que armazena o valor do tempo de variação do brilho.
int tempoDuty = 30;

void setup()
{
  pinMode(pinoLed, OUTPUT);
}

void loop()
{
  //Repetição que controla o acendimento gradual
  for (dutyPwm = 0; dutyPwm <= 255; dutyPwm += 5) {
    
    //Função que aciona o LED através do PWM e varia o brilho do LED
    analogWrite(pinoLed, dutyPwm);

    //Tempo de contagem dedicada como intervalo a cada variação do brilho
    delay(tempoDuty); 
  }

  //Repetição que controla o apagamento gradual
  for (dutyPwm = 255; dutyPwm >= 0; dutyPwm -= 5) {
    //Função que aciona o LED através do PWM e varia o brilho do LED
    analogWrite(pinoLed, dutyPwm);

    //Tempo de contagem dedicada como intervalo a cada variação do brilho
    delay(tempoDuty);
  }
}
