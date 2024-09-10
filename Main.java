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
        //comparing values
        while (index1<list1.size() && index2< list2.size()) {
            if (list1.get(index1)<=list2.get(index2)) {
                mergedList.add(list1.get(index1));
                index1++;
            }
            else{
                mergedList.add(list2.get(index2));
                index2++;
            }
        }
        while (index1 < list1.size()) {
            mergedList.add(list1.get(index1));
            index1++;
        }
        while (index2 < list2.size()) {
            mergedList.add(list2.get(index2));
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

        List<Integer> sorteMedList3= MERGE(list1,list2);
        System.out.println("Sorted elements in list1 and list2 by MERGE Sort are :" + sorteMedList3);

    }
}
