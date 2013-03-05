#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

/*Conversts Binary to Decimal*/
int b2d(char bin[]){
  bin = reverse(bin);/*may need to delete */
  int ans = 0;
  int i;
  for(i=0; i<strlen(bin); i++){
    if(bin[i] == '1'){
      ans += pow(2,i);
    }
  }
  bin = reverse(bin);
  return ans;
}

/*Conversts Binary to Decimal--Two's Complement*/
int neg_b2d(char bin[]){
  bin = reverse(bin); /*may need to delete */
  int ans = 0;
  int i;
  for(i=0; i<strlen(bin)-1; i++){
    if(bin[i] == '1'){
      ans += pow(2,i);
    }
  }
  ans -= pow(2, (strlen(bin)-1));
  bin = reverse(bin);
  return ans;
}

typedef union {
  int integer;
  float flt;
}Number;

/*Main Method */
void main(int argc, char*argv[]){

    /*check arguments*/
    if (argc != 3){
      fprintf(stderr, "Argc is off---should be 3\n");
      return;
    }

    /*check if binary num is 32 bits */
    if(strlen(argv[1]) != 32){
        fprintf(stderr, "ERROR: Binary number must be 32 bits\n");
        return;
    }

    char* binary = argv[1];
    /*Check if agrv[2] is int or float */
    Number output;
    if(strcmp(argv[2] , "int") == 0 || strcmp(argv[2] , "float") == 0){
     while (*binary){
      output.integer = (output.integer << 1) | (*binary == '1');
      binary ++;
     }
    }
    else{
        fprintf(stderr, "ERROR: Can only use float and int\n");
        return;
      }
   if( strcmp(argv[2] , "int") == 0){ 
     printf("output %d\n", output.integer);
   }
   else{
     printf("output %f\n", output.flt);
   }
    
    /*check if binary number is negative */
    int negative = 0;
    if(binary[strlen(binary)-1] == '1'){
      negative = 1;
    }
}

/*
    int ans;
    int mantissa;
    int exponent;
    if(integer){  binary num is integer
      if(negative){
        ans = neg_b2d(binary);
      }
      else{
        ans = b2d(binary);
      }
      printf("Answer: %d\n", ans);
    }
    else if(floater){  binary num is float 
     char* mant = (char*) malloc(23);
     char* expon = (char*) malloc(23);
     strcpy(mant, "");
     strcpy(expon, "");
     char test[9];
     int k;
     int b;
     for(k=0; k<23; k++){
       char temp = binary[k];
       strcat(mant, &temp);
     }
     int a=0;
     for(b=23; b<31; b++){
       test[a] = binary[b];
       a++;
     }
     test[a] = '\0';
     strcat(expon, test); 

     exponent = b2d(expon)-127;
     mantissa = b2d(mant);
    }
  printf("exponent: %d\n", exponent);
  printf("mantissa: %d\n", mantissa);
*/

