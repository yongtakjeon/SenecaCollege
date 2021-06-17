//Name: Yongtak Jun
//Date: June/17/2021

package main;

import shapes.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Main {

	//Add Shape object to Shape Array and return the Shape Array
	public static Shape[] addShape(Shape[] shapes, Shape newShape) {
		Shape[] newArr = new Shape[shapes.length + 1];

		for(int i = 0; i < shapes.length; i++)
			newArr[i] = shapes[i];

		newArr[newArr.length - 1] = newShape;

		return newArr;
	}


	//Delete the triangle with the minimum perimeter
	public static Shape[] deleteMinTriangle(Shape[] shapes) {

		// finding the minimum perimeter
		double minPerimeter = -1;

		for (Shape theShape : shapes) {
			if (theShape instanceof Triangle) {

				if(minPerimeter == -1) {
					// if this is the first Triangle of the Shape Array
					minPerimeter = theShape.getPerimeter();

				} else if (minPerimeter > theShape.getPerimeter()){
					// whenever there is a less perimeter, assign it to 'minPerimeter'
					minPerimeter = theShape.getPerimeter();
				}
			}
		}

		//check the number of elements which have to be deleted
		int minNum = 0;

		for (Shape theShape : shapes) {
			if (theShape instanceof Triangle && theShape.getPerimeter() == minPerimeter) {
				minNum++;
			}
		}

		//create new Array
		Shape[] newArr = new Shape[shapes.length - minNum];

		for(int i = 0, j = 0; i < newArr.length; i++, j++) {
			if (shapes[j] instanceof Triangle && shapes[j].getPerimeter() == minPerimeter) {
				j++;
			}

			newArr[i] = shapes[j];
		}

		return newArr;
	}


	//Delete the circle with the maximum perimeter
	public static Shape[] deleteMaxCircle(Shape[] shapes) {

		// finding the maximum perimeter
		double maxPerimeter = 0;

		for (Shape theShape : shapes) {
			if (theShape instanceof Circle) {

				if(maxPerimeter < theShape.getPerimeter()) {
					// whenever there is a bigger perimeter, assign it to 'maxPerimeter'
					maxPerimeter = theShape.getPerimeter();

				}
			}
		}

		//check the number of elements which have to be deleted
		int maxNum = 0;

		for (Shape theShape : shapes) {
			if (theShape instanceof Circle && theShape.getPerimeter() == maxPerimeter) {
				maxNum++;
			}
		}

		//create new Array
		Shape[] newArr = new Shape[shapes.length - maxNum];

		for(int i = 0, j = 0; i < newArr.length; i++, j++) {
			if (shapes[j] instanceof Circle && shapes[j].getPerimeter() == maxPerimeter) {
				j++;
			}

			newArr[i] = shapes[j];
		}

		return newArr;
	}
	
	
	//print the total perimeter of specific shape
	public static void printTotalPerimeter(Shape[] shapes, String shape) {
		double totalPerimeter = 0.0;
		
		if(shape.equals("Circle")) {
			for(Shape theShape : shapes) {
				if(theShape instanceof Circle) {
					totalPerimeter += theShape.getPerimeter();
				}
			}
		}
		else if(shape.equals("Square")) {
			for(Shape theShape : shapes) {
				if(theShape instanceof Square) {
					totalPerimeter += theShape.getPerimeter();
				}
			}
		}
		else if(shape.equals("Rectangle")) {
			for(Shape theShape : shapes) {
				if(theShape instanceof Rectangle) {
					totalPerimeter += theShape.getPerimeter();
				}
			}
		}
		else if(shape.equals("Parallelogram")) {
			for(Shape theShape : shapes) {
				if(theShape instanceof Parallelogram) {
					totalPerimeter += theShape.getPerimeter();
				}
			}
		}
		else if(shape.equals("Triangle")) {
			for(Shape theShape : shapes) {
				if(theShape instanceof Triangle) {
					totalPerimeter += theShape.getPerimeter();
				}
			}
		}
		
		System.out.printf("Total perimeter of %s is: %.4f\n", shape, totalPerimeter);
	}


	public static void main(String[] args) {

		// Task 1
		System.out.println("------->JAC 444 Assignment 1<-------");
		System.out.println("------->Task 1 ... <-------");

		//start from empty Shape Array, and the new Shape object will be added one at a time.
		Shape[] shapes = new Shape[0];
		Shape newShape;
		String s;

		try (BufferedReader br = new BufferedReader(new FileReader("shapes.txt"))) {

			while ((s = br.readLine()) != null) {
				String[] tokens = s.split(",");

				try {

					if(tokens[0].equals("Circle") && tokens.length == 2) {
						newShape = new Circle(Double.parseDouble(tokens[1]));
						shapes = addShape(shapes, newShape);
					}
					else if(tokens[0].equals("Square") && tokens.length == 2) {
						newShape = new Square(Double.parseDouble(tokens[1]));
						shapes = addShape(shapes, newShape);
					}
					else if(tokens[0].equals("Rectangle") && tokens.length == 3) {
						newShape = new Rectangle(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]));
						shapes = addShape(shapes, newShape);
					}
					else if(tokens[0].equals("Parallelogram") && tokens.length == 3) {
						newShape = new Parallelogram(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]));
						shapes = addShape(shapes, newShape);
					}
					else if(tokens[0].equals("Triangle") && tokens.length == 4) {
						newShape = new Triangle(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]), Double.parseDouble(tokens[3]));
						shapes = addShape(shapes, newShape);
					}
				}

				// If you cannot build the geometric shapes with the given values
				// (ex. zero or negative values for dimensions,
				// wrong values for three sides of a triangle, etc.), a custom exception will be thrown.	
				catch (CircleException errMsg) {
					System.out.println("Invalid radius!");
				}
				catch (QuadrangleException errMsg) {
					System.out.println("Invalid side!");
				}
				catch (TriangleException errMsg) {
					System.out.println("Invalid sides(s)!");
				}

			}

		}
		catch (IOException e) {
			System.out.println(e.getMessage());
		}

		System.out.println();
		System.out.println(shapes.length + " shapes were created:");
		for(Shape theShape : shapes) {
			System.out.println(theShape);
		}


		// Task 2
		System.out.println("\n------->Task 2 ... <-------");

		shapes = deleteMinTriangle(shapes);
		shapes = deleteMaxCircle(shapes);
		
		for(Shape theShape : shapes) {
			System.out.println(theShape);
		}
		
		
		// Task 3
		System.out.println("\n------->Task 3 ... <-------");
		printTotalPerimeter(shapes, "Parallelogram");
		printTotalPerimeter(shapes, "Triangle");

	}

}
