/*
Zach, Colin, Stephen, Brad, and Alex
Dr. Williams
Algorithms Project Code
*/

#include<iostream>
#include<cstdlib>
#include<array>
// #include<ctime>
#include<sys/time.h>

using namespace std;

//Selection Sort and Merge Sort: Zach Koontz
void swap_ours(int arr[], int x, int p);
void selectionSort(int arr[], int n);
void merge(int arr[], int start, int mid, int end);
void mergeSort(int arr[], int start, int end);

//Heap Sort and Bubble Sort: Alex McClellan
//Heap Sort functions from GeeksForGeeks.com 
void heapify(int arr[], int heapSize, int i);
void heapSort(int arr[], int heapSize);
void bubbleSort(int arr[], int arraySize);
int* arrayGenerator(int arr[], int n);

//Exchange Sort: Stephen  
void exchangeSort(int arr[], int z, int &swaps, int &compares);

//Insertion Sort: Brad 
void insertionSort(int arr[], int n);

//Array copy_ours function: Stephen
void copy_ours(int arrA[], const int arrB[], int z);

//quickSort: Colin McCarrie
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high, int &compares);

int main()
{
    int randomArray[1000], fewUnique[1000], arraySize = 0, heapSize, n;
    float runtime1, runtime2, runtime3, runtime4, runtime5, runtime6, runtime7, runtime8, runtime9, runtime10, runtime11, runtime12, runtime13, runtime14;
    struct timeval tstart, tend;
    int size;
    cout<<"Enter the size of the data set: ";
    cin>>size;
    cout<<endl;
    //Random Array Generator
    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        int x = rand() % 1000;
        randomArray[i] = x;
        arraySize++;
    }
    
    //Array Size Variables for Functions
    heapSize = arraySize;
    n = arraySize;

    //Few Unique Array
    int* ptr = arrayGenerator(fewUnique, n);

    //Make copies of randomArray to pass same array to functions
    //Exchange sort: Stephen
    int swaps = 0;
    int compares = 0;
    int exgList[n];
    copy_ours(exgList, randomArray, n);

    //Exchange Sort: Random
    gettimeofday(&tstart, NULL);
    exchangeSort(exgList, n, swaps, compares);
    gettimeofday(&tend, NULL);
    cout << "List sorted with exchange sort. Compares: " << compares << " swaps: " << swaps << endl;
    runtime1 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Exchange Sort (Random) Time: " << runtime1 << endl;
    
    //Exchange Sort: Few Unique
    gettimeofday(&tstart, NULL);
    exchangeSort(ptr, n, swaps, compares);
    gettimeofday(&tend, NULL);
    runtime8 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Exchange Sort (Few Unique) Time: " << runtime8 << endl<<endl;

    //Insertion Sort
    int insList[n];
    copy_ours(insList, randomArray, n);

    //Insertion Sort: Random
    gettimeofday(&tstart, NULL);
    insertionSort(insList, n);
    gettimeofday(&tend, NULL);
    cout << "List sorted with insertion sort. Compares: " << compares << endl;
    runtime2 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Insertion Sort (Random) Time: " << runtime2 << endl;

    //Insertion Sort: Few Unique
    gettimeofday(&tstart, NULL);
    insertionSort(ptr, n);
    gettimeofday(&tend, NULL);
    runtime9 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Insertion Sort (Few Unique) Time: " << runtime9 << endl<<endl;

    //Quicksort
    int listOints[n];
    copy_ours(listOints, randomArray, n);
    int quick_count = 0;
    //Quicksort: Random
    gettimeofday(&tstart, NULL);
    quickSort(randomArray,0, n-1, quick_count);
    gettimeofday(&tend, NULL);
    runtime3 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Quicksort (Random) Time: " << runtime3 << endl;
    cout << "-Quicksort (Random) Counts: " << quick_count << endl;
    quick_count = 0;
    //Quicksort: Few Unique
    gettimeofday(&tstart, NULL);
    quickSort(ptr,0, n-1, quick_count);
    gettimeofday(&tend, NULL);
    runtime10 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Quicksort (Few Unique) Time: " << runtime10 << endl;
    cout << "-Quicksort (Few Unique) Counts: " << quick_count << endl<<endl;
    
    //Bubble Sort
    int bubbleList[n];
    copy_ours(bubbleList, randomArray, n);

    //Bubble Sort: Random
    gettimeofday(&tstart, NULL);
    bubbleSort(bubbleList,n);
    gettimeofday(&tend, NULL);
    runtime4 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Bubble Sort (Random) Time: " << runtime4 << endl;

    //Bubble Sort: Few Unique
    gettimeofday(&tstart, NULL);
    bubbleSort(ptr,n);
    gettimeofday(&tend, NULL);
    runtime11 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Bubble Sort (Few Unique) Time: " << runtime11 << endl<<endl;

    //Heap Sort
    int heapList[n];
    copy_ours(heapList, randomArray, n);

    //Heap Sort: Random
    gettimeofday(&tstart, NULL);
    heapSort(heapList,n);
    gettimeofday(&tend, NULL);
    runtime5 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Heap Sort (Random) Time: " << runtime5 << endl;

    //Heap Sort: Few Unique
    gettimeofday(&tstart, NULL);
    heapSort(ptr,n);
    gettimeofday(&tend, NULL);
    runtime12 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Heap Sort (Few Unique) Time: " << runtime12 << endl;

    //Merge Sort
    int mergeList[n];
    copy_ours(mergeList, randomArray, n);

    //Merge Sort: Random
    gettimeofday(&tstart, NULL);
    mergeSort(mergeList,0,n-1);
    gettimeofday(&tend, NULL);
    runtime6 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Merge Sort (Random) Time: " << runtime6 << endl;

    //Merge Sort: Few Unique
    gettimeofday(&tstart, NULL);
    mergeSort(ptr,0,n-1);
    gettimeofday(&tend, NULL);
    runtime13 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Merge Sort (Few Unique) Time: " << runtime13 << endl;

    //Selection Sort
    int selectionList[n];
    copy_ours(selectionList, randomArray, n);

    //Selection Sort: Random
    gettimeofday(&tstart, NULL);
    selectionSort(selectionList,n);
    gettimeofday(&tend, NULL);
    runtime7 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Selection Sort (Random) Time: " << runtime7 << endl;

    //Selection Sort: Few Unique
    gettimeofday(&tstart, NULL);
    selectionSort(ptr,n);
    gettimeofday(&tend, NULL);
    runtime14 = tend.tv_sec - tstart.tv_sec + (tend.tv_usec - tstart.tv_usec)/ 1.e3;
    cout << "Selection Sort (Few Unique) Time: " << runtime14 << endl;

    return 0;
}

