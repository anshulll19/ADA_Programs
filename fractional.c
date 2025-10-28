#include <stdio.h>

void fractionalKnapsack(int n, float weight[], float value[], float capacity) {
    float ratio[20], temp;
    int i, j;
    float totalValue = 0, remaining = capacity;

    // Step 1: Compute value/weight ratio
    for (i = 0; i < n; i++)
        ratio[i] = value[i] / weight[i];

    // Step 2: Sort items by ratio (descending)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
                temp = value[i]; value[i] = value[j]; value[j] = temp;
            }
        }
    }

    // Step 3: Pick items
    for (i = 0; i < n; i++) {
        if (weight[i] <= remaining) {
            totalValue += value[i];
            remaining -= weight[i];
        } else {
            totalValue += value[i] * (remaining / weight[i]);
            break;
        }
    }

    printf("\nMaximum value in knapsack = %.2f\n", totalValue);
}

int main() {
    int n, i;
    float weight[20], value[20], capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter weights: ");
    for (i = 0; i < n; i++) scanf("%f", &weight[i]);
    printf("Enter values: ");
    for (i = 0; i < n; i++) scanf("%f", &value[i]);
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    fractionalKnapsack(n, weight, value, capacity);
    return 0;
}
