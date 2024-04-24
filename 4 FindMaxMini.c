
// Finding Minimum and Maximum Element

 #include <stdio.h>
 void MaxMin(int i, int j, int a[], int *max, int *min) {
    if (i == j) {
        *max = *min = a[i];
    } else if (i == j - 1) {
        if (a[i] < a[j]) {
            *max = a[j];
            *min = a[i];
        } else {
            *max = a[i];
            *min = a[j];
        }
    } else {
        int mid = (i + j) / 2;
        int max1, min1, max2, min2;
        MaxMin(i, mid, a, &max1, &min1);
        MaxMin(mid + 1, j, a, &max2, &min2);
        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 < min2) ? min1 : min2;
    }
 }
 int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
int max_val, min_val;
 MaxMin(0, n - 1, arr, &max_val, &min_val);
 printf("Maximum value: %d\n", max_val);
 printf("Minimum value: %d\n", min_val);
 return 0;
 }
 