//swap_ours function for the selection sort: Zach Koontz
void swap_ours(int arr[], int first, int second) {
    int temp = arr[second];
    arr[second] = arr[first];
    arr[first] = temp;
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
        swap_ours(arr, minIndex, i);
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
    swap_ours(arr, i, largest);
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
    swap_ours(arr, 0, i);

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
void exchangeSort(int arr[], int z, int &swaps, int &compares)
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
                swap_ours(arr, j, n);
            }
            compares++;
        }
    }
}

//Insertion Sort: Brad 
void insertionSort(int arr[], int n)
{
    int i, key, j, counter;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            counter++;
        }
        arr[j + 1] = key;
    }
}

//Array copy_ours function: Stephen
void copy_ours(int arrA[], const int arrB[], int z)
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
            swap_ours(arr, i, j);
        }
    }
    swap_ours(arr, (i + 1), high);
    return (i + 1);
}
 
//QUICK SORT FUNCTION: COLIN
void quickSort(int arr[], int low, int high, int &compares)
{
    if (low < high)
    {
        compares++;
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1, compares);
        quickSort(arr, pi + 1, high, compares);
    }
}

int* arrayGenerator(int arr[], int n)
{
  srand(time(0));

  //First integer
  int x = rand() % n;

  for (int i = 0; i < n / 4; i++)
  {
    x = arr[i];
  }

  //Second integer
  x = rand() % n;

  for (int j = 0; j < n / 4; j++)
  {
    x = arr[j];
  }

  //Third integer
  x = rand() % 1000;

  for (int k = 0; k < n / 4; k++)
  {
    x = arr[k];
  }

  //Fourth integer
  x = rand() % 1000;

  for (int l = 0; l < n / 4; l++)
  {
    x = arr[l];
  }

  return arr;
}