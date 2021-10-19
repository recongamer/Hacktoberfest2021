// Selection Sort in Ascending Order
import java.util.*;
public class SelectionSort 
{
    public static void main(String args[])
    {
	Scanner sc= new Scanner(System.in);
	System.out.println("Enter the size of array : ");
	int l= sc.nextInt();
	int arr[]=new int[l];
	System.out.println("Enter the array elements");
	for (int i=0; i<l;i++)
	{
	    arr[i]=sc.nextInt();
	}
        System.out.println("The unsorted array is: ");
	for (int i=0; i<l;i++)
	{
            System.out.print(arr[i]+" ");
	}
        selection_sort(arr);	
        System.out.println("\nThe Sorted Array in Ascending Order after performing Selection Sort is: ");
	for (int i=0; i<l;i++)
	{
            System.out.print(arr[i]+" ");
	}      
    }
    public static void selection_sort(int a[])
    {
        int n = a.length;
        for(int i = 0;i<n-1;i++)
        {
            int min=i;
            for (int j=i+1;j<n;j++)
            {
                if (a[j]<a[min])
                    min=j;
            }
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
    
}
