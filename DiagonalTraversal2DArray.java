import java.util.Scanner;

public class DiagonalTraversal2DArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scn = new Scanner(System.in);
		
		int row = scn.nextInt();
		int col = scn.nextInt();
		
		int arr [][] = new int[row][col];
		
		for(int i=0; i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				arr[i][j] = scn.nextInt();
			}
		}
		
    	for(int k=0;k<= row -1;k++)
		{
			int i =k;
			int j =0;
			while(i>=0)
			{
				System.out.print(arr[i][j] + " ");
				i =i-1;
				j=j+1;
				
			}
			System.out.println();
		}
		
		for(int k=1;k<=col-1;k++)
		{
			int i = row -1;
			int j =k;
			
			while(j <= col-1)
			{
				System.out.print(arr[i][j] + " ");
				i =i-1;
				j= j+1;
				
			}
			System.out.println();
		}
	}


}
