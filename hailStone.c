# include <stdio.h>

int main(int argc, char *argv[])
{
    int length = 1;
    int number = 27;

    while (1 < number)
    {
        printf("number(%d):%d \n", length, number);
        number = (number % 2) ? 3 * number + 1: number / 2;
        length ++;
    }

    printf("%d\n", length);
}
