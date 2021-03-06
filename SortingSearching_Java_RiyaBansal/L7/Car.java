package Sorting_Searching_7;

public class Car implements Comparable<Car> {

	int speed;
	int price;
	String color;

	public Car(int speed, int price, String color) {

		this.speed = speed;
		this.price = price;
		this.color = color;
	}

	@Override
	public int compareTo(Car other) {
		 return this.speed - other.speed;
		// return other.price - this.price;
		// return this.color.compareTo(other.color);
	}

	@Override
	public String toString() {
		return "S:" + this.speed + " P:" + this.price + " C:" + this.color;
	}
}