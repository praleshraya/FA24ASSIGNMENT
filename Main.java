import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    private static  final int MAX_SIZE = 30;

    public static List<Integer> insertionSort(List<Integer> array)
    {
        int size= array.size();
        for(int i=1; i<size; i++)
        {
            int pivot = array.get(i);
            int j=i-1;
            while(j>=0 && array.get(j)>pivot)
            {
                array.set(j+1, array.get(j));
                j=j-1;

            }
            array.set(j+1,pivot);
        }
        return array;
    }

    public static List<Integer> efficientBubbleSort(List<Integer> array)
    {
        int size = array.size();
        for(int i=0; i<size-1; i++)
        {
            for(int j=0; j<size-i-1; j++)
            {
                if(array.get(j)>array.get(j+1))
                {
                    int temp=array.get(j);
                    array.set(j, array.get(j+1));
                    array.set(j+1,temp);

                }

            }
        }
        return array;
    }

    public static List<Integer> MERGE(List<Integer> list1, List<Integer> list2)
    {
        List<Integer> mergedList = new ArrayList<>();
        int index1 =0; int index2=0;
        Integer lastAdded= null;
        int size1 = list1.size();
        int size2 = list2.size();
        
        //comparing values
        while (index1 < size1 && index2 < size2) {
            if (list1.get(index1) <= list2.get(index2)) {
                if(!list1.get(index1).equals(lastAdded))
                {
                mergedList.add(list1.get(index1));
                lastAdded = list1.get(index1);
                
                }
                index1+=1;
            }
            else{           
                    if(!list2.get(index2).equals(lastAdded))
                    {
                    mergedList.add(list2.get(index2));
                    lastAdded = list2.get(index2);
                    
                    }
                    index2+=1;
            }
        }
        while (index1 < size1) 
        {  
        if (list1.get(index1) <= list1.get(index1)) {

            mergedList.add(list1.get(index1));
            lastAdded=list1.get(index1);
        }
        index2+=1;
    }
        while (index2 < size2) {
            if (list2.get(index2) <= list2.get(index2)) {

            mergedList.add(list2.get(index2));
            lastAdded=list2.get(index2);
         
        }
        index2++;
    }           
    
    return mergedList;
}


    public static List<Integer> getIntegerList(String listName){
        Scanner sc= new Scanner(System.in);
        List<Integer> integers = new ArrayList<>();
        
        while (true) {
            System.out.println("Enter integers upto size "+ MAX_SIZE + " separted by spaces for " + listName +" : ");
            String input = sc.nextLine();
            String[] inputArray = input.split(" ");

            if(inputArray.length>MAX_SIZE)
            {
                System.out.println("Error : You have entered more than "+ MAX_SIZE +" integers. Please enter upto size "+ MAX_SIZE +" .");
            }
            else{
                 try {
                    for (String s : inputArray) {
                        integers.add(Integer.parseInt(s));
                    }
                    return integers;
                } catch (NumberFormatException e) {
                    System.out.println("Invalid input, please enter only integers.");
                    integers.clear();  // Clear the list if the input is invalid
                }
            }
        }
        
       
    }

     public static int binarySearch(List<Integer> array, int target)
    {
        int low=0;
        int high = array.size()-1;
        

        while (low<=high) {
            int mid =low+(high-low)/2;
            if(target==array.get(mid))
            {
                return mid;
            }
            else if(target>array.get(mid))
            {
                low= mid+1;
            }
            else {
                high = mid-1;
            }
        }

            return -1;
    }
    public static void main(String[] args)
    {

        List<Integer> list1 = getIntegerList("list1");
        List<Integer> list2 = getIntegerList("list2");

        System.out.println("Elements of list1 : " + list1);
        System.out.println("Elements of list2 : " + list2); 
        
        List<Integer> sortedList1= insertionSort(list1);
        System.out.println("Sorted elements in list1 by Insertion Sort are :" + sortedList1);

        List<Integer> sortedList2= efficientBubbleSort(list2);
        System.out.println("Sorted elements in list1 by Efficient Bubble Sort are :" + sortedList2);

        List<Integer> sortedList3= MERGE(sortedList1, sortedList2);
        System.out.println("Sorted elements in list1 and list2 by MERGE Sort are :" + sortedList3);

        Scanner sc= new Scanner(System.in);

        while (true) {
        System.out.println("Enter to search element in merged array:");
        int target = sc.nextInt();
        int target_index = binarySearch(sortedList3, target);
        if(target_index == -1)
        {
            System.out.println("Target element not found in merged array.");
        }
        else{
            System.out.println("Target element is found at index "+target_index+" .");
        }

        }
        

    }
}
