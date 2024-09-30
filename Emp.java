class Emp
{
	public static void main(String[] args)
	{
		
		Officer o = new Officer();
		o.Name="Jonah";
		o.Age=34;
		o.Ph_No="8967452310";
		o.Address="Sulu Mall,Angamaly,Kerala,686665";
		o.Salary=764655;
		o.Specialization="Software Engineer";
		o.print1();
		
		Manager m = new Manager();
		m.Name="Jonahthan";
		m.Age=54;
		m.Ph_No="4567452345";
		m.Address="Lulu Mall,Edapally,Kerala,686765";
		m.Salary=334655;
		m.Department="Hardware Engineer";
		m.print2();
	}
}

class Employee
{
	String Name;
	int Age;
	String Ph_No;
	String Address;
	double Salary;
	void printSalary()
	{
		System.out.println("The salary is : "+Salary);
	}
}
class Officer extends Employee
{
	String Specialization;
	
	void print1(/*String Name,int Age,double Ph_No,String Address,double Salary,String Specialization*/)
	{
		System.out.println("Name : "+Name+"\nAge : "+Age+"\nPhone Number : "+Ph_No+"\nAddress : "+Address+"\nSalary : "+Salary+"\n Specialization : "+Specialization);
	}
}
class Manager extends Employee
{
	String Department;
	
	void print2(/*String Name,int Age,double Ph_No,String Address,double Salary,String Department*/)
	{
		System.out.println("Name : "+Name+"\nAge : "+Age+"\nPhone Number : "+Ph_No+"\nAddress : "+Address+"\nSalary : "+Salary+"\n Department : "+Department);
	}
}

