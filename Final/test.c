#include <stdio.h>
#include <stdlib.h>
#include "node.h"

char ele[100];
node curr;
node *test_list;
node *del_test_list;
int num = 0;
int num2 = 0;
int del = 0;


void adding(node *head, int val) {
	if(num == 0) {
	    test_list->val = val;
	    num++;
	}
	else {
        node *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
            }
        curr->next = malloc(sizeof(node));
        curr->next->val = val;
        curr->next->next = NULL;
    	}
}

void deleting(node *head) {
	node* curr = head;
	while (curr != NULL) {
		if (curr->val != del) {
			adding(del_test_list, curr->val);
			}
		curr = curr->next;
        num2++;
        }
    num2 = 0;
}

void d(node *head) {
	printf("test111");
	//node* prev = head;
	node* nxt = head;
	node* temp = head;
	printf("test");
	while (temp != NULL) {
		if(temp->val == del){
			temp->next = nxt->next;
		}
		printf("temp: %d", temp->val);
		temp = temp->next;
		if (temp->next!= NULL)
        	nxt = temp->next;
        //num2++;
        printf("nxt: %d", nxt->val);
        }
        
    //num2 = 0;
}

void showing(node *head) {
    node * curr = head;
    while (curr != NULL) {
        	printf("%d  ", curr->val);
        	curr = curr->next;
        	num2++;
    }
    printf("\n");
    num2 = 0;
}

int main() {
	int size, i2;
	int i = 1;
	test_list = malloc(sizeof(node));
    test_list->next = NULL;
    del_test_list = malloc(sizeof(node));
    del_test_list->next = NULL;
    printf("Enter array size: ");
    scanf("%d", &size);
    while ( i <= size) {
    	printf("Enter number %d: ", i);
    	scanf("%d", &i2);
    	adding(test_list, i2);
    	i++;
    }
    // printf("Current array is ");
//     showing(test_list);
    printf("Enter number to remove from array: ");
    scanf("%d", &del);
    deleting(test_list);
    printf("Current array is ");
    showing(del_test_list->next);
    return 0;
}