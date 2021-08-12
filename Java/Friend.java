public class Friend extends Thread {
	private SharedAccount cHold;
	private int numberOfResources;

	// constructor
	public Friend(SharedAccount account, int numOfResources) {
		super("The Friend");
		cHold = account;
		numberOfResources = numOfResources;
	}

	public void run() {
		
		String money;

		for(int i = 0; i < numberOfResources; i++) {
			// sleep for a random interval
			try {
				Thread.sleep( (int) ( Math.random() * 3000 ) );
			} catch(InterruptedException e) {
				System.err.println(e.toString());
			}
			money = cHold.getSharedResource();
		}

	}

}
