#include <stdio.h>
char *search(char *x, char c);

int main()
{
    char *s="abcdef";

    char *p=search((char*)s,'c');
    printf("%p\n",s);
    printf("%p\n",p);
    return !(p==s+2);
}
