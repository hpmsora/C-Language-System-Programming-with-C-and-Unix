#include <stdio.h>
#include "student.h"
#include <string.h>

int stuid = 0;
char sid[10];
char nam[100];
char m1[10];
char m2[10];
char m3[10];
char to[10];

student inputStudent() {
student students;
strncpy(students.id, sid, 10);
strncpy(students.name, nam, 100);
strncpy(students.mark1, m1, 10);
strncpy(students.mark2, m2, 10);
strncpy(students.mark3, m3, 10);
strncpy(students.total, to, 10);
return students;
}

int main() {
FILE *fp;
student studentlist[10];
char c;
char a[99];
int type = 0;
int pos = 0;
fp = fopen("test.txt", "r");
while(1) {
	c = fgetc(fp);
	if (feof(fp)) {
		break;
		}
	if (c == '\n') {
		studentlist[stuid] = inputStudent();
		stuid++;
		type = 0;
		pos = 0;
		}
	else if (c == ' ') {
		pos = 0;
		type++;
		}
	else {
		if (type == 0) {
			sid[pos] = c;
			pos++;
			}
		else if(type == 1) {
			nam[pos] = c;
			pos++;
			}
		else if (type == 2) {
			m1[pos] = c;
			pos++;
			}
		else if (type == 3) {
			m2[pos] = c;
			pos++;
			}
		else if (type == 4) {
			m3[pos] = c;
			pos++;
			}
		else {
			to[pos] = c;
			pos++;
			}
		}
	}
fclose(fp);

int n;

printf("Enter number of records to be displayed: ");
scanf("%d", &n);
 int i;
 for(i = 0; i < n; i++) {
   student stu = studentlist[i];
   printf("%s", stu.id);
   printf(" %s", stu.name);
   printf(" %s", stu.mark1);
   printf(" %s", stu.mark2);
   printf(" %s", stu.mark3);
   printf(" %s\n", stu.total);
 }
return 0;
}
