/*
Zach, Colin, Stephen, and Alex
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





    return 0;
}
