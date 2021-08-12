import java.util.ArrayList;
import java.util.List;

public class SharedAccount {
	private List<Integer> amounts = new ArrayList<>();
	private List<String> currencies = new ArrayList<>();

	public synchronized void setSharedResource(int amount, String currency) {
		
		int totalAmount = amounts.stream().mapToInt(Integer::intValue).sum();
		
		if (totalAmount > 0 && !currencies.get(0).equals(currency)) { // cannot deposit yet, notify once
			System.out.println("Once you deposit some money in some currency, you are not allowed to deposit money in another currency, "
					+ "UNLESS the account balance would be zero.");
		}
		
		while (totalAmount > 0 && !currencies.get(0).equals(currency)) {  // cannot deposit yet
			try {
				System.out.println("Waiting for the Friend to withdraw...");
				wait();
				totalAmount = amounts.stream().mapToInt(Integer::intValue).sum(); // evaluate the amount again
			} catch ( InterruptedException e ) { 
				e.printStackTrace();
			}
		}

		System.err.println( Thread.currentThread().getName() +
				" deposit the money: " + amount + " " + currency);
		
		amounts.add(amount);
		currencies.add(currency);
		notify();  // tell a waiting thread to become ready
	}

	public synchronized String getSharedResource() {
		
		int totalAmount = amounts.stream().mapToInt(Integer::intValue).sum();
		
		while (totalAmount <= 0) {   // cannot withdraw yet
			try { 
				System.out.println("Waiting for Me to deposit...");
				wait();
				totalAmount = amounts.stream().mapToInt(Integer::intValue).sum(); // evaluate the amount again
			} catch (InterruptedException e) { 
				e.printStackTrace();
			}
		}
		
		notify();  // tell a waiting thread to become ready
		System.err.println( Thread.currentThread().getName() +
				" withdraws the money: " + amounts.get(0) + " " + currencies.get(0) + "\n");
		
		String returnVal = amounts.get(0) + " " + currencies.get(0);
		
		// removing after retrieving the value
		amounts.remove(0);
		currencies.remove(0);
		
		return returnVal;
	}

}
