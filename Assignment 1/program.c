#include<stdio.h>

int main(void)
{
int m, n, ori;
int sum=0, rest=0;
int sub_sum=1;
int i=1;
int a=1;

printf("Enter a number: ");
scanf("%d", &m);
ori = m;
rest = m;

while(sum<ori) {
	sum=0;
	while(rest>0){
		n=rest%10;
		rest=(rest-n)/10;
		sub_sum=1;
		while(a<=i) {
			sub_sum=n*sub_sum;
			a++;
		}
		a=1;
		sum+=sub_sum;
	}
	rest=ori;
	i++;
}

if(sum==ori)
	printf("%d is Armstrong number.\n", ori);
else
	printf("%d is not Armstrong number.\n", ori);
}
