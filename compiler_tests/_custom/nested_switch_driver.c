int determine_quadrant();

int main() {
    int test1 = 1==determine_quadrant(2, 3);  // Quadrant 1
    int test2 = 2==determine_quadrant(-2, 3); // Quadrant 2
    int test3 = 3==determine_quadrant(-2, -3);// Quadrant 3
    int test4 = 4==determine_quadrant(2, -3); // Quadrant 4
    return (test1 - test2) - (test3 - test4) ;
}
