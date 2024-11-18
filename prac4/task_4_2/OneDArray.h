#ifndef ONEDARRAY_H_
#define ONEDARRAY_H_
#include <iostream>
using namespace std;


const int DECLARED_SIZE = 10;

class OneDArray{
    private: 
        int arr[DECLARED_SIZE];
        int numberUsed;
    
    public:
        int search(const int a[], int, int);
        void fillArray(int a[], int, int&);
        void start();

};

int OneDArray::search(const int a[], int numberUsed, int target)
{
    int index = 0; 
    bool found = false;
                                                    // loop through every element in the array and compare it to the 
        for(int i = 0; i < numberUsed; i++){        // target variable obtrained from the user. if it is found, set the
            if (a[i] == target) {                   // found boolean to true so in the if statement below it returns the 
                found = true;                       // index/position of the number than the user wanted in the array otherwise
                index = i;                          // return -1 indicating that the number is not in the array.
            }

        }
    
    if (found)
        return index;
    else
        return -1;
}

void OneDArray::fillArray(int a[], int size, int& numberUsed) {
    cout << "Enter up to " << size << " nonnegative integers.\n"
         << "Mark the end of the list with a negative number.\n";

    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < size))
    {
        a[index] = next;
        index++;
        cin >> next;
    }

    numberUsed = index;
}

void OneDArray::start(){
    int arr[DECLARED_SIZE], listSize, target;

    fillArray(arr, DECLARED_SIZE, listSize);

        cout << "Enter a number to search for: ";
        cin >> target;

        int result = search(arr, listSize, target);
        if (result == -1)
            cout << target << " is not on the list.\n";
        else
            cout << target << " is stored in array position " 
                 << result << endl
                 << "(Remember: The first position is 0.)\n";
}




#endif 








