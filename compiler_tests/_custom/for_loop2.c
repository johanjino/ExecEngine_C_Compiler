int f() {
    int i;

    // Loop with empty condition statement
    for (; ; i++) {
        if (i >= 5) {
            break;
        }
    }
    return i;
}
