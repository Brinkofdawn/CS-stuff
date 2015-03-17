#include <stdio.h>
int main(){
int num,times,accum;
double average;
accum=0;
times=0;
num=0;
printf("\n type in a number then hit entering 9999 indicates add all numbers before 9999 \n");
while(num!=9999){
times++;
printf("number %d \n",times);
scanf("%d",&num);
accum=accum+num;}
average=(accum-9999)/(times-1);
printf("the average is %lf \n",average);
	return 0;
}