#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int DP[103][100003];
int w[103];
int v[103];

int main() {
    int n, k;//물건 종류의 수, 감당할수 있는 무게

    scanf_s("%d %d", &n, &k);

    for (int i = 1; i <= n; i++)
        scanf_s("%d %d", &w[i], &v[i]);// 무게와 가치 입력

    for (int i = 1; i <= n; i++) { // 물건의 종류 확인
        for (int j = 1; j <= k; j++) { // 1kg 부터 kkg 까지
            if (j - w[i] >= 0)
                DP[i][j] = MAX(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
            else DP[i][j] = DP[i - 1][j];
        }
    }

    printf("%d\n", DP[n][k]);

    return 0;
}