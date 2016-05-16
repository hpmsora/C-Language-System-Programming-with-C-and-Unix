#include <stdio.h>
#include <string.h>
#include "student.h"
#include "operations.c"

// declaration of common variable
int num_stu;
int opt;
int curr_stu;
int num;
char str[100];
struct student studentlist[100];

//naming function
// fixing name of each data set
void naming() {
printf("Enter student name: ");
scanf("%s", studentlist[curr_stu].personal.name);
}

//contacting function
// fixing contact number of each data set.
void contacting() {
printf("Enter student contact number: ");
scanf("%d", &num);
studentlist[curr_stu].personal.contact = num;
}

//addressing function
// fixing address of each data set.
void addressing() {
printf("Enter student address: ");
scanf("%s", studentlist[curr_stu].personal.address);
}

//assignmenting function
// fixing assignment score of each data set.
void assignmenting() {
printf("Enter student assignment score: ");
scanf("%d", &num);
studentlist[curr_stu].university.assignment = num;
}

//mid_terming function
// fixing mid term score of each data set.
void mid_terming() {
printf("Enter student mid term score: ");
scanf("%d", &num);
studentlist[curr_stu].university.mid_term = num;
}

//finaling function
// fixing final score of each data set.
void finaling() {
printf("Enter student final score: ");
scanf("%d", &num);
studentlist[curr_stu].university.final_mark = num;
}

//totaling function
// fixing total score of each data set.
void totaling() {
struct student cur = studentlist[curr_stu];
studentlist[curr_stu].university.total = cur.university.assignment + cur.university.mid_term + cur.university.final_mark;
}

//upload helper function
void up_lo() {
up_re();
int iopt;
printf("Enter your option: ");
scanf("%d", &iopt);
if (iopt == 1)
	naming();
if (iopt == 2)
	contacting();
if (iopt == 3)
	addressing();
if (iopt == 4)
	assignmenting();
if (iopt == 5)
	mid_terming();
if (iopt == 6)
	finaling();
if (iopt != 7) {
	totaling();
	up_lo();
	}
}

//printing all data function
void printing_all() {

int i = 0;

while (i < num_stu) {
	struct Personal a = studentlist[i].personal;
	struct University b = studentlist[i].university;
	printf("Student #: %d\n", i + 1);
	printf("Name: %s\n", a.name);
	printf("Contact: %d\n", a.contact);
	printf("Address: %s\n", a.address);
	printf("Total: %d\n", b.total);
	i++;
}
}

//printing average function
void averaging() {
int i = 0;
int sum = 0;
while (i < num_stu) {
	sum += studentlist[i].university.total;
	i++;
}
printf("Average: %d\n", (int)(sum/num_stu));
}

//main redoing function
void redo() {
int pos;
int iopt;
optioning();
printf("Enter your option\n");
scanf("%d", &iopt);
if(iopt == 1) {
	printf("Enter student no: ");
	scanf("%d", &pos);
	while (pos > (num_stu) || pos <= 0) {
		printf("Wrong student no!\n");
		printf("Enter student no: ");
		scanf("%d", &pos);
		}
	curr_stu = pos - 1;
	up_lo();
	redo();
	}
if(iopt == 2) {
	printing_all();
	redo();
}
if(iopt == 3) {
	averaging();
	redo();
	}
}

//main function
int main() {
int inum;
printf("Enter the no of students to be created: ");
scanf("%d", &inum);
printf("%d student(s) created.\n", inum);
num_stu = inum;

redo();

printf("%d", studentlist[0].personal.contact);

return 0;
}