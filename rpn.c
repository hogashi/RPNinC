/* rpn.c */
#include <stdio.h>

int main(void){
	int i = 0, countNum = 0, countBuff = 0, didMean = 0;
	double num[100] = {0.0};
	char buff[100] = "";

	while(1){
		// get chars to buffer
		countBuff = 0;
		while((buff[countBuff] = getchar()) != ' ' && buff[countBuff] != '\n'){
			countBuff++;
		}
		// calcurate buffer
		for(i = 0; i < countBuff; i++){
			// '!' means end
			if(buff[i] == '!'){
				return 0;
			}
			// read each char
			switch(buff[i]){
				case '+':
					if(countNum < 2){
						break;
					}
					num[countNum] = num[countNum-2] + num[countNum-1];
					//printf("%lf = %lf + %lf\n", num[countNum], num[countNum-2], num[countNum-1]);
					break;
				case '-':
					if(countNum < 2){
						break;
					}
					num[countNum] = num[countNum-2] - num[countNum-1];
					//printf("%lf = %lf - %lf\n", num[countNum], num[countNum-2], num[countNum-1]);
					break;
				case '*':
					if(countNum < 2){
						break;
					}
					num[countNum] = num[countNum-2] * num[countNum-1];
					//printf("%lf = %lf * %lf\n", num[countNum], num[countNum-2], num[countNum-1]);
					break;
				case '/':
					if(countNum < 2){
						break;
					}
					num[countNum] = num[countNum-2] / num[countNum-1];
					//printf("%lf = %lf / %lf\n", num[countNum], num[countNum-2], num[countNum-1]);
					break;
				default:
					if('0' <= buff[i] && buff[i] <= '9'){
						// ((buff[i]) - ('0')) --- atoi
						num[countNum] = num[countNum] * 10.0 + ((buff[i]) - ('0'));
						//printf("%lf\n", num[countNum]);
					}
					break;
			}// end switch
		}// end for
		printf("= %lf\n", num[countNum]);
		countNum++;
	}// end while
}// end main
