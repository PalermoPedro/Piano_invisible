//NOMBRE Y APELLIDO: Pedro Palermo
//FECHA: 20/11/2019
//LUGAR: Instituto TEKNE
//DESCRIPCION: Está maquina usa un sensor de sonido (HC-SR04) y un zumbador para crear un piano intangible que permita crear musica con nuestra mano.


//esta es la frecuencia a la que suenan las notas musicales
int nota_do = 277;
int nota_re = 293;
int nota_mi = 329;
int nota_fa = 349;
int nota_sol = 392;
int nota_la = 440;
int nota_si = 493;

//incluimos la libreria
#include <Ultrasonic.h>

/*ESQUEMA DE CONEXION
 * Utilizando un sensor HC-SR04 deben conectarse los pines de los extremos a (+) y (-)
 * y los dos pines del centro deben conectarse a los pines de la placa.
 * TRIG al pin 13
 * ECHO al pin 12
 */

int echo = 12;
int trig = 13;
int distanciaMax = 30000; //esta es la distancia que quiero medir, 30000 microsegundos son equivalentes a 5 metros

//creo el sensor y le paso los datos de configuración.

Ultrasonic sensor(trig,echo,distanciaMax);

int distancia = 0; //Declaro la variable que voy a utilizar para almacenar la distancia medida



void setup() { //En la funcion setup, escribo el codigo que quiero que se ejecute solo 1 vez al iniciar el sistema
  
Serial.begin(9600); // Inicializo el puerto serie
}



void loop() { //En la función loop, escirbo el codigo que quiero que se repita constantemente
  
  distancia = sensor.Ranging(CM);//Medimos la distancia y la guardamos en la variable
  Serial.println(distancia); //imprimo distancia en el monitor serial
  delay (50); //espero 50 ms entre cada vez que imprimo la distancia
  noTone (6);
  //realizo una prueba de sonido. quiero que suene la nota DO, cuando la distancia es menor a 15 centimetros
  if (distancia < 15){
    tone(6, nota_do);
  }
}
