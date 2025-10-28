#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int W, int weight[], int value[]) {
    int K[20][20];
    int i, w;

    // Build table K[][] using bottom-up DP
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    printf("\nMaximum value in knapsack = %d\n", K[n][W]);
}

int main() {
    int n, i, W;
    int value[20], weight[20];

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights: ");
    for (i = 0; i < n; i++) scanf("%d", &weight[i]);
    printf("Enter values: ");
    for (i = 0; i < n; i++) scanf("%d", &value[i]);
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    knapsack(n, W, weight, value);
    return 0;
}
