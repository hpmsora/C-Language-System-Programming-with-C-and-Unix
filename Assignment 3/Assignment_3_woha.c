#include<stdio.h>
#include <string.h>

//----------------------------------------------------------------------
//Helping functions

//The function multip is
// calculating pow.
// Int, Int -> Int
int multip(int x, int y) {
	int res = 1;
while(y>0) {
	res = res * x;
	y--;
	}
return res;
}

int hexato_tenth_help(char i) {
char hexa[16] = "0123456789abcdef";
int m = 0;
while(hexa[m] != i) {
	m++;
	}
return m;
}

int hexato_tenth(char *i, int lv) {
char hexa[16] = "0123456789abcdef";
if((int)strlen(i) - 1 <lv)
	return 0;
else
	return hexato_tenth_help((char)i[(int)strlen(i) - lv - 1]) + 16 * (hexato_tenth(i, (1 + lv)));
}

//The function anyto_tenth is
// changing any number base on any integer to number base on tenth.
// Int, Int, Int -> Int
int anyto_tenth(int rem, int num, int lev) {
if (rem != 0)
	return (rem%10) * multip(num, lev) + anyto_tenth((int)(rem/10), num, (lev + 1));
else 
	return 0;
}

//The function tenthto_any is
// changing the number base on tenth to number base on any integer.
// Int, Int, Int -> Int
int tenthto_any(int rem, int num, int lev) {
if (rem != 0) {
	return (rem%num) * multip(10, lev) + tenthto_any((int)(rem/num), num, (lev + 1));
}
else
	return 0;
}

//The function octa_add is
// adding two octal numbers in octal way
// Int, Int -> Int
int octa_add(int a, int b) {
if(a==0 && b==0)
	return 0;
else {
	int a1 = a%10;
	int b1 = b%10;
	int sum = a1 + b1;
	if(sum >= 8)
		return (sum - 8) + (10 * octa_add((int)(a/10 + 1), (int)(b/10)));
	else
		return sum + (10 * octa_add((int)(a/10), (int)(b/10)));
	}
}

//The function octa_multi_help is
// helping function of octa_multi function. It is only multiplying any integer with
// integer less than 8.
// Int, Int, Int -> Int
int octa_multi_help(int a, int b, int rem) {
if(a==0)
	return rem;
else {
	int sub = (a%10) * b + rem;
	if(sub>=8)
		return sub%8 + (10 * octa_multi_help((int)(a/10), b, (int)(sub/8)));
	else
		return sub + (10 * octa_multi_help((int)(a/10), b, 0));
	}
}

//The function octa_multi is
// multiplying two octal numbers in octal way
// Int, Int -> Int
int octa_multi(int a, int b) {
if(b==0) 
	return 0;
else {
	int mul = b%10;
	return octa_add(octa_multi_help(a, mul, 0), 10 * octa_multi(a, (int)(b/10)));
	}
}

//----------------------------------------------------------------------
//Main function
int main() {

//declare two integer variables
// a: first hexadecimal
// b: second hexadecimal
char a[99], b[99];
int ai, bi;
int addi, multi;

//receive two hexadecimals
printf("First hexadecimal: ");
gets(a);
printf("Second hexadecimal: ");
gets(b);

//making both received numbers to tenth base numbers
ai = hexato_tenth(a, 0);
bi = hexato_tenth(b, 0);

//change to octal numbers
ai = tenthto_any(ai, 8, 0);
bi = tenthto_any(bi, 8, 0);

// adding and multipling
addi = octa_add(ai, bi);
multi = octa_multi(ai, bi);

//print octal each numbers
printf("First number to octal: %d\n", ai);
printf("Second number to octal: %d\n", bi);

//print octal numbers added and multiplied
printf("Addition with octal: %d\n", addi);
printf("Multiplication with octal: %d\n", multi);

//print binary numbers added and multiplied
printf("Addition with binary: %d\n", tenthto_any(anyto_tenth(addi, 8, 0), 2, 0));
printf("Multiplication with binary: %d\n", tenthto_any(anyto_tenth(multi, 8, 0), 2, 0));
}