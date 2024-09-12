def get_array_input(array_name):
    MAX_SIZE = 30
    while(True):
        try:
            integers = list(map(int, input(f"Enter integers size upto 30 for {array_name}, separated by spaces : ").split(" ")))
            if(len(integers)>MAX_SIZE):
                print(f" Error : You have entered more than {MAX_SIZE} integers. Please enter upto size {MAX_SIZE}. ")
            else:
              return integers
        except Exception as e:
           print("Error: Invalid input. Please enter only integers.")
           

def insertion_sort(array):
    for i in range(1, len(array)):
        pivot = array[i]
        j = i - 1
        while j >= 0 and pivot < array[j]:
            array[j + 1] = array[j]
            j -= 1
        array[j + 1] = pivot
    return array        

def efficientBubbleSort(array):
    size=len(array)
    for i in range(size-1):
        swapElement=False
        for j in range(size-i-1):
            if array[j]>array[j+1]:
                temp = array[j]
                array[j]=array[j+1]
                array[j+1]=temp
    
    return array

def MERGE(list1, list2):
    mergedList = []
    size1 = len(list1)
    size2 = len(list2)
    index1,index2=0,0    
    lastAdded= None

    while(index1<size1 and index2<size2):
        if(list1[index1] <= list2[index2]):
            if(list1[index1] != lastAdded):
                mergedList.append(list1[index1])
                lastAdded = list1[index1]
            index1+=1
        else:
            if(list2[index2]!= lastAdded):
                mergedList.append(list2[index2])
                lastAdded = list2[index2]
            index2+=1
    
    while index1< size1:
         if(list1[index1] != lastAdded):
                mergedList.append(list1[index1])
                lastAdded = list1[index1]
         index1+=1

    while index1< size1:
        if(list2[index2] != lastAdded):
                mergedList.append(list2[index2])
                lastAdded = list2[index2]
        index2+=1
    return mergedList

def binarySearch(array, target):
    low =0
    high=len(array)-1
    while low <= high:

        mid = low + (high - low)//2

        if target == array[mid]:
            return mid

        elif target > array[mid]:
            low = mid + 1

        else:
            high = mid - 1

    return -1
    
def main():
    list1 = get_array_input("list1")
    list2 = get_array_input("list2")

    print(f"Elements from list1: {list1}")
    print(f"Elements from list2: {list2}")

    sorted_list1 = insertion_sort(list1)
    print(f"Sorted elements of List1 by Insertion sort are: {sorted_list1}")

    sorted_list2 = insertion_sort(list2)
    print(f"Sorted elements of List1 by Efficient Bubble sort are: {sorted_list2}")

    sorted_list3 = MERGE(sorted_list1, sorted_list2)
    print(f"Sorted elements of List1 and List2 by MERGE sort are: {sorted_list3}")

    while(True):
     target = input("Enter to search element in merged array:")
     if target.isnumeric():
        target_index = binarySearch(sorted_list3,int(target))
        if target_index != -1 :
            print(f" Target element is found at index: {target_index}")
        else:
            print(f" Target element is not found.")
        break
     else:
        print(f"Error: Target should be integer.")
        



    

if __name__ == "__main__":
    main()

  


