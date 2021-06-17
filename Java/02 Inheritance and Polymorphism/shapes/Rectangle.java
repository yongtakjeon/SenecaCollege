//Name: Yongtak Jun
//Date: June/07/2021

package shapes;

public class Rectangle extends Square {
	private double height;
	
	//constructor
	public Rectangle(double width, double height) throws QuadrangleException {
		super(width);
		if(height <= 0)
			throw new QuadrangleException();
		this.height = height;
	}
	
	//getter
	public double getHeight() {
		return height;
	}
	
	//setter
	public void setHeight(double height) {
		if(height > 0)
			this.height = height;
	}
	
	@Override //implementing getPerimeter() from 'Shape'
	public double getPerimeter() {
		return (2.0 * getWidth()) + (2.0 * height);
	}

	@Override
	public String toString() {
		return String.format("Rectangle {w=%.1f, h=%.1f} perimeter = %.4f\n", getWidth(), height, getPerimeter());
	}
	
}
