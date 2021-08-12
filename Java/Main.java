import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

	// Command-line Arguments Example:
	// 1-Dollar
	// 1-Euro
	// 1-Euro
	// 1-Pound
	// 1-Pound
	// 1-Pound
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		if (args.length == 0) {
			System.out.println("usage: java SharedResource <number of resources>");
			System.exit(0);
		}
		
		int numberOfResources = args.length;
		List<Integer> amounts = new ArrayList<>();
		List<String> currencies = new ArrayList<>();
		
		// retrieving amounts and currencies
		List<String> arguments = Arrays.asList(args);
		arguments.forEach(elem -> {
			
			String[] amountAndCurrency = elem.split("-");
			
			try {
				amounts.add(Integer.parseInt(amountAndCurrency[0]));
			} catch(NumberFormatException e) {
				e.printStackTrace();
			}
			
			currencies.add(amountAndCurrency[1]);
		});
		
		
		SharedAccount account = new SharedAccount(); // the shared account
		
		Me me = new Me(account, amounts, currencies, numberOfResources);
		Friend friend = new Friend(account, numberOfResources);
		
		me.start();
		friend.start();
	}

}
