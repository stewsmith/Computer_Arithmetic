#include <stdio.h>
#include <string.h>

/*Converts Decimal to Binary*/
void d2b(int num){
  int mod = 0;
  while (num != 0){
    mod = num%2;
    printf("%d", mod);
    num = num/2;
  }
    printf("\n");
}

void reverse(char s[])
{
      int length = strlen(s) ;
      int c, i, j;

      for (i = 0, j = length - 1; i < j; i++, j--)
     {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
      }
}

/*Converts Octal to Binary*/
char[] o2b(char raw[]){
  int len =strlen(raw);
  int i=0;
  char str[50];

  while(i < len){
    switch(raw[i]){
      case '0': strcat(str, "000");
                break;
      case '1': strcat(str, "001");
                break;
      case '2': strcat(str, "010");
                break;
      case '3': strcat(str, "011");
                break;
      case '4': strcat(str, "100");
                break;
      case '5': strcat(str, "101");
                break;
      case '6': strcat(str, "110");
                break;
      case '7': strcat(str ,"111");
                break;
      default: fprintf(stderr, "not octal");
    }
    i++;
  }
    printf("str: %s\n", str);
    return str;
}

/*Converts Hexadecimal to Binary*/
char[] x2b(char raw[]){
  int len =strlen(raw);
  int i=0;
  char str[50];

  while(i < len){
    switch(raw[i]){
      case '0': strcat(str, "0000");
                break;
      case '1': strcat(str, "0001");
                break;
      case '2': strcat(str, "0010");
                break;
      case '3': strcat(str, "0011");
                break;
      case '4': strcat(str, "0100");
                break;
      case '5': strcat(str, "0101");
                break;
      case '6': strcat(str, "0110");
                break;
      case '7': strcat(str, "0111");
                break;
      case '8': strcat(str,"1000");
                break;
      case '9': strcat(str, "1001");
                break;
      case 'A': strcat(str, "1010");
                break;
      case 'B': strcat(str, "1011");
                break;
      case 'C': strcat(str, "1100");
                break;
      case 'D': strcat(str, "1101");
                break;
      case 'E': strcat(str, "1110");
                break;
      case 'F': strcat(str, "1111");
                break;
      default: fprintf(stderr, "not hex");
    }
    i++;
  }
    printf("str: %s\n", str);
    return str;
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
     case 'd': printf("decimal format\n");
               /*decimal to binary*/
               firstForm++;
               firstFinal = atoi(firstForm);
               d2b(firstFinal);
               break;
     case 'o': printf("octal format\n");
               /*octal to decimal */
               firstForm++;
               o2b(firstForm);
               break;
     case 'b': printf("binary format\n");
               /*no conversion necessary */
               firstForm++;
               break;
     case 'x': printf("hexadecimal format\n");
               /*hexadecimal to decimal */
               firstForm++;
               x2b(firstForm);
               break;
     default: fprintf(stderr, "not a valid conversion base option");
              break;
   }

    switch(secForm[0])
   {
     case 'd': printf("decimal format\n");
               /*decimal to binary*/
               secForm++;
               secFinal = atoi(secForm);
               d2b(secFinal);
               break;
     case 'o': printf("octal format\n");
               /*octal to decimal */
               secForm++;
               o2b(secForm);
               break;
     case 'b': printf("binary format\n");
               /*no conversion necessary */
               secForm++;
               break;
     case 'x': printf("hexadecimal format\n");
               /*hexadecimal to decimal */
               secForm++;
               x2b(secForm);
               break;
     default: fprintf(stderr, "not a valid conversion base option");
              break;
   }
}
