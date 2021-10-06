/*
Zach, Colin, Stephen, Brad, and Alex
Dr. Williams
Algorithms Project Code
*/

#include<iostream>
#include<cstdlib>
#include<array>
#include<sys/time.h>

using namespace std;

//Selection Sort and Merge Sort: Zach Koontz
void swap(int *x, int *p);
void selectionSort(int arr[], int n);
void merge(int arr[], int start, int mid, int end);
void mergeSort(int arr[], int start, int end);

//Heap Sort and Bubble Sort: Alex McClellan
//Heap Sort functions from GeeksForGeeks.com 
void heapify(int arr[], int heapSize, int i);
void heapSort(int arr[], int heapSize);
void bubbleSort(int arr[], int arraySize);

//exchange and insertion sort: Stephen  
void exchangeSort(int arr[], int z, int swaps, int compares);
void insertionSort(int arr[], int z, int compares);

//Array copy function: Stephen
void copy(int arrA[], const int arrB[], int z);

//quickSort: Colin McCarrie
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
    int randomArray[1000], arraySize = 0, heapSize, n;
    float runtime1, runtime2, runtime3, runtime4, runtime5;
    struct timeval tstart, tend;

    //Random Array Generator
    srand(time(0));

    for (int i = 0; i < 1000; i++)
    {
        int x = rand() % 1000;
        randomArray[i] = x;
        arraySize++;
    }
    
    //Array Size Variables for Functions
    heapSize = arraySize;
    n = arraySize;

    //Make copies of randomArray to pass same array to functions
    //Exchange sort: Stephen
    int swaps = 0, compares = 0;
    int exgList[n];
    copy(exgList, randomArray, n);

    //Exchange Sort: Start Timer
    gettimeofday(&tstart, NULL);
    exchangeSort(exgList, n, swaps, compares);
    
    //Exchange Sort: End Timer
    gettimeofday(&tend, NULL);
    cout << "List sorted with exchange sort. Compares: " << compares << "Swaps: " << swaps << endl;
    runtime1 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e6;
    cout << "Exchange Sort Time: " << runtime1 << endl;

    //Insertion Sort
    int insList[n];
    copy(insList, randomArray, n);

    //Insertion Sort: Start Timer
    gettimeofday(&tstart, NULL);
    insertionSort(insList, n, compares);

    //Insertion Sort: End Timer
    gettimeofday(&tend, NULL);
    cout << "List sorted with insertion sort. Compares: " << compares << endl;
    runtime2 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e6;
    cout << "Insertion Sort Time: " << runtime2 << endl;

    //Quicksort
    int listOints[n];
    copy(listOints, randomArray, n);

    //Quicksort: Start Timer
    gettimeofday(&tstart, NULL);
    quickSort(listOints,0, n-1);

    //Quicksort: End Timer
    gettimeofday(&tend, NULL);
    runtime3 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e6;
    cout << "Insertion Sort Time: " << runtime3 << endl;
    
    //Bubble Sort
    int bubbleList[n];
    copy(bubbleList, randomArray, n);

    //Bubble Sort: Start Timer
    gettimeofday(&tstart, NULL);
    bubbleSort(bubbleList,n);

    //Bubble Sort: End Timer
    gettimeofday(&tend, NULL);
    runtime4 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e6;
    cout << "Bubble Sort Time: " << runtime4 << endl;

    //Heap Sort
    int heapList[n];
    copy(heapList, randomArray, n);

    //Heap Sort: Start Timer
    gettimeofday(&tstart, NULL);
    heapSort(heapList,n);

    //Heap Sort: End Timer
    gettimeofday(&tend, NULL);
    runtime5 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e6;
    cout << "Heap Sort Time: " << runtime5 << endl;

    return 0;
}

//Swap function for the selection sort: Zach Koontz
void swap(int *x, int *p)
{
    int temp = *x;
    *x = *p;
    *p = temp;
}

