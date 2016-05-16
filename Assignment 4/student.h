//structure type of personals
struct Personal {
char name[100];
int contact;
char address[200];
};

//structure type of university
struct University {
int assignment;
int mid_term;
char final_mark;
int total;
};

//structure type of student (personal + university)
struct student {
int stu_id;
struct Personal personal;
struct University university;
};