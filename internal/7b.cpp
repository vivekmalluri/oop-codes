#include <bits/stdc++.h>
using namespace std;
template<typename data>
bool compare(data left, data right)
{
 return left > right;
}
void swap(int *xp, int *yp)
{
 int temp = *xp;
 *xp = *yp;
 *yp = temp;
}
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
 int i, j;
 for (i = 0; i < n-1; i++) 
 
 // Last i elements are already in place
 for (j = 0; j < n-i-1; j++)
 if (compare(arr[j],arr[j+1]))
 swap(&arr[j], &arr[j+1]);
}
//selection sort
void selectionSort(int arr[], int n)
{
 int i, j, min_idx;
 // One by one move boundary of unsorted subarray
 for (i = 0; i < n-1; i++)
 {
 // Find the minimum element in unsorted array
 min_idx = i;
 for (j = i+1; j < n; j++)
 if (compare(arr[j], arr[min_idx]))
 min_idx = j;
 // Swap the found minimum element with the first element
 swap(&arr[min_idx], &arr[i]);
 }
}
/* Function to print an array */
void printArray(int arr[], int size)
{
 int i;
 for (i = 0; i < size; i++)
 cout << arr[i] << " ";
 cout << endl;
}
//MergeSort
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
 int n1 = m - l + 1;
 int n2 = r - m;
 // Create temp arrays
 int L[n1], R[n2];
 // Copy data to temp arrays L[] and R[]
 for (int i = 0; i < n1; i++)
 L[i] = arr[l + i];
 for (int j = 0; j < n2; j++)
 R[j] = arr[m + 1 + j];
 // Merge the temp arrays back into arr[l..r]
 // Initial index of first subarray
 int i = 0;
 // Initial index of second subarray
 int j = 0;
 // Initial index of merged subarray
 int k = l;
 while (i < n1 && j < n2) {
 if (L[i] <= R[j]) {
 arr[k] = L[i];
 i++;
 }
 else {
 arr[k] = R[j];
 j++;
 }
 k++;
 }
 // Copy the remaining elements of
 // L[], if there are any
 while (compare(n1,i)) {
 arr[k] = L[i];
 i++;
 k++;
 }
 // Copy the remaining elements of
 // R[], if there are any
 while (compare(n2,j)) {
 arr[k] = R[j];
 j++;
 k++;
 }
}
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
 if(l>=r){
 return;//returns recursively
 }
 int m =l+ (r-l)/2;
 mergeSort(arr,l,m);
 mergeSort(arr,m+1,r);
 merge(arr,l,m,r);
}
// Driver code
int main()
{
 int arr[] = {64, 34, 25, 12, 22, 11, 90};
 int n = sizeof(arr)/sizeof(arr[0]);
 bubbleSort(arr, n);
 cout<<"Sorted array using Buble Sort: \n";
 printArray(arr, n);
 cout<<"\nSelection Sort\n";
 selectionSort(arr, n);
 cout << "Sorted array: \n";
 printArray(arr, n);
 int arr_merge[] = { 12, 11, 13, 5, 6, 7 };
 int arr_size = sizeof(arr) / sizeof(arr[0]);
 cout << "Given array is \n";
 printArray(arr_merge, arr_size);
 mergeSort(arr_merge, 0, arr_size - 1);
 cout << "\nSorted array using Merge Sortis \n";
 printArray(arr_merge, arr_size);
 return 0;
}