//selection sort: Zach Koontz
void selectionSort(int arr[], int n)
{
    int i, j, minIndex;
    for (i = 0; i < n-1; i++)
    {
        minIndex = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[minIndex])
            minIndex = j;
        swap(&arr[minIndex], &arr[i]);
    }
}   

//Merge Function: Zach Koontz
void merge(int arr[], int start, int mid, int end)
{
   int length1 = mid - start + 1;
   int length2 = end - mid;  

    int leftArr[length1], rightArr[length2];

  for (int i = 0; i < length1; i++)
    leftArr[i] = arr[start + i];
  for (int j = 0; j < length2; j++)
    rightArr[j] = arr[mid + 1 + j];

  int a, b, c;
  a = 0;
  b = 0;
  c = start;

  while (a < length1 && b < length2) {
    if (leftArr[a] <= rightArr[b]) {
      arr[c] = leftArr[a];
      a++;
    } else {
      arr[c] = rightArr[b];
      b++;
    }
    c++;
  }

  while (a < length1) {
    arr[c] = leftArr[a];
    a++;
    c++;
  }

  while (b < length2) {
    arr[c] = rightArr[b];
    b++;
    c++;
  }
}

//Merge Sort: Zach Koontz
void mergeSort(int arr[], int start, int end)
{
  if(start < end){
     int mid = start + (end - start)/2;
     mergeSort(arr,start,mid);
     mergeSort(arr,mid + 1,end);
     merge(arr, start, mid, end);
  }
}
    
//Heapify Function
void heapify(int arr[], int heapSize, int i)
{
  int largest = i; //Last element becomes root
  int l = 2 * i + 1; //Left element
  int r = 2 * i + 2; //Right element

  //Left > Largest Case
  if (l < heapSize && arr[l] > arr[largest])
  {
      largest = l;
  }

  //Right > Largest Case
  if (r < heapSize && arr[r] > arr[largest])
  {
      largest = r;
  }

  //If Largest isn't the root
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
  }

  //Recursive call
  heapify(arr, heapSize, largest);
}

//Main Heap Sort Function
void heapSort(int arr[], int heapSize)
{
  //Builds the heap
  for (int i = heapSize / 2 - 1; i >= 0; i--)
  {
    heapify(arr, heapSize, i);
  }

  //Removes an element from heap
  for (int i = heapSize - 1; i >= 0; i--)
  {
    //Moves root to the end of the array
    swap(arr[0], arr[i]);

    //Call max heapify on reduced heap
    heapify(arr, i, 0);
  }
}

//Bubble Sort
void bubbleSort(int arr[], int arraySize)
{
  int temp;

  for (int i = 0; i < arraySize; i++)
  {
      //The Bubble
      for (int j = 0; j < arraySize; j++)
      {
          if (arr[j] > arr[j+1])
          {
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
          }
      }
  }
}

//Exchange Sort: Stephen 
void exchangeSort(int arr[], int z, int swaps, int compares)
{
    int length = z;
    int n;
    //int swaps = 0, compares = 0;
    for (int j = 0; j < length-1; j++)
    {
        for(n = j+1; n < length; n++)
        {
            int temp;
            if (arr[j] > arr[n])
            {
                swaps++;
                swap(arr[j], arr[n]);
            }
            compares++;
        }
    }
}

//Insertion Sort: Stephen 
void insertionSort(int arr[], int z, int compares)
{
    int length = z;
    //int compares = 0;
    int i, j, x;
    for(i = 1; i < length; i++)
    {
        x = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>x)
        {
            arr[j+1] = arr[j];
            j--;
            compares++;
        }
        arr[j+1] = x;
    }
}

//Array copy function: Stephen
void copy(int arrA[], const int arrB[], int z)
{
    for(int i=0; i < z; i++)
        arrA[i] = arrB[i];
}


//Partition FUNCTION: COLIN
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
//QUICK SORT FUNCTION: COLIN
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}