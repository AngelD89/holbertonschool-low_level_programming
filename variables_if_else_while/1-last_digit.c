#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n;

    srand(time(0));  // Seed the random number generator
    n = rand() - RAND_MAX / 2;  // Generate a random number

    int last_digit = n % 10;  // Get the last digit of the number

    // Print the last digit and the corresponding message
    printf("Last digit of %d is %d and is ", n, last_digit);

    if (last_digit > 5)
    {
        printf("greater than 5\n");
    }
    else if (last_digit == 0)
    {
        printf("0\n");
    }
    else if (last_digit < 6 && last_digit != 0)
    {
        printf("less than 6 and not 0\n");
    }

    return (0);
}

