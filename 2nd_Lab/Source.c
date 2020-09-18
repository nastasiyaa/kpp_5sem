#include <stdio.h>
int a[1000][1000];
int main() {
   int n, m, buf;
    scanf_s("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            scanf_s("%d", &a[i][j]);
        }

    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n - 1; i++)
            for (int k = i + 1; k < n; k++)
            {
                if (a[i][j] > a[k][j] && a[i][j] < 0 && a[k][j] < 0)
                {
                    buf = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = buf;
                }
            }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}