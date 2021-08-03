//John Merino
//Assignment 2 sorting

#include <iostream>
#include <random>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


void datasetGenerator(double array[], int size);
void swap(double *num1, double *num2);
int selectionSort(double array[], int size);
void printArray(double array[], int size);
void duplicateArray(double arrayToCopy[], double copyOfArray[], int size);
int insertionSort(double array[], int size);
int  bubbleSort(double arr[], int n);
int mergeSort(double *array, int l, int r);
void merge(double *array, int l, int m, int r);
int quickSort(double arr[], int low, int high);
int partition (double arr[], int low, int high);
int heapSort(double arr[], int n);
void heapify(double arr[], int n, int i);


const int size = 25000;

int main()
{

  cout << "This program will take some time to run, please do not quit\n" << "\n" << endl;
  int selectionSortTime, insertionSortTime, bubbleSortTime, mergeSortTime,
      quickSortTime, heapSortTime, selectionSortTime2, insertionSortTime2, bubbleSortTime2, mergeSortTime2,
          quickSortTime2, heapSortTime2;
  double dataset[size], selectionSortArray[size], insertionSortArray[size],bubbleSortArray[size],
  mergeSortArray[size], quickSortArray[size], heapSortArray[size], runTimeArray[6];
  datasetGenerator(dataset, size);
  duplicateArray(dataset, selectionSortArray, size);
  duplicateArray(dataset, insertionSortArray, size);
  duplicateArray(dataset, bubbleSortArray, size);
  duplicateArray(dataset, mergeSortArray, size);
  duplicateArray(dataset, quickSortArray, size);
  duplicateArray(dataset, heapSortArray, size);

  double dataset2[size], selectionSortArray2[size], insertionSortArray2[size],bubbleSortArray2[size],
  mergeSortArray2[size], quickSortArray2[size], heapSortArray2[size], runTimeArray2[6];
  datasetGenerator(dataset2, size);
  duplicateArray(dataset2, selectionSortArray2, size);
  duplicateArray(dataset2, insertionSortArray2, size);
  duplicateArray(dataset2, bubbleSortArray2, size);
  duplicateArray(dataset2, mergeSortArray2, size);
  duplicateArray(dataset2, quickSortArray2, size);
  duplicateArray(dataset2, heapSortArray2, size);



  selectionSortTime = selectionSort(selectionSortArray, size);
  insertionSortTime = insertionSort(insertionSortArray,size);
  bubbleSortTime = bubbleSort(bubbleSortArray,size);
  mergeSortTime = mergeSort(mergeSortArray, 0, size-1);
  quickSortTime = quickSort(quickSortArray, 0, size-1);
  heapSortTime = heapSort(heapSortArray, size);

  selectionSortTime2 = selectionSort(selectionSortArray2, size);
  insertionSortTime2 = insertionSort(insertionSortArray2,size);
  bubbleSortTime2 = bubbleSort(bubbleSortArray2,size);
  mergeSortTime2 = mergeSort(mergeSortArray2, 0, size-1);
  quickSortTime2 = quickSort(quickSortArray2, 0, size-1);
  heapSortTime2 = heapSort(heapSortArray2, size);


  runTimeArray[0] = (selectionSortTime + selectionSortTime2) / 2;
  runTimeArray[1] = (insertionSortTime + insertionSortTime2) / 2;
  runTimeArray[2] = (bubbleSortTime + bubbleSortTime2) /2;
  runTimeArray[3] = (mergeSortTime + mergeSortTime2) /2;
  runTimeArray[4] = (quickSortTime + quickSortTime2) /2;
  runTimeArray[5] = (heapSortTime + heapSortTime2) /2;

  duplicateArray(runTimeArray, runTimeArray2, 6);
  bubbleSort(runTimeArray, 6);
  cout << "Runtimes measured in microseconds. Each sort ran twice with dataset of 25000" << endl;
  cout << "Sorts displayed fastest to slowest based on the average of 2 runs" << endl;
  cout << setw(20) << left << "Sort Type" << setw(20) << left <<"Runtime dataset 1" << setw(20) << left <<"Runtime dataset 2" << setw(20) << left <<"Average" << endl;
  cout << setw(20) << "--------------------" << "--------------------" << "--------------------" <<"--------------------"<<""<<endl;
  for (int i = 0; i < 6; i++)
  {
    if (runTimeArray[i] == runTimeArray2[0])
      cout << setw(20) << left << "Selection Sort" << setw(20) << left << selectionSortTime << setw(20) << left << selectionSortTime2 << setw(20) << left <<runTimeArray[i] << endl;
    else if (runTimeArray[i] == runTimeArray2[1])
      cout << setw(20) << left << "Insertion Sort" << setw(20) << left << insertionSortTime << setw(20) << left << insertionSortTime2 << setw(20) << left << runTimeArray[i] << endl;
    else if (runTimeArray[i] == runTimeArray2[2])
      cout << setw(20) << left << "Bubble Sort" << setw(20) << left << bubbleSortTime << setw(20) << left << bubbleSortTime2 << setw(20) << left << runTimeArray[i] << endl;
    else if (runTimeArray[i] == runTimeArray2[3])
      cout << setw(20) << left << "Merge Sort" << setw(20) << left << mergeSortTime << setw(20) << left << mergeSortTime2 << setw(20) << left << runTimeArray[i] << endl;
    else if (runTimeArray[i] == runTimeArray2[4])
      cout << setw(20) << left << "Quick Sort" << setw(20) << left << quickSortTime << setw(20) << left << quickSortTime2 << setw(20) << left << runTimeArray[i] << endl;
    else if (runTimeArray[i] == runTimeArray2[5])
      cout << setw(20) << left << "Heap Sort" << setw(20) << left << heapSortTime << setw(20) << left << heapSortTime2 << setw(20) << left << runTimeArray[i] << endl;
  }

}

