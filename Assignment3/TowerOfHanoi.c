#include <stdio.h>

void solvetower(int n, char from, char to, char using)
{

    if (n == 1)
    {

        printf("Move disc 1 from tower %c to tower %c \n", from, to);
        return;
    }

    solvetower(n - 1, from, using, to);                               // first solve n-1 from A to B using C
    printf("Move disc %d from tower %c to tower %c \n", n, from, to); // then move largest to C
    solvetower(n - 1, using, to, from);                               // move n-1 from B to C using A
}

int main()
{
    int n;
    printf("Enter the number of discs to solve for : \n"); // take value of n from the user
    scanf("%d", &n);
    solvetower(n, 'A', 'C', 'B');
    return 0;
}
