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

/*Converts Decimal to Binary */
void d2b(char* bin, int num){
  int mod = 0;
  strcpy(bin, "");

  while (num != 0){
    mod = num%2;
    if(mod){
      strcat(bin, "1");
    }else{
      strcat(bin, "0");
    }
    num = num/2;
  }
  strcat(bin, "\0");
  reverse(bin);
}

/*Conversts Binary to Decimal*/
int b2d(char bin[]){
  bin = reverse(bin);
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

/*takes two binary strings and does subtraction*/
void binSub(char sum[], char b[], char s[]){
  char* rev1 = reverse(b);
  char* rev2 = reverse(s);
  int i;
  for(i=0; i< strlen(b); i++){
    if(b[i] == '0' && s[i] == '0'){  /* 0 - 0 */
      strcat(sum, "0");
    }else if(b[i] == '1' && s[i] == '1'){  /* 1 - 1 */
      strcat(sum, "0");
    }else if(b[i] == '1' && s[i] == '0'){  /* 1 - 0 */
      strcat(sum, "1");
    }else if(b[i] == '0' && s[i] == '1'){ /* 0 - 1 (hard case) */
      int k = i;
      while(b[k] != '1'){
        b[k] = '1';
        k++;
      }
      b[k] = '0';
      strcat(sum, "1");
    }
  }
  sum = reverse(sum);
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

/*converts binary to octal */
void b2o(char * ans, char raw[]){
  raw = reverse(raw);
  int len = strlen(raw);
  int i;
  int j =0;
  strcpy(ans, "");

  if(len%3 != 0){
    for(i=0; i<(3-(len%3)); i++){
      strcat(raw, "0");
    }
  }
  raw = reverse(raw);
  while(j<len){
    char subbuff[3];
    memcpy(subbuff, &raw[j], 3);
    if(strcmp(subbuff, "000") == 0)
          strcat(ans, "0");
    else if(strcmp(subbuff, "001") == 0){
          strcat(ans, "1");
    } else if(strcmp(subbuff, "010") == 0){
          strcat(ans, "2");
    } else if(strcmp(subbuff, "011") == 0){
          strcat(ans, "3");
    } else if(strcmp(subbuff, "100") == 0){
          strcat(ans, "4");
    } else if(strcmp(subbuff, "101") == 0){
          strcat(ans, "5");
    } else if(strcmp(subbuff, "110") == 0){
          strcat(ans, "6");
    } else if(strcmp(subbuff, "111") == 0){
          strcat(ans, "7");
    }
    j+=3;
  }
  printf("ans: %s\n", ans);
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
      case '8': strcat(bin, "1000");
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


/* Converts Binary to Hexadecimal */
void b2x(char * ans, char raw[]){
  raw = reverse(raw);
  int len = strlen(raw);
  int i;
  int j =0;
  strcpy(ans, "");

  if(len%4 != 0){
    for(i=0; i<(4-(len%4)); i++){
      strcat(raw, "0");
    }
  }
  raw = reverse(raw);
  while(j<len){
    char subbuff[5];
    memcpy(subbuff, &raw[j], 4);
    subbuff[4] = '\0';
    int k;
    if(strcmp(subbuff, "0000") == 0) {
      strcat(ans, "0");
    } else if(strcmp(subbuff, "0001") == 0) {
            strcat(ans, "1");
    } else if(strcmp(subbuff, "0010") == 0) {
            strcat(ans, "2");
    } else if(strcmp(subbuff, "0011") == 0){
            strcat(ans, "3");
    } else if(strcmp(subbuff, "0100") == 0){
            strcat(ans, "4");
    } else if(strcmp(subbuff, "0101") == 0){
            strcat(ans, "5");
    } else if(strcmp(subbuff, "0110") == 0){
            strcat(ans, "6");
    } else if(strcmp(subbuff, "0111") == 0){
            strcat(ans, "7");
    } else if(strcmp(subbuff, "1000") == 0){
            strcat(ans, "8");
    } else if(strcmp(subbuff, "1001") == 0){
            strcat(ans, "9");
    } else if(strcmp(subbuff, "1010") == 0){
            strcat(ans, "A");
    } else if(strcmp(subbuff, "1011") == 0){
            strcat(ans, "B");
    } else if(strcmp(subbuff, "1100") == 0){
            strcat(ans, "C");
    } else if(strcmp(subbuff, "1101") == 0){
            strcat(ans, "D");
    } else if(strcmp(subbuff, "1110") == 0){
            strcat(ans, "E");
    } else if(strcmp(subbuff, "1111") == 0){
            strcat(ans, "F");
    } else {
      printf("failure\n");
    }
    j+=4;
  }
  printf("ans: %s\n", ans);
}


/*Main Method */
void main(int argc, char*argv[]){
    
    int addition = 0;
    int subtraction = 0;
    int mult = 0;
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
      fprintf(stderr, "Argc is off---should be 5\n");
      return;
    }
   
   /*Check for addition and subtraction*/ 
    char sign = *argv[1];
    switch (sign){
      case '+': addition = 1;
                break;
      case '-': subtraction = 1;
                break;
      case '*': mult = 1;
                break;
      default: fprintf(stderr, "Only addition, subtraction and multiplication allowed\n");
    }

    firstArg = argv[2];
    secArg = argv[3];
    firstForm =  firstArg;
    secForm = secArg;

    /*check for negatives*/
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
     case 'o': /*octal to binary */
               firstForm++;
               firstBin = (char*) malloc(3*(strlen(firstForm)));
               o2b(firstBin, firstForm);
               break;
     case 'b': /*no conversion necessary */
               firstForm++;
               firstBin = firstForm;
               break;
     case 'x': /*hexadecimal to binary */
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
               secBin = (char*) malloc(3*(strlen(secForm)));
               d2b(secBin, secFinal);
               break;
     case 'o': /*octal to binary */
               secForm++;
               secBin = (char*) malloc(3*(strlen(secForm)));
               o2b(secBin, secForm);
               break;
     case 'b': /*no conversion necessary */
               secForm++;
               secBin = secForm;
               break;
     case 'x': /*hexadecimal to binary */
               secForm++;
               secBin = (char*) malloc(4*(strlen(secForm)));
               x2b(secBin, secForm);
               break;
     default: fprintf(stderr, "not a valid conversion base option\n");
              return;
   }
   
/*
  int diff;
  diff = abs(strlen(firstBin) - strlen(secBin));
  char* shorter;
  char* shorterBin;
  char* longerBin;
  * if strings are different lengths,
   *  we must do some adjusting*
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
    * add zeros to the front of the shorter binary string 
    * so they can be compared *
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

  if (addition){
    binAdd(sum, longerBin, shorter);
    sum = reverse(sum);
    printf("binSum: %s\n", sum);
  }
  if (subtraction){
    binSub(sum, longerBin, shorter);
    printf("Subtraction sum: %s\n", sum); 
  }
*/

  /*decimal aritmatic*/
  int decAns = 0;
  if (addition){
    if(negFirst){
      decAns += -1*b2d(firstBin);
    }else{
      decAns += b2d(firstBin);
    }
    if(negSec){
      decAns += -1*b2d(secBin);
    }else{
      decAns += b2d(secBin);
    }
  }else{
  if (subtraction){
    if(negFirst){
      int addme = -1*b2d(firstBin);
      decAns = decAns + addme;
      
    }else{
      decAns += b2d(firstBin);
    }
    if(negSec){
      int addme = -1*b2d(secBin);
      decAns = decAns - addme;
    }else{
      decAns -= b2d(secBin);
    }
  }else{
    if (mult){
     printf("need to complete multiplication"); 
    }
  }
  }
/*convert to final output form*/
  char * ans = (char*) malloc(2*(strlen(firstBin)));
  char * temp = (char*) malloc(2*(strlen(firstBin)));
  char output = *argv[4];
  switch (output){
    case 'd': /*no conversion necessary*/
              printf("Answer: %d\n", decAns);
              break;
    case 'o': /*binary to octal*/
              d2b(temp, decAns);
              b2o(ans, temp);
              printf("Answer: %s\n", ans);
              break;
    case 'x': /*binary to hexadecimal*/
              d2b(temp, decAns);
              b2x(ans, temp);
              printf("Answer: %s\n", ans);
              break;
    case 'b': /*decimal to binary*/
              d2b(ans, decAns);
              printf("Answer: %s\n", ans);
              break;
    default: fprintf(stderr, "not a valid conversion output");
  }

}
