import java.util.Scanner;
class Mat2{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of rows of mat1");
		int row = sc.nextInt();
		System.out.println("Enter number of columns of mat1 or number of rows of mat2");
		int columns = sc.nextInt();
		System.out.println("Enter number of columns of mat2");
		int col2 = sc.nextInt();
		int[][] mat1 = new int[row][columns];
		int[][] mat2 = new int[columns][col2];
		int[][] mat3 = new int[row][col2];
		System.out.println("Enter vals of mat1");
		for (int i=0;i<row;i++){
			for (int j=0;j<columns;j++){
				System.out.println("Enter value for ["+i+"]["+j+"]");
				mat1[i][j]=sc.nextInt();
				}
			}
		System.out.println("Enter vals of mat2");
		for (int i=0;i<columns;i++){
			for (int j=0;j<col2;j++){
				System.out.println("Enter value for ["+i+"]["+j+"]");
				mat2[i][j]=sc.nextInt();
				}
			}
		for (int i=0;i<row;i++){
			for (int j=0;j<col2;j++){
				mat3[i][j]=0;
				for(int k=0;k<columns;k++){
					mat3[i][j]+=mat1[i][k]*mat2[k][j];
				}
			}
		}
		System.out.println("Sum of the matrices is:");
		for (int i=0;i<row;i++){
			for (int j=0;j<col2;j++){
				System.out.print(mat3[i][j]+" ");
				}
			System.out.println();
		}
	}

}
		
