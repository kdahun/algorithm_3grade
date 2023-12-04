#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int DP[103][100003];
int w[103];
int v[103];

int main() {
    int n, k;//���� ������ ��, �����Ҽ� �ִ� ����

    scanf_s("%d %d", &n, &k);

    for (int i = 1; i <= n; i++)
        scanf_s("%d %d", &w[i], &v[i]);// ���Կ� ��ġ �Է�

    for (int i = 1; i <= n; i++) { // ������ ���� Ȯ��
        for (int j = 1; j <= k; j++) { // 1kg ���� kkg ����
            if (j - w[i] >= 0)
                DP[i][j] = MAX(DP[i - 1][j], DP[i - 1][j - w[i]] + v[i]);
            else DP[i][j] = DP[i - 1][j];
        }
    }

    printf("%d\n", DP[n][k]);

    return 0;
}