/*
  SD Minimal.side

  Create test.txt, write characters in, read back out, display. 
  
  http://learn.parallax.com/propeller-c-simple-devices/sd-card-data
*/

#include "simpletools.h"                      // Include simpletools header    
#include <string.h>           //para comparar cadenas

char *str1; 
char s[15];
int comp;
FILE* fp;
int DO = 22, CLK = 23, DI = 24, CS = 25;

int main(){ 
  sd_mount(DO, CLK, DI, CS); 
                                         
  str1 = "";
  
  fp = fopen("P_Numeros.txt", "r");
  fread(s, 1, 15, fp);
  fclose(fp)
  
  print("texto en el archivo: %s \n", s);
  //print("texto guardado: %s \n", str1);
  
  comp = strcmp(str1, s);
  if(comp < 0){
    print("El texto esta iniciado, REPRODUCIENDO SECIENCIA");
  }
  else{
    print("El texto esta vacio, GUARDANDO SECUENCIA");
    fp = fopen("P_Numeros.txt", "w");
    fwrite("1 \n2 \n3 \n4 \n", 1, 15,fp);
    fclose(fp);
  }                                 
}    
