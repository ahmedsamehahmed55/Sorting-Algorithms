#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#include "support.h"
#include "hw.h"

#define NPERLINE 10

// Swap the values of a and b
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


void printArray(int a[], const int size) {
    // print in blocks of NPERLINE per line
    cout << "=====================================================================\n";
    for(int i=0;i<size;i++) {
        if ((i>0) && (i%NPERLINE)==0) printf("\n");
        printf("%6d ",a[i]);
    }
    printf("\n");
    cout << "=====================================================================\n";

}

// print timing
void printTiming(string algorithmName, double timeRandom, double timeSorted, double timeReversed, double timeSortedDesc){
    cout << algorithmName << ":\n";
    cout << "   Sort Random array in ascending order         → " << timeRandom      << " sec\n";
    cout << "   Sort Already sorted array in ascending order → " << timeSorted      << " sec\n";
    cout << "   Reverse array to descending order            → " << timeReversed    << " sec\n";
    cout << "   Sort Array in ascending order                → " << timeSortedDesc  << " sec\n\n";
    cout<<"================================================================================="<<"\n";
}



// merge 
void merge(int leftarr[], int rightarr[], int arr[], int left, int right, bool ascending = true) {
   int i=0, j=0, k=0; 
   // Merge two sorted subarrays (leftarr and rightarr) into arr
   while(i<left&&j<right){ 
   if ((ascending && leftarr[i] <= rightarr[j]) ||
    (!ascending && leftarr[i] >= rightarr[j])) {
    arr[k++] = leftarr[i++];   
    } else {
    arr[k++] = rightarr[j++]; }}
   while(i<left){ // Copy remaining elements from left subarray
    arr[k++]=leftarr[i++];
   }
   while(j<right){  // Copy remaining elements from right subarray
    arr[k++]=rightarr[j++];
   }
   }

// Recursive merge sort
void mergeSort(int arr[], const int size, bool ascending = true) {
    if (size<=1) return; // base case
    int right=size/2;
    int left=size-right;
    int* leftarr=new int[left]; // allocate new array
    int* rightarr= new int[right];
    for (int i=0; i<left;i++){ // Copy elements into left subarray
         leftarr[i]=arr[i];
    }
    for(int j=left;j<size;j++){ // Copy elements into right subarray
        rightarr[j-left]=arr[j];
    }
    mergeSort(leftarr, left, ascending); // recursive call
    mergeSort(rightarr, right, ascending);
    merge(leftarr, rightarr,arr, left, right, ascending);
    delete [] rightarr; // Free right subarray
    delete [] leftarr; // Free left subarray
}

  
// partition
int partition(int arr[], const int start, const int end, bool ascending = true ){
    int pivot = 0;
    // find the median of three
    if ((arr[end] >= arr[(end+start)/2] && arr[end] <= arr[start]) ||
        (arr[end] <= arr[(end+start)/2] && arr[end] >= arr[start])) {
        pivot = end;
    }
    else if ((arr[start] >= arr[(end+start)/2] && arr[start] <= arr[end]) ||
            (arr[start] <= arr[(end+start)/2] && arr[start] >= arr[end])) {
        pivot = start;
    }
    else {
        pivot = (end+start)/2;
    }
    // add the midian to the end
    swap(arr[pivot],arr[end]);
    int temp=arr[end];
    int j=start-1;
    // make sure that elements in right of the pivot is smaller than the pivot

    for(int i=start;i<end;i++){
        if(arr[i]<=temp&&ascending ||arr[i]>=temp && !ascending){
            j++;
            swap(arr[i], arr[j]);            
        }
    }
    // Place the pivot element in its correct sorted position
    swap(arr[end], arr[j+1]);
    return j+1; // return pivot location
}
void quickSort(int arr[], const int start, const int end, bool ascending = true){
    if(end>start){ // stopping condition: stop when subarray has one or zero elements
    int pivot=partition(arr, start, end, ascending); 
    quickSort(arr,start , pivot-1,ascending ); // Recursively sort left partition
    quickSort(arr, pivot+1, end, ascending); // Recursively sort right partition
}

}

// quick sort
void quickSort(int arr[], int size, bool ascending = true) {  // function overloading to use it in the main 
    quickSort(arr, 0, size-1, ascending);
}  
// insertion sort
void insertionSort(int arr[], const int size,  bool ascending = true){ 
    for (int i=1;i<size;i++){  
        int j=i-1;
        int temp=arr[i];
        while(j>=0 && (temp<arr[j]&& ascending || temp>arr[j]&& !ascending)){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
// selection sort
void selectionSort(int arr[], const int size, bool ascending = true) {
    for (int i = 0; i < size - 1; i++) {
        int targetIndex = i;
        // Find the largest or the smallest element in the array
        for (int j = i + 1; j < size; j++) {
            if ((ascending && arr[j] < arr[targetIndex]) || 
                (!ascending && arr[j] > arr[targetIndex])) {
                targetIndex = j;
            }
        }
        // Swap the smallest (or largest) element found with the current index
        if (targetIndex != i) swap(arr[i], arr[targetIndex]);   
    }
}

// bubble sort
void bubble(int a[], const int size, bool ascending = true) {
    for(int i=0;i<size;i++) {
        bool sorted=true;
        for(int j=0;j<size-i-1;j++) {
            if (a[j]>a[j+1]&&ascending==true 
            || a[j]<a[j+1]&&ascending==false ) {
                swap(a[j],a[j+1]);
                sorted=false;
            }
        }
        if (sorted) break; // exit if no swapes happened
    }
}

void algorithmTime(string name,void Func(int[], const int, bool), int arr[], const int num){
    //cout <<name <<":\n";
    //sort unsorted
    double start = getCPUTime();
    Func(arr,num, 1);
    double end = getCPUTime();
    double timeRandom=end-start;
    //printArray(arr,num);
    //sort sorted
    start = getCPUTime();
     Func(arr,num, 1);
    end = getCPUTime();
    double timeSorted=end-start;
    //printArray(arr,num);
    // reverse 
    start = getCPUTime();
    Func(arr,num, 0);
    end = getCPUTime();
    double timeDec=end-start;
    //printArray(arr,num);
     // reverse again
    start = getCPUTime();
     Func(arr,num, 1);
    end = getCPUTime();
    double revAgain=end-start;
    //printArray(arr,num);
    printTiming(name, timeRandom, timeSorted, timeDec, revAgain);
}
// print an integer array

int main(int argc, char *argv[]) {
    // check arguments
    if (argc!=2) {
        cerr << "Usage: " << argv[0] << " num_of_elements\n";
        return -1;
    }
    // create base array
    int num = stoi(argv[1]); // string to integer
    int *arr = new int[num];

    // read data
    for(int i=0;i<num;i++) {
        cin >> arr[i];
    }
    // print before sort
    cout<< "Number of Elements :"<< num<<"\n";
    //cout << "Original\n";
    //printArray(arr,num);
    // bubble sort
    //algorithmTime("Bubble Sort", bubble, arr, num);
    //selection sort
    //algorithmTime("Selection Sort", selectionSort, arr, num);
    // insertion sort
    //algorithmTime("Insertion Sort", insertionSort, arr, num);
    // merge sort
    //algorithmTime("Merge Sort", mergeSort, arr, num);
    // quick Sort
    algorithmTime("Quick Sort", quickSort, arr, num);

    // clean up
    delete[] arr;

    return 0;
}