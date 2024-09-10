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

vector<int> efficientBubbleSort(vector<int> array)
{
    int n= array.size();
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(array[j]>array[j+1])
            {
                int temp= array[j];
                array[j]=array[j+1];
                array[j+1]= temp;
            }
        }
    }
    return array;

}

vector<int> MERGE(const vector<int> &list1, const vector<int> &list2) {
    vector<int> mergedList;
    int size1 = list1.size();
    int size2 = list2.size();
    int index1 = 0, index2 = 0;
    int lastAdded = INT_MIN;

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
        mergedList.push_back(list1[index1]);
        index1++;
    }

    // Add remaining elements from list2
    while (index2 < size2) {
        mergedList.push_back(list2[index2]);
        index2++;
    }

    return mergedList;


}

int main(){
    vector<int> list1 = get_array_input("list1");
    vector<int> list2 = get_array_input("list2");

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

    return 0;
}
