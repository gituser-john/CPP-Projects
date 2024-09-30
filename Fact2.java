import java.util.Scanner;

class Fact2{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number");
		int a = sc.nextInt();
		int b = 1;
		for (int i=a;i>0;i--){
			b*=i;
			}
		System.out.println("The factorial is :"+b);
		}
	
}
		
