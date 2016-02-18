#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int num;
	int result;
int sub;
int i;
int temp;
printf("enter number\n");
scanf("%d",&num);

for(i=5;i>0;i--){
	sub=(int)pow(10,i-1);
	result=num % (int)pow(10,i);//removes one digit from num when i decreases
temp=result/sub;//since it is integer division it truncate the remaining digits
	printf("%d ",temp);
}
return 0;
}
