import java.util.Scanner;
class Freq{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter String");
		String str = sc.next();
		System.out.println("Enter character");
		char str2 = sc.next().charAt(0);
		int count=0;
		for (int i=0;i<str.length();i++){
			if (str.charAt(i)==str2){
				count++;
				}
			}
		System.out.println("Frequency of "+str2+" is "+count);
		}
}
		
