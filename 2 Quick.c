//Quick Short  
#include<stdio.h>
 #include<stdlib.h>
 void quicksort(int *arr, int start, int end)
 {
 if(start == end-1) 
{
 return;
 }
 int p = start+1, q = end-1;
 int v = start;
 if(p >= q)
 {
 if(arr[p] < arr[v])
 {
 int temp = arr[p];
 arr[p] = arr[v];
 arr[v] = temp;
 }
 return;
 }
 else
 {
 while(p<q)
 {
 while((arr[p] < arr[v]))
 {
 if(p>=end){break;}
 p++;
 }
 while((arr[q] > arr[v]))
 {
 if(q<=start){break;}
 q--;
 }
 if(p >= q)
 {
 int temp = arr[v];
 arr[v] = arr[q];
arr[q] = temp;
 quicksort(arr, start, q);
 quicksort(arr, q+1, end);
 }
 else
 {
 int temp = arr[p];
 arr[p] = arr[q];
 arr[q] = temp;
 }
 }
 }
 }
 int main()
 {
 int n;
 printf("Enter the size of array: ");
 scanf("%d", &n);
 int *arr = malloc(sizeof(int)*n);
 for(int i=0;i<n;i++)
 {
 printf("Enter %d Element: ", i+1);
 scanf("%d", &arr[i]);
 }
 quicksort(arr, 0, n);
 printf("Sorted Array: ");
 for(int i=0;i<n;i++)
 {
 printf("%d ", arr[i]);
 }
 printf("\n");
 return 0;
 }
 