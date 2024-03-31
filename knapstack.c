#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Comparison function to sort items by value-to-weight ratio in non-increasing order
int compare(const void *a, const void *b) {
    double ratio1 = (double)(((struct Item *)a)->value) / (((struct Item *)a)->weight);
    double ratio2 = (double)(((struct Item *)b)->value) / (((struct Item *)b)->weight);
    return (ratio2 - ratio1) > 0 ? 1 : -1;
}

// Function to solve the knapsack problem using the greedy approach
int knapsackGreedy(int W, int weights[], int values[], int n) {
    struct Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].value = values[i];
        items[i].weight = weights[i];
    }

    // Sort items by their value-to-weight ratio in non-increasing order
    qsort(items, n, sizeof(struct Item), compare);

    int totalValue = 0, totalWeight = 0;
    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= W) {
            totalValue += items[i].value;
            totalWeight += items[i].weight;
        } else {
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];
    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    int maxValue = knapsackGreedy(W, weights, values, n);
    printf("Maximum value achievable: %d\n", maxValue);

    return 0;
}
