//RMI interface
import java.rmi.Remote; 
import java.rmi.RemoteException; 

public interface Registration extends Remote { 
	Car registration(Car car) throws RemoteException;
}