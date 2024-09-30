abstract class Shape{
	abstract void numberofsides();
}

class Rect extends Shape{
	void numberofsides(){
		System.out.println("The number of sides is 4");
		}
	}
	
class Tri extends Shape{
	void numberofsides(){
		System.out.println("The number of sides is 3");
		}
	}
	
class Hex extends Shape{
	void numberofsides(){
		System.out.println("The number of sides is 6");
		}
	}
	
class Poly{
	public static void main(String[] args){
	Rect rect = new Rect();
	Tri tri = new Tri();
	Hex hex = new Hex();
	rect.numberofsides();
	tri.numberofsides();
	hex.numberofsides();
	}
	}
		
	
