/* rpn.c */
#include <stdio.h>
#include <stdlib.h>

int main(void){
  int countNum = 0, didMean = 0;
  double num[100] = {0.0};
  char c;

  while(1){
    while((c = getchar()) != '\n'){
      if(c == '!'){
        return 0;
      }
      switch(c){
        case '+':
          if(countNum < 2){
            break;
          }
          num[countNum] = num[countNum-2] + num[countNum-1];
          //printf("%lf = %lf + %lf\n", num[countNum], num[countNum-2], num[countNum-1]);
          didMean = 1;
          break;
        case '-':
          if(countNum < 2){
            break;
          }
          num[countNum] = num[countNum-2] - num[countNum-1];
          //printf("%lf = %lf - %lf\n", num[countNum], num[countNum-2], num[countNum-1]);
          didMean = 1;
          break;
        case '*':
          if(countNum < 2){
            break;
          }
          num[countNum] = num[countNum-2] * num[countNum-1];
          //printf("%lf = %lf * %lf\n", num[countNum], num[countNum-2], num[countNum-1]);
          didMean = 1;
          break;
        case '/':
          if(countNum < 2){
            break;
          }
          num[countNum] = num[countNum-2] / num[countNum-1];
          //printf("%lf = %lf / %lf\n", num[countNum], num[countNum-2], num[countNum-1]);
          didMean = 1;
          break;
        case ' ':
          if(didMean){
            countNum++;
          }
          didMean = 0;
          break;
        default:
          if('0' <= c && c <= '9'){
            num[countNum] = num[countNum] * 10.0 + atoi(&c);
            //printf("%lf\n", num[countNum]);
            didMean = 1;
          }
          else{
            didMean = 0;
          }
          break;
      }
    }
    printf("res: %lf\n", num[countNum]);
    countNum++;
  }
}