//print function
void printArray(double array[], int size)
{
  for (int i = 0; i < size; i++)
  cout << array[i] << endl;
}


//generate an array of numbers 0 - 1 of size size
void datasetGenerator(double array[], int size)
{

  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_real_distribution<float> distr(0, 1);
  for (int i = 0; i < size; i++)
  {
    array[i] = distr(eng);
  }
}

//duplicate array for re-sorting
void duplicateArray(double arrayToCopy[], double copyOfArray[], int size)
{
  for (int i = 0; i < size; i++)
  {
    copyOfArray[i] = arrayToCopy[i];
  }
}

//Selection sort functions
void swap(double *num1, double *num2)
{
  double temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

int selectionSort(double array[], int size)
{
  int selectionSortTime;
  auto start = high_resolution_clock::now();
  for (int i = 0; i < size-1 ; i++)
  {
    int minimumIndex = i;
    for (int j = i+1; j < size; j++)
    if (array[j] < array[minimumIndex])
        minimumIndex = j;

      swap(&array[minimumIndex], &array[i]);

  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  selectionSortTime = duration.count();

  return selectionSortTime;
}

//Insertion sort functions
int insertionSort(double array[], int size)
{
  int insertionSortTime;
  auto start = high_resolution_clock::now();
  int i, j;
  double key;
  for (i = 1; i < size; i++)
  {
    key = array[i];
    j = i -1;

    while (j >= 0 && array[j] > key)
    {
      array[j+1] = array[j];
      j = j-1;
    }
    array[j+1] = key;

  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  insertionSortTime = duration.count();

  return insertionSortTime;
}

//Bubble sort functions

int  bubbleSort(double arr[], int n)
{
    int bubbleSortTime;
    auto start = high_resolution_clock::now();
    int i, j;
    for (i = 0; i < n-1; i++)

    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);

            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            bubbleSortTime = duration.count();

            return bubbleSortTime;
}


//merge sort functions

void merge(double *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
int mergeSort(double *array, int l, int r)
{
  int mergeSortTime;
  auto start = high_resolution_clock::now();
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);




   }
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);
   mergeSortTime = duration.count();
   return mergeSortTime;
 }


 //quick sort functions
 int partition (double arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int quickSort(double arr[], int low, int high)
{
  int quickSortTime;
  auto start = high_resolution_clock::now();
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
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    quickSortTime = duration.count();
    return quickSortTime;
}

//heap sort functions
void heapify(double arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

int heapSort(double arr[], int n)
{
  int heapSortTime;
  auto start = high_resolution_clock::now();
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    heapSortTime = duration.count();
    return heapSortTime;
}
