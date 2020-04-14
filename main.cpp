#include <iostream>
#include <chrono>
#include <iomanip>
#include <bits/stdc++.h>
#define MY_ARRAY_LENGTH  30000
#define TIME_TEST 5
using namespace std;
using namespace std::chrono;


void give_random_array(int *);
void show(int *);
void mergeSort(int* ,int ,int );
void merge_arr(int* ,int ,int ,int);
void selectionSort(int *);
void insertionSort(int *);
void bubleSort(int *);
void quickSort(int *,int ,int);
int partition(int *,int ,int);

int main()
{
    cout << "[Sort] \n";
    auto total = 0;
	int arr[MY_ARRAY_LENGTH];
	int n = sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < TIME_TEST; ++i){
        give_random_array(arr);
        auto start = high_resolution_clock::now();
//      insertionSort(arr);
//      selectionSort(arr);
//      bubleSort(arr);
//      mergeSort(arr,0,MY_ARRAY_LENGTH-1);
//      quickSort(arr,0,MY_ARRAY_LENGTH-1);
        sort(arr,arr+n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        total += duration.count();
        //cout << "Time taken: " << i+1 << " "<< setw(6) << duration.count() << " milliseconds" << endl;
        cout << duration.count() << endl;
    }
    cout <<total/TIME_TEST << endl;


	return 0;
}

void show(int *arr)
{
    bool isSorted = true;
    for (int i = 0; i < MY_ARRAY_LENGTH; ++i)
    {
        if(arr[i] != arr[MY_ARRAY_LENGTH-1])
            if (arr[i] > arr[i+1])
                isSorted = false;
        cout << arr[i] << " ";
    }
    cout << (isSorted ? "[Sorted]" : "[Not Sorted]");
    cout << endl;
}

void give_random_array(int *arr)
{
    srand(time(NULL));
    //cout << "[Random array] \n";
    for (int i = 0; i < MY_ARRAY_LENGTH; ++i)
        arr[i] = i+1;
    for (int i = 1; i < MY_ARRAY_LENGTH; ++i)
    {
        int num = rand() % i + 1;
        swap(arr[i],arr[num]);
    }
    swap(arr[0],arr[rand() % MY_ARRAY_LENGTH + 1]);
    //show(arr);
}

void selectionSort(int *arr)
{
    for (int i = 0; i < MY_ARRAY_LENGTH-1; ++i) {
        int min = i;
        for (int j = i+1; j < MY_ARRAY_LENGTH; ++j)
            if (arr[j] < arr[min]) min = j;
        swap(arr[i], arr[min]);
    }
    //show(arr);
}

void insertionSort(int *arr)
{
    for (int i = 1; i < MY_ARRAY_LENGTH; ++i)
    {
        int tmp = arr[i];
        int j;
        for (j=i; j>0 && tmp < arr[j-1]; --j)
            arr[j] = arr[j-1];
        arr[j] = tmp;
    }
    //show(arr);
}

void bubleSort(int *arr)
{
    int last_sorted = MY_ARRAY_LENGTH;
    bool sorted = true;
    do
    {
        sorted = false;
        for(int i = 0; i < last_sorted-1; ++i)
            if (arr[i] > arr[i+1])
            {
                swap(arr[i],arr[i+1]);
                sorted = true;
            }
        last_sorted--;
    }while (sorted);
    //show(arr);
}

void merge_arr(int *arr, int first, int mid, int last)
{
    int tempArray[MY_ARRAY_LENGTH]; // temporary array
    int first1 = first; // beginning of first subarray
    int last1 = mid; // end of first subarray
    int first2 = mid + 1; // beginning of second subarray
    int last2 = last; // end of second subarray
    int index = first1; // next available location in tempArray
    for ( ; (first1 <= last1) && (first2 <= last2); ++index)
        if (arr[first1] < arr[first2])
            tempArray[index] = arr[first1++];
        else
            tempArray[index] = arr[first2++];
            // finish off the first subarray, if necessary
    for (; first1 <= last1; ++first1, ++index)
        tempArray[index] = arr[first1];
    // finish off the second subarray, if necessary
    for (; first2 <= last2; ++first2, ++index)
        tempArray[index] = arr[first2];
    // copy the result back into the original array
    for (index = first; index <= last; ++index)
        arr[index] = tempArray[index];
}

void mergeSort(int *arr, int first, int last) {
    if (first < last) { // more than one item
        int mid = (first + last)/2; // index of midpoint
        mergeSort(arr, first, mid);
        mergeSort(arr, mid+1, last);
        // merge the two halves
        merge_arr(arr, first, mid, last);
    }
} // end mergesort

int partition (int *arr, int low, int high)
{
    int pivot = arr[high];    // pivot
    int left = low;
    int right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
