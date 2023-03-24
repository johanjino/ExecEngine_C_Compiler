int f() {
    int i=0;

    // Loop with empty condition statement
    for (; ; i++) {
        if (i >= 5) {
            break;
        }
    }
    return i;
}
