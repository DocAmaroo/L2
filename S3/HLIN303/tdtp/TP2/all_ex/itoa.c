#include <stdio.h>
#include <string.h>

/** convertit un entier en chaîne de char le représentant en base 10
 *@param i une entier positif
 *@param s un ptr sur un tableau de char suffisament grand
 *@return NULL si i est négatif, s sinon
 */
char* itoa(int i, char *s){ /* s : un ptr sur une zone suffisament grande */
  if (i<0){
    return NULL;
  }
  else if (i<10){
    s[0]=i+'0';
    s[1]='\0';
  }else{
    char unite=i%10+'0';
    int l=strlen(itoa(i/10,s));
    s[l]=unite;
    s[l+1]='\0';
  }
  return s;
}
int main(int argc, char *argv[], char *env[]) {
  char s[256];
  for(int i=0;i<3000;i+=485){
    printf("L'entier %i est convertie en la chaine %s !\n", i,itoa(i,s)); 
  }
  return 0;			/* OK */
}
