
volatile int pulses = 0; //pulsos contados
unsigned int rpm = 0; //revoluciones por minuto
float velocity = 0; //velocidad calculada
unsigned long timeold = 0;  // Tiempo 
unsigned int pulsesperturn = 12; // Número de muescas que tiene el disco del encoder.
const int wheel_diameter = 64;   // Diámetro de la rueda pequeña[mm]
static volatile unsigned long debounce = 0; // Tiempo del rebote


const int pinInterrupcion_1 = D5; 


void setup() {
  Serial.begin(9600);
  pinMode(pinInterrupcion_1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinInterrupcion_1), sensor4, CHANGE); //Mide el flanco de subida se puede camabiar por CHANGE para aunmetar la cantidad de pulos por vuelta
  pulses = 0;
  rpm = 0;
  timeold = 0;


}

void loop() {
  Serial.print("Contador pulsos - > ");
  Serial.println(pulses);
 // Serial.print("RPM -> ")
 // Serial.println()

  //if (millis() - timeold >= 1000){  // Se actualiza cada segundo
 // noInterrupts(); 

  //rpm = (60 * 1000 / pulsesperturn )/ (millis() - timeold)* pulses; // Calculamos las revoluciones por minuto
  //velocity = rpm * 3.1416 * wheel_diameter * 60 / 1000000; // Cálculo de la velocidad en [Km/h]
  //timeold = millis(); // Almacenamos el tiempo actual.
  //Serial.print(millis()/1000); Serial.print("       ");// Se envia al puerto serie el valor de tiempo, de las rpm y los pulsos.
  //Serial.print(rpm,DEC); Serial.print("       ");
  //Serial.print(pulses,DEC); Serial.print("       ");
  //Serial.println(velocity,2);
  //pulses = 0;  // Inicializamos los pulsos.
  //interrupts(); // Restart the interrupt processing // Reiniciamos la interrupción

 // }

}

  ICACHE_RAM_ATTR void sensor4(){

    if(  digitalRead (pinInterrupcion_1) && (micros()-debounce > 500) && digitalRead (pinInterrupcion_1) ) {

// Vuelve a comprobar que el encoder envia una señal buena y luego comprueba que el tiempo es superior a 1000 microsegundos y vuelve a comprobar que la señal es correcta.

         debounce = micros(); // Almacena el tiempo para comprobar que no contamos el rebote que hay en la señal.

    pulses++;}  // Suma el pulso bueno que entra.

    else ;

  }