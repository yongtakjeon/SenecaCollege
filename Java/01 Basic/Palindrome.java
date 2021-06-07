//Name: Yongtak Jun
//Date: May/31/2021

import java.util.Arrays;

public class Palindrome {

	public static void main(String[] args) {

		System.out.println("Is Palindrome?");
		
		for(int i = 0; i < args.length; i++) {
			char[] charArr = args[i].toCharArray();
			char[] copiedArr = Arrays.copyOf(charArr, charArr.length);
			char[] newArr = new char[0];
			
			for(int j = 0; j < charArr.length; j++) {
				//Using 'Stack' Class
				newArr = Stack.pushChar(newArr, copiedArr[copiedArr.length - 1]);
				copiedArr = Stack.popChar(copiedArr);
			}

			
			if(Arrays.equals(charArr, newArr))
				System.out.println("Argument " + i + " (" + String.valueOf(charArr) + "): TRUE");
			else
				System.out.println("Argument " + i + " (" + String.valueOf(charArr) + "): FALSE");
		}	
		
	}
	
}
