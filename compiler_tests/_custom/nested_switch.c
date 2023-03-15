int determine_quadrant(int x, int y) {
    int quadrant;

    switch (x > 0) {
        case 1:
            switch (y > 0) {
                case 1:
                    quadrant = 1;
                    break;
                case 0:
                    quadrant = 4;
                    break;
            }
            break;
        case 0:
            switch (y > 0) {
                case 1:
                    quadrant = 2;
                    break;
                case 0:
                    quadrant = 3;
                    break;
            }
            break;
    }

    return (quadrant);
}
