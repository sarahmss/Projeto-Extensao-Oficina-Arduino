//Declaração de variáveis globais
//Armazena o valor de leitura do potenciômetro
int leituraPot = 0;
//Armazena o valor de medido de tensão do potenciômetro
float tensaoPot = 0;

//pino de leitura do potenciômetro
int pinoPot = A0;

void setup()
{
  pinMode(pinoPot, INPUT);
  
  //Inicia a comunicação com o Arduino com velocidade de 9600 bits/segundo
  Serial.begin(9600);

}
void loop()
{
  //A função analogRead faz a leitura analógica do pino com ADC.
  leituraPot = analogRead(pinoPot);

  //Apresenta o valor da variável no monitor serial e pula para próxima linha.
  Serial.print("Valor leitura do ADC: ");
  Serial.println(leituraPot);
  
  //Conversão para o valor de tensão
  tensaoPot = leituraPot*0,00488;

  //Apresenta o valor da variável no monitor serial e pula para próxima linha.
  Serial.print("Tensão medida no potenciômetro");
  Serial.println(tensaoPot);

  //Contagem de tempo dedicada entre cada leitura do potenciômetro
  delay(200); 

}
