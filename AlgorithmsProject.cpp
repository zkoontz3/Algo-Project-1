/*
Zach, Colin, Stephen, Brad, and Alex
Dr. Williams
Algorithms Project Code
*/

#include<iostream>
#include<cstdlib>
#include<array>

using namespace std;

int main()
{
    int randomArray[1000];

    //Random Array Generator
    srand(time(0));

    for (int i = 0; i < 1000; i++)
    {
        int x = rand() % 1000;
        randomArray[i] = x;
    }


    
//selection sort: Zach Koontz
void selectionSort(int arr[], int n) 
{
    int i, j, min, tmp;    
      for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
          if (arr[j] < arr[min])
              min = j;
          if (min != i) {
              tmp = arr[i];
              arr[i] = arr[min];
              arr[min] = tmp;
    }
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
    return 0;
}
