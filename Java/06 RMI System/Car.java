import java.io.*;

// The objects of type Car must be serialized so that they could be sent between server and client.
// It is needed because the communication between both parts is done using serialization.
public class Car implements Serializable {

	private String model;
	private String color;
	private double mileage;
	private String plate;

	public Car( String brand, String name, double m ) {
		model = brand;
		color = name;
		mileage = m;
		plate = "undefined";
	}

	public String toString() {
		return "Model: " + model + ", Color: " + color + 
				", Mileage: " +  mileage + 
				", Plate number: " + plate;
	}

	public void setPlate(String plate) {
		this.plate = plate;
	}
}
