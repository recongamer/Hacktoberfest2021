import java.util.Arrays;
import java.util.Scanner;

class bubble {
    Scanner input = new Scanner(System.in);

    void bubbleSort(int array[]) {
        int size = array.length;
        System.out.println("Choose Sorting Order:");
        System.out.println("1 for Ascending \n2 for Descending");
        int sortOrder = input.nextInt();
        for (int i = 0; i < size - 1; i++)

            for (int j = 0; j < size - i - 1; j++)
                if (sortOrder == 1) {
                    if (array[j] > array[j + 1]) {
                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                } else {
                    if (array[j] < array[j + 1]) {

                        int temp = array[j];
                        array[j] = array[j + 1];
                        array[j + 1] = temp;
                    }
                }
    }

    public static void main(String args[]) {

        int[] data = {-8, 23, 4, 12, -19};
        bubble bs = new bubble();

        bs.bubbleSort(data);
        System.out.println("Sorted Array in Ascending Order:");
        System.out.println(Arrays.toString(data));
    }
}
