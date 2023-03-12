int f()
{
    int y = 0;
    int i = 0;
    while(i<10){
        if (i>=5){
            i++;
            continue;
        }
        ++y;
        i++;
    }
    return y;
}
