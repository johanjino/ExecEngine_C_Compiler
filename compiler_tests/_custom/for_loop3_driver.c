#include <stdio.h>
int f();

int main()
{
    printf("%i",f());
    return !(f()==5);
}
