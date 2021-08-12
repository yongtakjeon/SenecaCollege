import java.util.List;

public class Me extends Thread {
	private SharedAccount pHold;
	private List<Integer> amounts;
	private List<String> currencies;
	private int numberOfResources;
	
	// constructor
	public Me(SharedAccount account, List<Integer> amounts, List<String> currencies,int numOfResources) {
		super("I");
		pHold = account;
		this.amounts = amounts;
		this.currencies = currencies;
		numberOfResources = numOfResources;
	}
	
	public void run() {
		for (int i = 0; i < numberOfResources; i++) {
			// sleep for a random interval
			try {
				Thread.sleep( (int) ( Math.random() * 3000 ) );
			} catch(InterruptedException e) {
				System.err.println(e.toString());
			}
			
			pHold.setSharedResource(amounts.get(i), currencies.get(i));
		}

	}

}
