#include <stdio.h>

int f();

int main()
{
    int val = f();
    printf("The value returned: %d", val);
    return !( 7928 == val);
}
