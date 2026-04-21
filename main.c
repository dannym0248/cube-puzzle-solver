#include <stdio.h>
#include <stdlib.h>

const int turn_left = 0;
const int turn_right = 1;
const int turn_up = 2;
const int turn_down = 3;

int opposite(int n) {
    if (n>6 || n<1) {
        printf("Würfelzahl muss zwischen 1 und 6 liegen, hat hier aber den Wert %d!\n", n);
        exit(EXIT_FAILURE);
    }
    return 7 - n;
}

int main(void) {
    int top = 2;
    int front = 6;
    int leftside = 3;
    int tmp = -1;

    int ops[] = {turn_right, turn_right, turn_right, turn_down, turn_left, turn_down, turn_right, turn_down, turn_left, turn_left, turn_up, turn_up, turn_left, turn_down, turn_down, turn_down, turn_right, turn_right, turn_right};

    int steps = sizeof(ops) / sizeof(ops[0]);

    printf("%d Schritte\n",steps);

    for (int step = 0; step < steps; step++) {
        if (ops[step] == turn_down) {
            // leftside const
            tmp = top;
            top = opposite(front);
            front = tmp;
        } else if (ops[step] == turn_up) {
            // leftside const
            tmp = top;
            top = front;
            front = opposite(tmp);
        } else if (ops[step] == turn_left) {
            // front const
            tmp = top;
            top = opposite(leftside);
            leftside = tmp;
        } else if (ops[step] == turn_right) {
            // front const
            tmp = top;
            top = leftside;
            leftside = opposite(tmp);
        } else {
            printf("Nicht definierte Operation!");
            return 1;
        }
        printf("Schritt %d: \n", step+1);
        printf("oben = %d\n", top);
        printf("links = %d\n", leftside);
        printf("vorn = %d\n", front);
        printf("\n");
    }

    printf("Am Ende zeigt %d nach oben.\n", top);

    return 0;
}