/*
Name : PRALESH RAYAMAJHI
 Course : CSC 710 Structure and Design Programming Langauge
 Assignment : 1 
 Question : 1
 Due Date 20 Sept, 2024
 Application : C++
 Task : Sort(bubble and insertion) and Merge(MergeSort) array A and B and search target element by using binary searh.

*/
// here we are using vector type of array so that it can be dynamic and memory efficienent so that program runs smoothly.
#include<iostream>
#include<sstream>
#include<vector>
#include<string>
#include<cctype>
#include<climits>

using namespace std;


// Function to check if a string represents an integer
bool is_integer(const string &s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c) && c != '-' && c != '+') {
            return false;
        }
    }
    return true;
}

vector<int> get_array_input(string array_name){
    const int MAX_SIZE = 30;
    vector<int> integers;
    string input;
    string temp;


    while(true){
        cout << "Enter integers upto size " << MAX_SIZE << " separted by spaces for " << array_name << endl;
        getline(cin, input);
        stringstream ss(input);
        integers.clear();
        bool allIntegers = true;

        while (ss >> temp)
        {
            if (is_integer(temp)){
                integers.push_back(stoi(temp));
            }else{
                cout << "Error: Invalid input element. Enter only integers." << endl;
                allIntegers = false;
                break;
            }
        }
            if (!allIntegers) {
            continue;  // Re-prompt for valid input
        }

        if(integers.size()> MAX_SIZE)
        {
            cout << " Error : You have entered more than "<< MAX_SIZE <<" integers. Please enter upto size "<< MAX_SIZE <<" .";
        }
        else if (allIntegers) {
            return integers;  // If all values are valid, return the list
        }

    }
}

vector<int> insertionSort(vector<int> array) {
    int n = array.size();
    for (int i = 1; i < n; i++)
    {
        int pivot = array[i];
        int j = i;

        while (j > 0 && array[j-1] > pivot) {
            array[j] = array[j-1];
            j--;
        }
        array[j] = pivot;
    }

    return array;
}

// here we are definiing a function using bubble sort

vector<int> efficientBubbleSort(vector<int> array)
{
    int n= array.size();
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(array[j]>array[j+1])
            {
                int temp= array[j];   //to hold temporaray data
                array[j]=array[j+1];
                array[j+1]= temp;
            }
        }
    }
    return array;

}

// here we are now merging those two list or array

vector<int> MERGE(const vector<int> &list1, const vector<int> &list2) {
    vector<int> mergedList;
    int size1 = list1.size();
    int size2 = list2.size();
    int index1 = 0, index2 = 0;
    int lastAdded = INT_MIN;

    //until size of left index is smaller than right loop continues.
     while (index1 < size1 && index2 < size2) {
        if (list1[index1] <= list2[index2]) {
            if (list1[index1] != lastAdded) {
                mergedList.push_back(list1[index1]);
                lastAdded = list1[index1];
            }
            index1++;
        } else {
            if (list2[index2] != lastAdded) {
                mergedList.push_back(list2[index2]);
                lastAdded = list2[index2];
            }
            index2++;
        }
    }

    // Add remaining elements from list1
    while (index1 < size1) {
          if (list1[index1] != lastAdded) {
        mergedList.push_back(list1[index1]);
          lastAdded= list1[index1];
          }
        index1++;
    }

    // Add remaining elements from list2
    while (index2 < size2) {
          if (list2[index2] != lastAdded) {
        mergedList.push_back(list2[index2]);
          lastAdded=list2[index2];
          }
        index2++;
    }

    return mergedList;


}
 // here we are implementing binary search algorithm.
int binarySearch(vector<int> array, int target)
{
    int left =0;
    int right =array.size()-1;
    while (left <= right)
    {
        int mid = left + (right-left)/2;
        if(array[mid]==target)
        {
            return mid;
        }
        else if(target> array[mid])
        {
            left =mid+1;
        }
        else{
            right = mid-1;
        }

    }
    return -1;
}

// starting point of a program.

int main(){
    vector<int> list1 = get_array_input("list1");
    vector<int> list2 = get_array_input("list2");

    //displaying input from user.

    cout << "Elements in list1 are : ";
    for(int num: list1)
    {
        cout << num << " ";
    }
    cout << endl;

    cout << "Elements in list2 are : ";
    for(int num: list2)
    {
        cout<< num << " ";
    }
    cout << endl;

    vector<int> sortedList1 = insertionSort(list1);
    cout << "Sorted elements in list1 by Insertion Sort are : ";
    for(int num: sortedList1)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> sortedList2 = efficientBubbleSort(list2);
    cout << "Sorted elements in list2 by Efficient Bubble Sort are : ";
    for(int num: sortedList2)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> sortedList3 = MERGE(sortedList1, sortedList2);
    cout << "Sorted elements in list1 and list2 by Merge Sort are : ";
    for(int num: sortedList3)
    {
        cout << num << " ";
    }
    cout << endl;


  while (true)
{
    int target, target_index;
    cout << "Enter an integer to search in the merged array:" << endl;
    cin >> target;


    target_index = binarySearch(sortedList3, target);
    if (target_index != -1)
    {
        cout << "Target element is found at index: " << target_index << endl;
    }
    else
    {
        cout << "Target element is not found." << endl;
    }
    break;
}





    return 0;
}



