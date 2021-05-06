#include <stdio.h>
#include <stdlib.h>

void print_cake(const int n)
{
    for (int i = 1; i <= n; i++) {
        int j = i-n+1;
        //printf("i(%d), j(%d)\n", i, j);
        int k = j;
        // print left side
        while (j < i) {
            if (j <= 0) {
                printf(" ");
            } else {
                printf("%d", j);
            }
            ++j;
        }
        // print right side + middle one
        while (j >= k) {
            if (j > 0) {
                printf("%d", j);
            } else {
                printf(" ");
            }
            --j;
        }
        printf("\n");
    }
}

int main()
{
    print_cake(5);
    return 0;
}
