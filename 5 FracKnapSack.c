// Fractional Knapsack 

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 // Structure to store the values of the knapsack object
 typedef struct
 {
 char name[20];
 int profit;
 int weight;
 float ratio;
 }knapsack;
 // Sort object in descending order by the profit/weight ratio
 knapsack *sort(knapsack *arr, int start, int end)
 {
 int size = (end - start);
 if(size == 1) return arr+start;
 int mid = (start + end) / 2;
 knapsack *lft = sort(arr, start, mid);
 knapsack *rht = sort(arr, mid, end);
 int l_size = (mid - start);
 int r_size = (end - mid);
 knapsack *left = malloc(sizeof(knapsack) * l_size);
 knapsack *right = malloc(sizeof(knapsack) * r_size);
 for(int i=0;i<l_size;i++)
 {
 left[i] = lft[i];
 }
 for(int i=0;i<r_size;i++)
 {
 right[i] = rht[i];
 }
 int l=0, r=0, a=start;
 while((l < l_size) && (r < r_size))
 {
 if(left[l].ratio > right[r].ratio)
 {
 arr[a] = left[l];
 l++;
 }
 else
 {
 arr[a] = right[r];
 r++;
}
 a++;
 }
 if(l == l_size)
 {
 while(r < r_size)
 {
 arr[a] = right[r];
 r++;
 a++;
 }
 }
 else
 {
 while(l < l_size)
 {
 arr[a] = left[l];
 l++;
 a++;
 }
 }
 return arr+start;
 }
 int main()
 {
 int total_objects, capacity;
 printf("Enter Total Number of Objects: ");
 scanf("%d", &total_objects);
 printf("Enter Capacity of Knapsack: ");
 scanf("%d", &capacity);
 knapsack *obj = malloc(sizeof(knapsack) * total_objects);
 // Gets the info of the objects
 for(int i=0; i<total_objects; i++)
 {
 printf("\nEnter Object Name: ");
 scanf("%s", obj[i].name);
 getchar();
 printf("Enter %s Profit: ", obj[i].name);
 scanf("%d", &obj[i].profit);
 printf("Enter %s Weight: ", obj[i].name);
 scanf("%d", &obj[i].weight);
 obj[i].ratio = (float) obj[i].profit / obj[i].weight;
 }
 sort(obj, 0, total_objects); // Sort the object
 float profit = 0.0; // Stores the total profit
 int div;
 for(int i=0;i<total_objects;i++)
 {
if(capacity <= 0) break;
 if(capacity > obj[i].weight)
 {
 div = obj[i].weight;
 }
 else
 {
 div = capacity;
 }
 profit += (((float)div / obj[i].weight) * obj[i].profit);// Calculate the profit
 capacity -= div;
 }
 printf("Total Profit: %.3f\n", profit); // Print the total profit
 return 0;
 }