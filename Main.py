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

def main():
    list1 = get_array_input("list1")
    list2 = get_array_input("list2")

    print(f"Elements from list1: {list1}")
    print(f"Elements from list2: {list2}")

    sorted_list1 = insertion_sort(list1)
    print(f"Sorted elements of List1 by Insertion sort are: {sorted_list1}")

    sorted_list2 = insertion_sort(list2)
    print(f"Sorted elements of List1 by Efficient Bubble sort are: {sorted_list2}")

if __name__ == "__main__":
    main()

  


