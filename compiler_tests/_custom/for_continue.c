int f()
{
    int y = 0;
    for(int i=0; i<10; i++){
        if (i>=5){
            continue;
        }
        ++y;
    }
    return y;
}
