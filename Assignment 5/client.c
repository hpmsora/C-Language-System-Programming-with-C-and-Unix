#include <stdio.h>
#include "node.h"
#include <stdlib.h>

node * test_list;
int or = 0;
int sz = 0;

void searching(node *head, int n) {
    node * current = head;
    int f = 0;
    while (current != NULL) {
        if (n == current->val) {
        	f++;
        	printf("Found value in linkedlist\n");
        	}
        current = current->next;
    }
    if (f == 0)
    	printf("Value not found\n\n");
}

void print_list(node *head) {
    node * current = head;

    while (current != NULL) {
    	if(sz == 0) {
    		printf("%d", current->val);
        	current = current->next;
        	sz++;
    	}
    	else {
        	printf(" -> %d", current->val);
        	current = current->next;
        	sz++;
        }
    }
    printf("\n");
    sz = 0;
}

void adding(node *head, int val) {
	if(or == 0) {
	    test_list->val = val;
	    or++;
	}
	else {
        node * current = head;
        while (current->next != NULL) {
            current = current->next;
            }
        current->next = malloc(sizeof(node));
        current->next->val = val;
        current->next->next = NULL;
    	}
}

void optioning() {
int i = 0;
int m = 0;
printf("Enter your option:\n\n");
printf("\t1. Add element\n");
printf("\t2. Search\n");
printf("\t3. Display\n");
printf("\t4. Exist\n\n");
scanf("%d", &i);

if(i == 1) {
	printf("Enter the value: ");
	scanf("%d", &m);
	adding(test_list, m);
	optioning();
	}
if(i == 2) {
	printf("Enter the value: ");
	scanf("%d", &m);
	searching(test_list, m);
	optioning();
	}
if(i == 3) {
	print_list(test_list);
	optioning();
	}
}

int main() {
	test_list = malloc(sizeof(node));
    test_list->next = NULL;
    optioning();
    return 0;
}