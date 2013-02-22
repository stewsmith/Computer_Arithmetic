#include <stdio.h>
#include <string.h>

void main(int argc, char*argv[]){
    /*check arguments*/
    
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

    if (argc != 5){
      printf("Argc is off---should be 5");
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
               /*no conversion necessary */
               firstForm++;
               firstFinal = atoi(firstForm);
               printf("%d\n", firstFinal);
               break;
     case 'o': printf("octal format\n");
               /*octal to decimal */
               firstForm++;
               break;
     case 'b': printf("binary format\n");
               /*binary to decimal */
               firstForm++;
               break;
     case 'x': printf("hexadecimal format\n");
               /*hexadecimal to decimal */
               firstForm++;
               break;
     default: printf("not a valid conversion base option");
              break;
   }

    switch(secForm[0])
   {
     case 'd': printf("decimal format\n");
               /*no conversion necessary */
               secFinal = atoi(secForm);
               secForm++;
               if(addition)
                 add(firstFinal, secFinal);
               break;
     case 'o': printf("octal format\n");
               /*octal to decimal */
               secForm++;
               break;
     case 'b': printf("binary format\n");
               /*binary to decimal */
               secForm++;
               break;
     case 'x': printf("hexadecimal format\n");
               /*hexadecimal to decimal */
               secForm++;
               break;
     default: printf("not a valid conversion base option");
              break;
   }

  

    printf("argument 1: %s \nargument 2: %s\n", firstForm, secForm );
}

int add(int a, int b){
  return (a + b);
}
