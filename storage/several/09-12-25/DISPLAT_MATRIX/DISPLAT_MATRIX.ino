#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>


#define HARDWARE_TYPE MD_MAX72XX::FC16_HW   // definição do tipo de hardware
#define MAX_DEVICES 16 // Número de displays de leds a serem utilizados
#define PinDIN  11 //Pino DIN se conecta com a porta digital 11 do arduino
#define PinCS 10 //Pino CS se conecta com a porta digital 10 do arduino
#define PinCLK  13 //Pino CLK se conecta com a porta digital 13 do arduino

MD_Parola P = MD_Parola(HARDWARE_TYPE, PinCS, MAX_DEVICES); //Manda as informações definidas para a biblioteca 

void setup(){
  P.begin(); //Incia a comunicação de dados
  Serial.begin(9600);

}

String Texto(){
String c = "";
char letra ;
while(Serial.available() > 0){
  letra = Serial.read();
  if(letra != '\n')c.concat(letra);
  delay(2);
}
return c;
}

 String tela ="TEXTO PADRAO";
void loop(){
  if(Serial.available()>0){
    tela = Texto(); 
  }
  if (P.displayAnimate()) //será responsável por animar a tela com os parâmetros definidos no  “P.displayText”.
    P.displayText(tela.c_str(), PA_CENTER, 100, 1, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
     //Configura o texto que será exibido
}
