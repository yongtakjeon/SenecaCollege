//RMI Client
import java.rmi.Naming;
import java.rmi.RemoteException;
import java.net.MalformedURLException;
import java.rmi.NotBoundException;
import java.util.ArrayList;
import java.util.List;

public class CarsClient {

	public static void main(String[] args) {
		
		List<Car> cars = new ArrayList<>();
		cars.add(new Car("Toyata Corolla", "Skyblue", 1000));
		cars.add(new Car("Honda Civic", "Purple", 2000));
		cars.add(new Car("Volvo S70", "Yellow", 3000));

		List<Car> registeredCars = new ArrayList<>();
		
		try {
			Registration registration = (Registration) Naming.lookup("rmi://localhost:1099/RegistrationService");

			for (Car car : cars) {
				System.out.printf("Send this car to the server for registration:\n  - ");
				System.out.println(car);
				
				Car registeredCar = registration.registration(car);
				
				System.out.printf("the car returned by the server:\n  - ");
				System.out.println(registeredCar);
				System.out.println();
				
				registeredCars.add(registeredCar);
			}
			
		} catch (MalformedURLException murle) {
			System.out.println("MalformedURLException");
			System.out.println(murle);
		} catch (RemoteException re) {
			System.out.println("RemoteException");
			System.out.println(re);
		} catch (NotBoundException nbe) {
			System.out.println("NotBoundException");
			System.out.println(nbe);
		}
		
	}
}
