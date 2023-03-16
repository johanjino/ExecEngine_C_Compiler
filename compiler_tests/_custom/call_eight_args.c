int g(int a, int b, int c, int d, int e, int f, int g, int h)
{
    int x = a+b+c+d;
    int y = e+f+g+h;
    return x+y;
}

int f()
{
    return g(1,2,3,4,5,6,7,8);
}
