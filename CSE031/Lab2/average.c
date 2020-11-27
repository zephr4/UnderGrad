#include <stdio.h>

/*
    Read a set of values from the user.
    Store the sum in the sum variable and return the number of values read.
*/
int read_values(double sum) {
  int values=0,input=0;
  sum = 0;
  printf("Enter input values (enter 0 to finish):\n");
  scanf("%d", &input);
  while(input != 0) {
    values++;
    sum += input;
    scanf("%d", &input);
  }
  return sum/values; //the program was only returning sum and not values.
}

int main() {
  double sum=0;
  double avg=0;
  int values=0; //values caused a segmentation fault because it was not intialized, forcing itslef to be set to garbage, initialize to fix
  avg = read_values(sum);
  printf("Average: %g\n",avg);
  return 0;
}

