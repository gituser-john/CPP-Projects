import java.util.Scanner;
class Mat{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of rows");
		int row = sc.nextInt();
		System.out.println("Enter number of columns");
		int col = sc.nextInt();
		int[][] mat1 = new int[row][col];
		int[][] mat2 = new int[row][col];
		int[][] mat3 = new int[row][col];
		System.out.println("Enter vals of mat1");
		for (int i=0;i<row;i++){
			for (int j=0;j<col;j++){
				System.out.println("Enter value for ["+i+"]["+j+"]");
				mat1[i][j]=sc.nextInt();
				}
			}
		System.out.println("Enter vals of mat2");
		for (int i=0;i<row;i++){
			for (int j=0;j<col;j++){
				System.out.println("Enter value for ["+i+"]["+j+"]");
				mat2[i][j]=sc.nextInt();
				}
			}
		for (int i=0;i<row;i++){
			for (int j=0;j<col;j++){
				mat3[i][j]=mat1[i][j]+mat2[i][j];
				}
			}
		System.out.println("Sum of the matrices is:");
		for (int i=0;i<row;i++){
			for (int j=0;j<col;j++){
				System.out.print(mat3[i][j]+" ");
				}
			System.out.println();
		}
	}

}
		
