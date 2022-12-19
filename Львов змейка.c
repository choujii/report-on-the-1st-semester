#include <stdio.h>


int main()
{
    int N = 5;
    int a[N][N];
    for (int in = 0; in < N; in++)
        for (int jn = 0; jn < N; jn++)
            a[in][jn] = 0;

    for (int in = 0; in < N; in++){
        for (int jn = 0; jn < N; jn++){

            int i = in + 1;
            int j = jn + 1;
            int D = i + j-1;
            int Matrix = (D * D + D) / 2 - ((D-N) * (D-N)) * (D / (N +1)) - j * ((D + 1) % 2) - i * (D % 2) + 1;
            a[jn][in] = Matrix;

        }
    }
    for (int in = 0; in < N; in++){
        for (int jn = 0; jn < N; jn ++){
            printf(" %02d ", a[in][jn]);

        }
        printf("\n");
    }
    return 0;



}
