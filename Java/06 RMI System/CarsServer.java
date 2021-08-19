//RMI Server
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.AccessException;
import java.rmi.RemoteException;

public class CarsServer {

	public static void main(String args[]) {
		try {
			// Create the object implementation
			Registration obj = new RegistrationImpl();

			// Bind this object instance to the name "RegistrationService"
			Registry registry = LocateRegistry.createRegistry(1099);
			registry.rebind("RegistrationService", obj);

			System.out.println("RegistrationService bound in registry");
			System.out.println("RegistrationService is running");
			System.out.println("** This server is going to register the cars **\n");
			
		} catch (AccessException e) {
			System.err.println("Problem: " + e);
			System.exit(1);
		} catch (RemoteException e) {
			System.err.println("Problem: " + e);
			System.exit(1);
		} 
	}
}
