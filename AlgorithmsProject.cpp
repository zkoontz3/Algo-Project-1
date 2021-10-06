/*
Zach, Colin, Stephen, Brad, and Alex
Dr. Williams
Algorithms Project Code
*/

#include<iostream>
#include<cstdlib>
#include<array>
#include<timercpp>

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
void exchangeSort(int arr[], int z, int& swaps, int& compares);
void insertionSort(int arr[], int z, int& compares);

//Array copy function: Stephen
void copy(int arrA[], const int arrB[], int z);

//insertion: Brad 

//quickSort: Colin McCarrie

int main()
{
    int randomArray[1000], arraySize = 0, heapSize, n;

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
<<<<<<< HEAD
    
    //Make copies of randomArray to pass same array to functions
    //Exchange and Insertion sort: Stephen
    int swaps = 0, compares = 0;
    int exgList[n];
    copy(exgList, randomArray, n);
    exchangeSort(exgList, n, swaps, compares);
    cout << "List sorted with exchange sort. Compres: " << compares << "Swaps: " << swaps << endl;
    int insList[n];
    copy(insList, randomArray, n);
    insertionSort(insList, n, compares);
    cout << "List sorted with exchange sort. Compres: " << compares << endl;

    return 0;
}

>>>>>>> 62d8e5e4ed8107d1593dadfaaa6b2ca4655b264c
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
void exchangeSort(int arr[], int z, int& swaps, int& compares)
{
    int length = z;
    int n;
    int swaps = 0, compares = 0;
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
void insertionSort(int arr[], int z, int& compares)
{
    int length = z;
    int compares = 0;
    int i, j, x;
    for(i = 1; i < length; i++)
    {
        x = arr[i];
        j = i-1;
        while(j>=0 && s[j]>x)
        {
            arr[j+1] = arr[j];
            j--;
            compares++;
        }
        s[j+1] = x;
    }
}

//Array copy function: Stephen
void copy(int arrA[], const int arrB[], int z)
{
    for(int i=0; i < z; i++)
        arrA[i] = arrB[i];
}
