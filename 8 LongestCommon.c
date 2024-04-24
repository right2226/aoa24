// Longest common subsequence

 #include <stdio.h>
 #include <string.h> // For strlen()
 #define INF 99999
 int max(int a, int b);
 /* Returns length of LCS for A[] and B[] */
 int lcs(char *A, char *B, int i, int j) {
 if (i == 0 || j == 0)
 return 0;
 if (A[i - 1] == B[j - 1])
 return 1 + lcs(A, B, i - 1, j - 1);
 else
 return max(lcs(A, B, i, j - 1), lcs(A, B, i - 1, j));
 }
 /* function to get max of 2 integers */
 int max(int a, int b) {
 return (a > b) ? a : b;
 }
 /* main program to test above function */
 int main() {
 char A[] = "longest";
 char B[] = "stone";
 int i = strlen(A);
 int j = strlen(B);
 printf("Length of LCS is %d\n", lcs(A, B, i, j));
 return 0;
 }
 