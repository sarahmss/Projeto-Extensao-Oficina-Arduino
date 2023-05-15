/*
 * Neste projeto, será utilizado um display de 7 segmentos com cátodo comum usando a biblioteca Segment
 * Também será utilizado 3 LEDs para o semáforo da via e 2 LEDs para o semáforo de pedestres
 * Também usará 2 botões para o acionamento da parada da via.
 * É configurada todos os pinos do display através da biblioteca Segment.
 * Quando iniciado o sistema, o LED verde do semáforo da via liga, e o LED vermelho do semáforo dos pedestres liga também
 * Quando é apertado o botão, o sistema conta 3 segundos e desliga o LED vermelho e liga o LED amarelo da via.
 * O sistema conta mais 3 segundos e desliga o LED amarelo e liga o LED vermelho da via, e desliga o LED vermelho e liga o LED verde dos pedestres.
 * O sistema conta 10 segundos e em cada segundo o display mostrará o tempo restante a partir do 9
 * Quando chegar a 0, o display desliga, desliga o LED vermelho e acende o LED verde da via, e desliga o LED verde e acende o LED vermelho do pedestres.
*/

//Inclusão da biblioteca Segment para o display
#include <Segment.h>

//Declaração de variáveis globais
int pinoBotao = 12; // Pino de leitura do botão

//Semáforo da via principal
int pinoLedVerdeVia= 9; // Pino de acionamento do LED verde da via principal
int pinoLedAmareloVia= 10; // Pino de acionamento do LED amarelo da via principal
int pinoLedVermelhoVia= 11; // Pino de acionamento do LED vermelho da via principal

//Pinos exclusivos do Arduino Mega e Due
//Semáforo de pedestre
int pinoLedVermelhoPedestre= 22; // Pino de acionamento do LED vermelho da via principal
int pinoLedVerdePedestre= 24 ; // Pino de acionamento do LED verde da via principal

//Instanciado o objeto sevseg da biblioteca Segment. 
//Com ele, foi declarado os pinos do display na ordem das letras e o true indica que o display é de cátodo comum
//Caso o display seja de ânodo comum, trocar o atributo true por false
Segment sevseg(2, 3, 4, 5, 6, 7, 8, true);
                  
// Função principal de configuração do sistema
void setup()
{  
  //Atribuição do pino do botão como entrada
  pinMode(pinoBotao, INPUT);

  //Atribuição do pino do botão como entrada
  pinMode(pinoLedVerdeVia, OUTPUT);

  //Atribuição do pino do botão como saída
  pinMode(pinoLedAmareloVia, OUTPUT);

  //Atribuição do pino do botão como saída
  pinMode(pinoLedVermelhoVia, OUTPUT);

  //Atribuição do pino do botão como saída
  pinMode(pinoLedVermelhoPedestre, OUTPUT);

  //Atribuição do pino do botão como saída
  pinMode(pinoLedVerdePedestre, OUTPUT);

  //Início do sistema dos semáforos
  //Acendimento do LED verde do semáforo da via
  digitalWrite(pinoLedVerdeVia,HIGH);
  //Acendimento do LED vermelho do semáforo do pedestre
  digitalWrite(pinoLedVermelhoPedestre,HIGH);
  
}

// Função de repetição contínua do sistema
void loop()
{
  //Condicional que verifica o estado do Botão. Se o botão for pressionado, mudará o sinal para amarelo
  if (digitalRead(pinoBotao) == HIGH) {
    delay(3000); //Contagem do tempo dedicada em espera para troca do sinal para amarelo
    digitalWrite(pinoLedVerdeVia,LOW); //Desligar LED verde do semaforo da via
    digitalWrite(pinoLedAmareloVia,HIGH); //Ligar o LED amarelo do semaforo da via
    
    delay(3000);//Contagem do tempo dedicada em espera para troca do sinal para amarelo
    digitalWrite(pinoLedAmareloVia,LOW); //Desligar o LED amarelo do semaforo da via
    digitalWrite(pinoLedVermelhoVia,HIGH); //Ligar o LED vermelho do semaforo da via
    digitalWrite(pinoLedVermelhoPedestre,LOW); //Desligar o LED vermelho do semaforo de pedestre
    digitalWrite(pinoLedVerdePedestre,HIGH); //Ligar o LED verde do semaforo de pedestre

    //Repetição que faz a contagem do tempo e aciona o display
    for(int i=9;i>=0;i--){
      //Conversão de variável do int para char para a função da biblioteca
      char teste;
      sprintf(teste,"%d",i); 

      //Acionamento do display com valor do tempo restante
      sevseg.display(teste);
      contar--;
      
      delay(1000); // Contagem de tempo em 1 segundo para exibição do tempo restante
    }
  
  digitalWrite(pinoLedVermelhoVia,LOW); //Desligar LED vermelho do semaforo da via
  digitalWrite(pinoLedVerdePedestre,LOW); //Desligar LED verde do semaforo do pedestre
  
  digitalWrite(pinoLedVerdeVia,HIGH); //Ligar LED verde do semaforo da via
  digitalWrite(pinoLedVermelhoPedestre,HIGH); //Ligar LED vermelho do semaforo do pedestre

  //Desliga o display
  sevseg.clear();

  }
  
  delay(100); // Contagem de tempo dedicada para melhor desempenho do protótipo evitando o efeito boucing
}
