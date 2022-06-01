#include<bits/stdc++.h>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int next(int arr[], int target, int end)
{
    int start = 0;

    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        // Move to right side if target is
        // greater.
        if (arr[mid] <= target){
            start = mid + 1;
            ans = mid;
        }

        // Move left side.
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }

    return ans;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(int arr[], int l, int r, int x)
{
    int mid = l + (r - l) / 2;
    if (r >= l) {


        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x){
            if(arr[mid-1]<x){
                return mid-1;
            }
            return binarySearch(arr, l, mid - 1, x);
        }

        // Else the element can only be present
        // in right subarray
        if(arr[mid+1]>x){
            return mid;
        }
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    if(mid == 0 && arr[0]>x){
        return -1;
    }
    else{
        return r;
    }
}

int main(){
    int n;
    cin>>n;
    int shopPrice[n];
    for(int i=0;i<n;i++){
        int j;
        cin>>j;
        shopPrice[i]=j;
    }
    int numberOfDays = 0;
    cin>>numberOfDays;
    int amountPerDay[numberOfDays];
    for(int i=0;i<numberOfDays; i++){
        int j;
        cin>>j;
        amountPerDay[i] = j;
    }
    quickSort(shopPrice, 0, n - 1);
    for(int i=0;i<numberOfDays;i++){
        // int result = binarySearch(shopPrice, 0, n-1, amountPerDay[i]);
        int result = next(shopPrice, amountPerDay[i], n);
        cout<<result<<endl;
    }
}
