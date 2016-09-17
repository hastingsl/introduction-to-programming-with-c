#include <stdio.h>
#include <stdlib.h>

/*
  Requests integer numbers be input from the keyboard continuously until the user enters a 0.
  Once the user finishes entering numbers, the program prints the average value of the even numbers,
  the average value of the odd numbers, the largest even number, and the smallest odd number.
*/

// Function prototypes:
// Determines if a number is even:
int is_even(int num);
// Calculates average:
float calc_average(int num, int num_of_nums);

int main (void) {

  printf("Hello. Please enter your name.\n");
  char name[50];
  scanf("%s", name);
  printf("Enter integers. Enter 0 to quit.\n");

  int num_even = 0;
  int num_odd = 0;
  int sum_even = 0;
  int sum_odd = 0;
  int max_even = 0;
  int min_odd = 0;

  while (1) {

    // Get integer from user.
    int num;
    printf("Please enter an integer:\n");
    // We exit if the user enters 0:
    scanf("%d", &num);
    if (num == 0) {
      break;
    }

    if (is_even(num)) {
      sum_even += num;
      num_even++;
      if(num > max_even) {
        max_even = num;
      }
    }
    else {
      sum_odd += num;
      num_odd++;
      if(min_odd == 0 || num < min_odd) {
        min_odd = num;
      }
    }
  }

  // Outputs info:
    float average_even = calc_average(sum_even, num_even);
    float average_odd = calc_average(sum_odd, num_odd);
    printf("%s,\n", name);
    printf("The average of the even numbers is %.2f and the average of the odd numbers is %.2f.\n", average_even, average_odd);
    printf("The largest even number entered was %d.\n", max_even);
    printf("The smallest odd number entered was %d.\n", min_odd);

  return 0;
}

// Determines if a number is even or odd
int is_even (int num) {
  if (num % 2 == 0) {
    return 1;
  }
  return 0;
}

// Calculates the average given a number and the number of numbers it is the sum of
float calc_average (int num, int num_of_nums) {
  return (float) num / (float) num_of_nums;
}
