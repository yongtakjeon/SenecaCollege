//Name: Yongtak Jun
//Date: June/07/2021

package shapes;

import static java.lang.Math.*;

public class Circle implements Shape {
	private double radius;

	//constructor
	public Circle(double radius) throws CircleException {
		if(radius <= 0)
			throw new CircleException();
		this.radius = radius;
	}

	//getter
	public double getRadius() {
		return radius;
	}

	//setter
	public void setRadius(double radius) {
		if(radius > 0)
			this.radius = radius;
	}

	@Override //implementing getPerimeter() from 'Shape'
	public double getPerimeter() {
		return 2.0 * PI * radius;
	}

	@Override
	public String toString() {
		return String.format("Circle {r=%.1f} perimeter = %.4f\n", radius, getPerimeter());
	}
}
