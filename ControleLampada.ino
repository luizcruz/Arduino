/*

* Controlando a lampada por proximidade
* Componentes: Luminaria de escritorio, Rele (Modulo Rele v.1.0 - MPA-S-105-C), Arduino Duemilanove ou equivalente e sensor ultrassom (HC-SR04)
* Autor: Luiz Cruz (Revista INFO)
* 
*/


//Variaveis que definem os pinos de conexao
int trigPin = 5;
int echoPin = 6;
int relePin = 9;
bool state = false;

// Variaveis para calculo da distancia
long duration, inches, x;
int i;

void setup(){
  
  // Inicializacao
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relePin, OUTPUT);
    
}

void loop(){
  
  // O ultrasom inicializa com pulso em alta por 2 ou mais microsegundos 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);

  // Duracao da ida e volta do sinal resulta no calculo da distancia 
  duration = pulseIn(echoPin, HIGH);
  x = microsecondsToCentimeters(duration);
  
  // Logica de ativacao
  if (x < 30) {
    
    //Distancia menor que 30 cm, verifica estado
    
    if (state == 0){
        //Desliga lampada
        digitalWrite(relePin, HIGH);
        Serial.print(state);
        state = true;
    }
    else{
        // Liga a lampada
        digitalWrite(relePin, LOW); 
        Serial.print(state);
        state = false;       
    }
     
  }
  
  // Imprime no console a distancia (conferir ativacao do sensor ultrasom)
  Serial.print("\nDistancia = ");
  Serial.print(x);
  Serial.print(" cm ");
  Serial.println();
  delay(500);
}


long microsecondsToCentimeters(long microseconds){
 
  // Velocidade do som e 360 m/s ou 29 microsegundos por centimetro. A distancia e metade do percurso. 
  return microseconds / 29 / 2;
}
