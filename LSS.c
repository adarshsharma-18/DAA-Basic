longestCommonSubsequence(char X[], char Y[], int m, int n)
    // Create a 2D array to store the lengths of LCS
    int L[m + 1][n + 1]

    // Build the LCS matrix using dynamic programming
    for i from 0 to m
        for j from 0 to n
            if i = 0 or j = 0
                L[i][j] = 0
            else if X[i-1] = Y[j-1]
                L[i][j] = L[i-1][j-1] + 1
            else
                L[i][j] = max(L[i-1][j], L[i][j-1])

    // Traverse the matrix to find the LCS
    int index = L[m][n]
    char lcs[index + 1]
    lcs[index] = '\0'
    int i = m, j = n
    while i > 0 && j > 0
        if X[i-1] = Y[j-1]
            lcs[index-1] = X[i-1]
            i--, j--, index--
        else if L[i-1][j] > L[i][j-1]
            i--
        else
            j--

    // Print the LCS
    printf("Longest Common Subsequence: %s\n", lcs)
