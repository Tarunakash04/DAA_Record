#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100
int max(int a, int b) {
    return (a > b) ? a : b;
}
int longestCommonSubsequence(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

 
    return L[m][n];
}

void printLongestCommonSubsequence(char *X, char *Y, int m, int n) {
    int L[m + 1][n + 1];
    int i, j, index;
    char lcs[MAX_LENGTH];

 
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    i = m;
    j = n;
    index = L[m][n];
    lcs[index] = '\0';
    while (i > 0 && j > 0) {
     
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
       
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }


    printf("Longest Common Subsequence: %s\n", lcs);
}

int main() {
    char X[MAX_LENGTH], Y[MAX_LENGTH];
    int m, n;

    printf("Enter the first string: ");
    scanf("%s", X);

    printf("Enter the second string: ");
    scanf("%s", Y);

    m = strlen(X);
    n = strlen(Y);

    int length = longestCommonSubsequence(X, Y, m, n);
    printf("Length of Longest Common Subsequence: %d\n", length);

    printLongestCommonSubsequence(X, Y, m, n);

    return 0;
}
