/*
  Este código acionará o LED a partir de um botão push.
  A leitura do estado do botão será feita via pino digital através da função digitalRead.
  Quando o botão for pressionado, o LED se acenderá e a variável estado LED mudará, e assim, guardando a informação se o LED está aceso ou não.
*/

//Declaração de variáveis globais

//Armanzenamento do estado do LED entre ligado e desligado
int estadoLed = 0;

//Definição do pino onde será conectado o jumper do LED no Arduino
int pinoLed=3;

//Definição do pino onde será conectado o jumper do botão no Arduino
int pinoBotao = 2;

//Função principal do Arduino. Nela as configurações são feitas.
void setup()
{
  //A função pinMode define o pino do botão como entrada
  pinMode(pinoBotao, INPUT);

  //A função pinMode define o pino do LED como saída
  pinMode(pinoLed, OUTPUT);
}

//Função que o sistema repete enquanto o Arduino estiver ligado. Inicia-se após a função setup
void loop()
{
  /*Condicional de quando o botão for pressionado
   * Quando o botão for pressionado pelo usuário, a porta ficará em estado HIGH, e a condição será verdadeira
   * Quando o botão for solto, a porta volta ao estado LOW e a condição será falsa.
   * Quando a condicional é verdadeira, ela executa as instruções dadas no if
   * Quando a condicional é falsa, ela executa as instruções dadas no else.
   */

  // A função digitalRead lê a tensão em sua porta, e retorna HIGH quando a tensão é 5V, ou LOW quando a tensão for 0V.
  if (digitalRead(pinoBotao) == HIGH) {
    
    //Condicional do estado do LED verificando se está HIGH ou LOW.
    if (estadoLed == HIGH) {
      //Se o LED estiver ligada

      //A função digitalWrite insere na porta a tensão definida no parâmetro. 
      //Quando HIGH, o Arduino chaveia para 5V na porta; e quando LOW o Arduino chaveia para o 0V, ou GND.
      //Desligar o LED
      digitalWrite(pinoLed, LOW);
      
      //Altera a variável estadoLed para desligado
      estadoLed = LOW;
    } else {
      //Se não estiver ligado, estará desligado
      
      //Ligar o Led
      digitalWrite(pinoLed, HIGH);

      //Altera variável estadoLed para ligado
      estadoLed = HIGH;
    }
  }

  //Função que faz o sistema contar o tempo de forma dedicada em 100ms para melhor desempenho do protótipo evitando o efeito boucing
  delay(100); 
}
