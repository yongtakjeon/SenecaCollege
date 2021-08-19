//RMI Service Implementation
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class RegistrationImpl extends UnicastRemoteObject implements Registration {
	
	// Implementations must have an explicit constructor
	// in order to declare the RemoteException exception.
	public RegistrationImpl() throws RemoteException {
		super();
	}
	
	public Car registration(Car car) throws RemoteException{
		System.out.printf("Received an object from the CLIENT:\n  - ");
		System.out.println(car);
		
		Car registered = car;
		registered.setPlate(Integer.toString(registered.hashCode()));

		System.out.println("Send the object to the CLIENT\n");
		return registered;
	}
}