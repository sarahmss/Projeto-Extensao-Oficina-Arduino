/* Este código executa a automação de um semáforo com 3 LEDs. 
 *  Inicia com o LED vermelho aceso e os outros apagados.
 *  O sistema conta 10 segundos, e após apaga o LED vermelho e acende o LED verde.
 *  O sistema conta 10 segundos, depois apaga o LED verde e acende o LED amarelo.
 *  O sistema conta 3 segundos e o sistema se repete continuamente através da função loop.
*/

//Declaração de variáveis globais
//Definição do pino onde será conectado o jumper do LED vermelho.
int pinoLedVermelho = 4;

//Definição do pino onde será conectado o jumper do LED amarelo.
int pinoLedAmarelo = 3;

//Definição do pino onde será conectado o jumper do LED verde.
int pinoLedVerde = 2;

//Função principal do código. Nela as configurações do circuito são feitas.
void setup()
{
  //A função pinMode define o pino do LED vermelho como saída.
  pinMode(pinoLedVermelho, OUTPUT);

  //A função pinMode define o pino do LED amarelo como saída.
  pinMode(pinoLedAmarelo, OUTPUT);

  //A função pinMode define o pino do LED verde como saída.
  pinMode(pinoLedVerde, OUTPUT);
}

//Função que o sistema repete enquanto o Arduino estiver ligado. Inicia-se após a função setup.
void loop()
{
  //Função digitalWrite acende o LED vermelho
  digitalWrite(pinoLedVermelho, HIGH);
  //Função digitalWrite mantém apagado o LED amarelo
  digitalWrite(pinoLedAmarelo, LOW);
  //Função digitalWrite mantém apagado o LED verde
  digitalWrite(pinoLedVerde, LOW);

  //A função delay faz o sistema contar 10 segundos e mantém o sistema inalterado.
  //Tempo para a troca entre a luz vermelha e verde.
  delay(10000); 

  //Função digitalWrite apaga o LED vermelho.
  digitalWrite(pinoLedVermelho, LOW);

  //Função digitalWrite acende o LED verde.
  digitalWrite(pinoLedVerde, HIGH);

  //A função delay faz o sistema contar 10 segundos e mantém o sistema inalterado.
  //Tempo para a troca entre a luz verde e amarela.
  delay(10000);

  //Função digitalWrite apaga o LED verde.
  digitalWrite(pinoLedVerde, LOW);

  //Função digitalWrite que acende o LED amarelo.
  digitalWrite(pinoLedAmarelo, HIGH);

  //A função delay faz o sistema contar 3 segundos e mantém o sistema inalterado.
  //Tempo para a troca entre a luz amarela e vermelha.
  delay(3000);
}
