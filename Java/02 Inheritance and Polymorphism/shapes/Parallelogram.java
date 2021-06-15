//Name: Yongtak Jun
//Date: June/07/2021

package shapes;

public class Parallelogram extends Rectangle {
	//constructor
	public Parallelogram(double width, double height) throws Exception {
		super(width, height);
	}
	
	@Override
	public String toString() {
		return String.format("Parallelogram {w=%.1f, h=%.1f} perimeter = %.4f\n", getWidth(), getHeight(), getPerimeter());
	}

}
