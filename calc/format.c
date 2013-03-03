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

/*Main Method */
void main(int argc, char*argv[]){

    /*check arguments*/
    if (argc != 3){
      fprintf(stderr, "Argc is off---should be 3\n");
      return;
    }

    /*Check if agrv[2] is int or float */
    int integer = 0;
    int floater = 0;
    if(strcmp(argv[2] , "int") == 0)
      integer = 1;
    else{
      if(strcmp(argv[2] , "float") == 0)
        floater = 1;
      else fprintf(stderr, "Can only use float and int");
    }

    char* binary = argv[1];
    /*check if binary number is negative */
    int negative = 0;
    if(binary[strlen(binary)-1] == '1'){
      negative = 1;
    }

    int ans;
    if(negative){
      ans = neg_b2d(binary);
    }
    else{
    ans = b2d(binary);
    }
    printf("Answer: %d\n", ans);
}

