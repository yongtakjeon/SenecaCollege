//Name: Yongtak Jun
//Date: June/07/2021

package shapes;

public class Square implements Shape {
	private double width;

	//constructor
	public Square(double width) throws QuadrangleException {
		if(width <= 0)
			throw new QuadrangleException();
		this.width = width;
	}

	//getter
	public double getWidth() {
		return width;
	}

	//setter
	public void setWidth(double width) {
		if(width > 0)
			this.width = width;
	}

	@Override //implementing getPerimeter() from 'Shape'
	public double getPerimeter() {
		return 4.0 * width;
	}

	@Override
	public String toString() {
		String returnString;

		// when the number is too small, print it as scientific notation.
		if (width < 0.0001)
			returnString = String.format("Square {s=%.1e} perimeter = %e\n", width, getPerimeter());
		else
			returnString = String.format("Square {s=%.1f} perimeter = %.4f\n", width, getPerimeter());

		return returnString;
	}
}
