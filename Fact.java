import java.util.Scanner;

class Fact{
	static int Fact(int n){
		if (n==0){
			return 1;
			}
		return (n*Fact(n-1));
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number");
		int a = sc.nextInt();
		int b = Fact(a);
		System.out.println("The factorial is :"+b);
		}
}
		
