//Name: Yongtak Jun
//Date: May/31/2021

public class Stack {

	public static char[] pushChar(char[] charArr, char ch) {

		char[] newArr = new char[charArr.length + 1];

		for(int i = 0; i < charArr.length; i++)
			newArr[i] = charArr[i];

		newArr[newArr.length-1] = ch;

		return newArr;
	}

	public static char[] popChar(char[] charArr) {

		char[] newArr = new char[charArr.length - 1];

		for(int i = 0; i < charArr.length - 1; i++)
			newArr[i] = charArr[i];

		return newArr;
	}
}
