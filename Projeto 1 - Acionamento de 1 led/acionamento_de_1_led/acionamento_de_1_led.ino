/*
 * Nesta prática, será utilizado um LED que pisca em 1 segundo.
 * É apresentado o conceito das funções básicas para o Arduino e o acionamento do LED
 * O sistema inicia com o LED ligado e conta 500milisegundos para após desligar o LED.
 * Depois o sistema conta 500milisegudos e liga o LED novamente e fica em repetição neste ciclo.
 */

//Declaração de variáveis globais
    
//Definição do pino do LED no Arduino
int pinoLed = 2; 

// tempo de troca de estado do LED.
int tempo = 500; 
  
//Função principal do código. Nela, os pinos são configurados
void setup() {
  
  //A função pinMode atribui o pino do LED como saída
  pinMode(pinoLed, OUTPUT);
}

//Função que o sistema repete enquanto o Arduino estiver ligado. Inicia-se após a função setup
void loop() {
  
 //A função digitalWrite insere no pino a tensão definida no parâmetro entre HIGH e LOW.
  digitalWrite(pinoLed, HIGH);  
  
  //A função delay faz a contagem de tempo indicada na função de forma dedicada no sistema, mantendo o sistema inalterado. Este tempo é definido para manter o LED ligado em milissegundos
  delay(tempo); 

 //A função digitalWrite insere na porta a tensão definida no parâmetro entre HIGH e LOW.
  digitalWrite(pinoLed, LOW);   
  
  //A função delay faz a contagem de tempo indicada na função de forma dedicada no sistema, mantendo o sistema inalterado. Este tempo é definido para manter o LED desligado em milissegundos.                       
  delay(tempo); 
}
