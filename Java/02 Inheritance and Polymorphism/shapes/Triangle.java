//Name: Yongtak Jun
//Date: June/07/2021

package shapes;

public class Triangle implements Shape {
	
	private double side1;
	private double side2;
	private double side3;
	
	//constructor
	public Triangle(double side1, double side2, double side3) throws TriangleException {
		
		if(side1<=0 || side2<=0 || side3<=0 ||
			side1 >= side2+side3 || side2 >= side1+side3 || side3 >= side1+side1)
			throw new TriangleException();
		
		this.side1 = side1;
		this.side2 = side2;
		this.side3 = side3;
	}
	
	//setter
	public void setAllSides(double side1, double side2, double side3) {
		this.side1 = side1;
		this.side2 = side2;
		this.side3 = side3;
	}
	
	//getter
	@Override //implementing getPerimeter() from 'Shape'
	public double getPerimeter() {
		return side1 + side2 + side3;
	}

	@Override
	public String toString() {
		return String.format("Triangle {s1=%.1f, s2=%.1f, s3=%.1f} perimeter = %.4f\n", side1, side2, side3, getPerimeter());
	}
}
