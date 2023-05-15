/*
 * Este código executa a automação de um semáforo com 3 LEDs, para a via principal, 2 LEDs para a via do pedestre, e 1 botão.
 * Inicia com o LED verde da via principal e o LED vermelho da via dos pedestres acesos e os outros apagados.
 * O sistema monitora o sinal do pino do botão. Quando o botão for apertado, o sinal altera para HIGH e o sistema detecta.
 * O sistema conta 3 segundos e apaga o LED verde da via principal e acende o LED amarelo da via principal.
 * O sistema conta 3 segundos e apaga o LED amarelo e acende o LED vermelho da via principal, apaga o LED vermelho e acende o LED verde da via de pedestre.
 * O sistema conta 15 segundos e o sistema se repete continuamente através da função loop.
*/

//Definição das variáveis globais
//Pinos do semáforo da via principal
//Pino do LED vermelho
int pinoLedVermelhoVia = 4;
//Pino do LED amarelo
int pinoLedAmareloVia = 3;
//Pino do LED verde
int pinoLedVerdeVia = 2;

//Pinos do semáforo da via de pedestres
//Pino do LED vermelho
int pinoLedVermelhoPedestre = 6;
//Pino do LED verde
int pinoLedVerdePedestre = 7;

//Pino do botão
int pinoBotao = 5;

//Função principal do código. Nela, os pinos são configurados.
void setup()
{
  //A função pinMode atribui o pino do LED vermelho como saída
  pinMode(pinoLedVermelhoVia, OUTPUT);
  //A função pinMode atribui o pino do LED amarelo como saída
  pinMode(pinoLedAmareloVia, OUTPUT);
  //A função pinMode atribui o pino do LED verde como saída  
  pinMode(pinoLedVerdeVia, OUTPUT);

  //A função pinMode atribui o pino do LED vermelho como saída
  pinMode(pinoLedVermelhoPedestre, OUTPUT);
  //A função pinMode atribui o pino do LED verde como saída  
  pinMode(pinoLedVerdePedestre, OUTPUT);
  
  //A função pinMode atribui o pino do botão como entrada
  pinMode(pinoBotao, INPUT);
}

    //Função que o sistema repete enquanto o Arduino estiver ligado. Inicia-se após a função setup
void loop()
{
  //Função que acenderá o LED verde da via
  digitalWrite(pinoLedVerdeVia, HIGH);
  //Função que manterá apagado o LED amarelo da via
  digitalWrite(pinoLedAmareloVia, LOW);
  //Função que manterá apagado o LED vermelho da via
  digitalWrite(pinoLedVermelhoVia, LOW);

  //Função que acenderá o LED vermelho do pedestre
  digitalWrite(pinoLedVermelhoPedestre, HIGH);
  //Função que manterá apagado o LED verde do pedestre
  digitalWrite(pinoLedVerdeVia, LOW);

  /*
   * Quando for pressionado, a tensão será 5V e retornará nivel HIGH na leitura e mudará o sinal do semáforo.
   * Quando não for pressionado o botão, a tensão será 0V e retornará nivel LOW, não mudando o sinal do semáforo
   */
  //Condicional que verá se o botão foi pressionado através da função digitalRead que lerá a tensão no pino do botão. 
  if (digitalRead(pinoBotao) == HIGH) {
    //Faz contagem do tempo para troca de sinal do semáforo entre verde e amarelo
    delay(3000); 
        //Função que apagará o pino do LED verde da via
        digitalWrite(pinoLedVerdeVia, LOW);
    
        //Função que acenderá o pino do LED amarelo da via
        digitalWrite(pinoLedAmareloVia, HIGH);
    
        //Faz contagem do tempo dedicada para troca de sinal do semáforo entre amarelo e vermelho
        delay(3000); 
    
        //Função que apagará o pino do LED amarelo da via
        digitalWrite(pinoLedAmareloVia, LOW);
    
        //Função que acenderá o pino do LED vermelho da via
        digitalWrite(pinoLedVermelhoVia, HIGH);

        //Função que apagará o LED vermelho do pedestre
        digitalWrite(pinoLedVermelhoPedestre, LOW);
        //Função que acenderá o LED verde do pedestre
        digitalWrite(pinoLedVerdePedestre, HIGH);

        // Faz contagem do tempo dedicada para retornar a repetição do loop e trocar de sinal do semáforo da via entre verde e vermelho.
        delay(15000); 
      }
    
      //Função que faz o sistema contar o tempo de forma dedicada em 100ms para melhor desempenho do protótipo evitando o efeito boucing
      delay(100);
    }
