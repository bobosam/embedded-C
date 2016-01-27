#include <stdio.h>

#define COUNT_CARDS 13
#define COUNT_SUITS 4

int main(void) {
    int faces, counter = 1;
    for (faces = 0; faces < COUNT_CARDS; faces++) {
        int suits;
        for (suits = 0; suits < COUNT_SUITS; suits++) {
            switch (faces) {
                case 0: printf("2");
                    break;
                case 1: printf("3");
                    break;
                case 2: printf("4");
                    break;
                case 3: printf("5");
                    break;
                case 4: printf("6");
                    break;
                case 5: printf("7");
                    break;
                case 6: printf("8");
                    break;
                case 7: printf("9");
                    break;
                case 8: printf("10");
                    break;
                case 9: printf("J");
                    break;
                case 10: printf("Q");
                    break;
                case 11: printf("K");
                    break;
                case 12: printf("A");
                    break;
            }

            switch (suits) {
                case 0: printf("C ");
                    break;
                case 1: printf("D ");
                    break;
                case 2: printf("H ");
                    break;
                case 3: printf("S ");
                    break;
            }

            if (4 == counter) {
                printf("\n");
                counter = 0;
            }

            counter++;
        }


    }



    return 0;
}

