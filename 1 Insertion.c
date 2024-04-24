//Insertion Sort Algorithm

 #include<stdio.h>
 void intersertionSort(int arr[], int n){
 int i, key, j;
 for(int i = 1; i<n; i++){
 key = arr[i];
 j = i-1;
 while(j>=0 && arr[j]>key){
 arr[j+1]=arr[j];
 j=j-1;
 }
 arr[j+1]=key;
 }
 }
 int main(){
 int n;
 printf("Enter the n no.");
 scanf("%d", &n);
 int arr[n];
 printf("Enter the elements of array");
 for(int i = 0; i<n; i++){
 scanf("%d", &arr[i]);
 }
 intersertionSort(arr, n);
 for(int i = 0; i<n; i++){
 printf("%d\t", arr[i]);
 }
 }