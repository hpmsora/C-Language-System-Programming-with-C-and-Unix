#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  int num_arr[argc];

  int i;

  for(i = 0; i < argc; i++) {
    num_arr[i] = atoi(argv[i]);
  }

  int max_1_pos = 0;
  int max_2_pos = 0;
  int max_1_neg = 0;
  int max_2_neg = 0;
  int mul = 0;

  for(i = 0; i < argc; i++) {
    if(num_arr[i] < max_1_neg) {
      max_2_neg = max_1_neg;
      max_1_neg = num_arr[i];
    }
    else if(num_arr[i] < max_2_neg)
      max_2_neg = num_arr[i];
    else if(num_arr[i] > max_1_pos) {
      max_2_pos = max_1_pos;
      max_1_pos = num_arr[i];
    }
    else if(num_arr[i] > max_2_pos)
      max_2_pos = num_arr[i];
    else{}
  }
  if ((max_1_pos * max_2_pos) > (max_1_neg * max_2_neg))
    printf("%d %d\n", max_1_pos, max_2_pos);
  else
    printf("%d %d\n", max_1_neg, max_2_neg);
}
