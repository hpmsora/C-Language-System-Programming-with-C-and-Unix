 /* Finding Maximum Porduct program */
 /* Array -> Array */
 /* CSCI-C 291 Won Yong Ha */

#include<stdio.h>

int gl_size = 0;

 /* declare Max_Product */
void Max_Product(int *a) {

 /* declare variables */
int size=sizeof(a);
int x;

 /* print the original input */
printf("Input: {");
for(x=0; x<gl_size; x++) {
printf(" %d", a[x]);
}
printf(" }\n");

 /* checking the array whether the size of array is 0 or not */
if(size>1) {

 /* declare variables for 'for' loop */
int res=a[0]*a[1];
int i, j, prod;
int ans[2];

 /* first 'for' loop increasing first variable 'i' */
for(i=0; i<size; i++) {
	 /* second 'for' loop increasing second variable 'j' */
	for(j=i+1; j<size; j++) {
		prod=a[i]*a[j]; // multiplying ith element and jth element
		 /* checking the bigger one */
		if(res<prod) {
			ans[0]=a[i];
			ans[1]=a[j];
			res=prod;
		}
	}
	 /* resetting variable 'j' */
	j=i+2;
}

 /* print the result */
printf("Output: { %d %d }\n", ans[0], ans[1]);
}

 /* print if the array size is 0 */
else
printf("The array has too less data!\n");
}

 /* main function */
int main(void) {
int el, f;
int arr[99];
 /* assigned arrays */
printf("How many elements: ");
scanf("%d", &el);
gl_size = el;
for(int i = 0; i < el; i++) {
	printf("Element %d : ", i+1); 
	scanf("%d", &f);
	arr[i] = f;
	} 
 /* active the function Max_Product */
Max_Product(arr);
return 0;
}
