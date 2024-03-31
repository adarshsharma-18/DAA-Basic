#include <stdio.h>
#include <string.h>

// Function to perform naive string matching
void naiveStringMatching(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    // Loop through the text to find matches
    for (int i = 0; i <= n - m; i++) {
        // Check if the current substring matches the pattern
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m)
            printf("Pattern found at index %d\n", i);
    }
}

int main() {
    char text[100], pattern[100];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern: ");
    scanf("%s", pattern);

    printf("Occurrences of pattern in text:\n");
    naiveStringMatching(text, pattern);

    return 0;
}
