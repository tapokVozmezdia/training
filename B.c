#include <stdlib.h>
#include <stdlib.h>


int main() {
    int a[] = {1, 3, 2, 5, 4};
    int t;
    for (int i = 0; i <= 3; ++i) {
        for (int y = i + 1; y <= 4; ++y) {
            if (a[i] > a[y]) {
                t = a[y];
                a[y] = a[i];
                a[i] = t;
            }
        }
    }


    printf("%d %d", a[0], a[4]);
    FILE* f;
    f = fopen("3232.txt", "w");
    for (int i = 0; i <= 4; ++i) {
        fprint(f, "%d ", a[i]);
    }
    fclose(f);


    return 0;
}
