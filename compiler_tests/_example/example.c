int f()
{
    int a = 5;
    int b = ++a;
    ++b;
    ++b;
    int c = --b;

    return c;
}
