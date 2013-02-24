#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Converts Decimal to Binary */
void d2b(char* bin, int num){
  int mod = 0;
  strcpy(bin, "");
  char b[100];

  while (num != 0){
    mod = num%2;
    /*char* modChar = (char*)(((int)'0')+mod);
    strcat(bin, modChar); */
    sprintf(bin, "%d", mod);
    num = num/2;
  }
  printf("d2b: %s\n", bin);
}

/*takes a string and reverses it */
char* reverse(char s[])
{
      int length = strlen(s) ;
      int c, i, j;

      for (i = 0, j = length - 1; i < j; i++, j--)
     {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
      }
      return s;
}

/*takes two strings of binary form and adds them*/
void binAdd(char sum[], char s1[], char s2[]){
  int carry = 0;
  char* rev1 = reverse(s1);
  char* rev2 = reverse(s2);
  int i;
  for(i=0; i< strlen(s1); i++){
    if(s1[i] == '1' && s2[i] == '1'){
      if(carry){
        carry = 1;
        strcat(sum, "1");
      }
      else{
        carry = 1;
        strcat(sum, "0");
      }
    }else{
      if((s1[i] == '0' && s2[i] == '1') || (s1[i] == '1' && s2[i] == '0')){
        if(carry){
          carry = 1;
          strcat(sum, "0");
        }else{
          carry = 0;
          strcat(sum, "1");
        }
      }else{
        if(s1[i] == '0' && s2[i] == '0'){
          if (carry){
            carry = 0;
            strcat(sum, "1");
          }else{
            carry = 0;
            strcat(sum, "0");
        }
      } 
    }
  }
}
if(carry)
  strcat(sum, "1");
}

/*Converts Octal to Binary*/
void o2b(char * bin, char raw[]){
  int len =strlen(raw);
  int i=0;
  strcpy(bin, "");

  while(i < len){
    switch(raw[i]){
      case '0': strcat(bin, "000");
                break;
      case '1': strcat(bin, "001");
                break;
      case '2': strcat(bin, "010");
                break;
      case '3': strcat(bin, "011");
                break;
      case '4': strcat(bin, "100");
                break;
      case '5': strcat(bin, "101");
                break;
      case '6': strcat(bin, "110");
                break;
      case '7': strcat(bin ,"111");
                break;
      default: fprintf(stderr, "not octal");
    }
    i++;
  }
}

/*Converts Hexadecimal to Binary*/
void x2b(char* bin, char raw[]){
  int len =strlen(raw);
  int i=0;
  strcpy(bin, "");

  while(i < len){
    switch(raw[i]){
      case '0': strcat(bin, "0000");
                break;
      case '1': strcat(bin, "0001");
                break;
      case '2': strcat(bin, "0010");
                break;
      case '3': strcat(bin, "0011");
                break;
      case '4': strcat(bin, "0100");
                break;
      case '5': strcat(bin, "0101");
                break;
      case '6': strcat(bin, "0110");
                break;
      case '7': strcat(bin, "0111");
                break;
      case '8': strcat(bin,"1000");
                break;
      case '9': strcat(bin, "1001");
                break;
      case 'A': strcat(bin, "1010");
                break;
      case 'B': strcat(bin, "1011");
                break;
      case 'C': strcat(bin, "1100");
                break;
      case 'D': strcat(bin, "1101");
                break;
      case 'E': strcat(bin, "1110");
                break;
      case 'F': strcat(bin, "1111");
                break;
      default: fprintf(stderr, "not hex");
    }
    i++;
  }
}


void main(int argc, char*argv[]){
    
    int addition = 0;
    int subtraction = 0;
    char * firstArg;
    char * secArg;
    char * firstForm;
    char * secForm;
    int negFirst = 0;
    int negSec = 0;
    int firstFinal = 0;
    int secFinal = 0;
    char * firstBin;
    char * secBin;

    /*check arguments*/
    if (argc != 5){
      fprintf(stderr, "Argc is off---should be 5");
      return;
    }
    
    if(strcmp(argv[1], "+") == 0)
      addition = 1;
    if(strcmp(argv[1], "-") == 0)
      subtraction = 1;
    
    firstArg = argv[2];
    secArg = argv[3];
    firstForm =  firstArg;   
    secForm = secArg;

    if(firstArg[0] == '-'){
      negFirst = 1;
      firstForm+=1;
    }
    if(secArg[0] == '-'){
      negSec = 1;
      secForm+=1;
    }

   switch(firstForm[0])
   {
     case 'd': /*decimal to binary*/
               firstForm++;
               firstFinal = atoi(firstForm);
               firstBin = (char*) malloc(3*(strlen(firstForm)));
               d2b(firstBin, firstFinal);
               break;
     case 'o': /*octal to decimal */
               firstForm++;
               firstBin = (char*) malloc(3*(strlen(firstForm)));
               o2b(firstBin, firstForm);
               break;
     case 'b': /*no conversion necessary */
               firstForm++;
               firstBin = firstForm;
               break;
     case 'x': /*hexadecimal to decimal */
               firstForm++;
               firstBin = (char*) malloc(4*(strlen(firstForm)));
               x2b(firstBin, firstForm);
               break;
     default: fprintf(stderr, "not a valid conversion base option\n");
              return;
   }

    switch(secForm[0])
   {
     case 'd': /*decimal to binary*/
               secForm++;
               secFinal = atoi(secForm);
               firstBin = (char*) malloc(3*(strlen(firstForm)));
               d2b(firstBin, firstFinal);
               break;
     case 'o': /*octal to decimal */
               secForm++;
               secBin = (char*) malloc(3*(strlen(secForm)));
               o2b(secBin, secForm);
               break;
     case 'b': /*no conversion necessary */
               secForm++;
               secBin = secForm;
               break;
     case 'x': /*hexadecimal to decimal */
               secForm++;
               secBin = (char*) malloc(4*(strlen(secForm)));
               x2b(secBin, secForm);
               break;
     default: fprintf(stderr, "not a valid conversion base option\n");
              return;
   }
   
  int diff;
  diff = abs(strlen(firstBin) - strlen(secBin));
  char* shorter;
  char* shorterBin;
  char* longerBin;

  if(diff > 0){
    if(strlen(firstBin) > strlen(secBin)){
      longerBin = firstBin;
      shorterBin = secBin;
      shorter = (char*) malloc(strlen(shorterBin));
    }
    else{
      longerBin = secBin;
      shorterBin = firstBin;
      shorter = (char*) malloc(strlen(shorterBin));
    }
    /* add zeros to the front of the shorter binary string 
    * so they can be compared */
    strcpy(shorter, "0");
    int k;
    for(k=0; k<diff-1; k++){
      strcat(shorter, "0");
    }
    strcat(shorter, shorterBin);
  }
  else{
    longerBin = firstBin;
    shorter = secBin;
  }
    
  printf("longerBin %s\n", longerBin);
  printf("shorter : %s\n", shorter);

  char * sum = (char*) malloc(2*(strlen(shorter)));
  binAdd(sum, longerBin, shorter);
  sum = reverse(sum);
  printf("sum: %s\n", sum);

}
