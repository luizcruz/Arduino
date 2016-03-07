/*
* Desenhando temperatura no display (v1.0)
* Componentes: Display 0,96" 128 x 64 I2C SSD1206 
* Biblioteca: U8g - https://github.com/olikraus/u8glib/ 
* Autor: Luiz Cruz 
* 
*
* Wire:
* A5 - SDA
* A4 - SLC
*/


#include <U8glib.h>

 
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NO_ACK);
 
void draw() 
{
  //Fonte
  u8g.setFont(u8g_font_8x13B);
  
  //Temperatura 
  u8g.drawStr( 5, 15, "28");
  u8g.drawCircle(28,8,3);
  u8g.drawStr( 34, 15, "C");

  //Umidade
  u8g.drawStr( 90, 15, "75");
  u8g.drawStr( 110, 15, "%");
  
  //Nome
  //u8g_font_fub30
  u8g.setFont(u8g_font_ncenB24);
  u8g.drawStr( 10, 57, "Bebe");

  //Moldura
  u8g.drawRFrame(0,18, 128, 46, 2);
  
}
 
void setup(void) 
{
  Serial.begin(9600);
}
 
void loop(void) 
{
  //Loop
  u8g.firstPage();  
  do
  {
    draw();
  } while( u8g.nextPage() );
   
  delay(100);
}
