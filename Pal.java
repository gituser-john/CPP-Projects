import java.util.Scanner;
class Pal{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter String");
		String str=sc.next();
		String Revstr="";
		for (int i=str.length()-1;i>=0;i--){
			Revstr+=str.charAt(i);
			}
		if (Revstr.equals(str)){
			System.out.println("Its palindrome");
			}
		else{
			System.out.println("Its not a palindrome");
			}
		}
	}
