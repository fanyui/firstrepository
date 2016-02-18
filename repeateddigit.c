#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int main(){
bool digit_seen[10]={false};
int digit;
long n;
printf("input a digit\n");
scanf("%ld",&n);
while(n>0){

	digit=n%10;
	if(digit_seen[digit]){
		printf(" %d",digit);
		}
	digit_seen[digit]=true;
	n/=10;
if(n<10)
break;
}
if(n>0){
printf("repeated digit\n");
//printf("%ld\n",n);
}
else printf("no repeated digits\n");
return 0;
}
