import java.util.Scanner;

public class SpiralTraversal2DArray {

public static void main(String[] args) {
		
		Scanner scn = new Scanner(System.in);
		
		int row = scn.nextInt();
		int col = scn.nextInt();
		
		int arr [][] = new int[row][col];
		
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				arr[i][j] = scn.nextInt();
			}
		}

		printSpiral(row,col,arr);
	}

	private static void printSpiral(int row, int col, int[][] arr) {
		
		int i, k=0,l=0;
		int last_row = row -1,last_col = col -1;
		
		while( k <= last_row && l<= last_col)
		{
			for(i=l;i<=last_col;i++)
			{
				System.out.print(arr[k][i] + " ");
			}
			k++;
			
			for(i=k;i<=last_row;i++)
			{
				System.out.print(arr[i][last_col] + " ");
			}
			last_col--;
			
			if(k<=last_row) {
				for(i=last_col;i>=l;i--)
				{
					System.out.print(arr[last_row][i] + " ");
				}
				last_row--;
			}
			
			if(l<=last_col) {
				for(i=last_row;i>=k;i--) {
					System.out.print(arr[i][l] + " ");
				}
				l++;
			}
		}
	}



}
