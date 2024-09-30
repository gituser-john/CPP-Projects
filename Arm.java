import java.util.Scanner;

class Arm{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter value :");
		int arm = sc.nextInt();
		int a=arm,b=0,c=0;
		while(a!=0){
			b=a%10;
			c+=(b*b*b);
			a/=10;
			}
		if (c==arm){
			System.out.println("Its Armstrong");
			return;
			}
		else{
			System.out.println("Not Armstrong");
		}
	}
}
		
