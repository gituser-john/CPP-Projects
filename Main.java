
class Main{
	public static void main(String[] args) {
		Fish fish = new Fish();
		fish.hunt();
		fish.flee();
		
		Hawk hawk = new Hawk();
		Rabbit rabbit = new Rabbit();
		hawk.hunt();
		rabbit.flee();
	}
}

interface Prey {
	void flee();
}

interface Predator {
	void hunt();
}

class Rabbit implements Prey{
	public void flee() {
		System.out.println("*The rabbit is fleeing*");
        }
}

class Hawk implements Predator{
	public void hunt() {
		System.out.println("*The hawk is hunting*");
        }
}

class Fish implements Prey,Predator{
	public void hunt() {
		System.out.println("*The fish is hunting*");
	}
	
	public void flee() {
		System.out.println("*The fish is fleeing*");
		
	}
}

