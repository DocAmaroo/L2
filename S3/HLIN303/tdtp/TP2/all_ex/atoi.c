#include <stdio.h>
int monatoi(char *s){
  int cumul=0, i=0;
  if (s==NULL) return 0;
  while(s[i]!='\0' && s[i]>='0' && s[i]<='9'){
    cumul=cumul*10+s[i]-'0';
    i++;
  }
  return cumul;
}
int main(int argc, char *argv[], char* env[]){
  if (argc!=2){
    fprintf(stderr,"Erreur de Syntaxe : %s 123\n", argv[0]);
    return 1;
  }
  printf("%s --> %d\n", argv[1],monatoi(argv[1]));
  return 0;
}
