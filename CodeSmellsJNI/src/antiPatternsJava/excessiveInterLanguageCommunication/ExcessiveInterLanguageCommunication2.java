package antiPatternsJava.excessiveInterLanguageCommunication;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class ExcessiveInterLanguageCommunication2 {
	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	public native int square(int n);

	public static void main(String args[]) {
		ExcessiveInterLanguageCommunication2 test = new ExcessiveInterLanguageCommunication2();
		System.out.println("*********** Anti-Pattern: Excessive Inter-language Communication ***************");
		int sumOfSquares = 0;
		// FIRST CASE Too many calls to the same method (outside a loop)
		sumOfSquares += test.square(1);
		sumOfSquares += test.square(2);
		sumOfSquares += test.square(3);
		sumOfSquares += test.square(4);
		sumOfSquares += test.square(5);
		sumOfSquares += test.square(6);

		System.out.println("The sum of the squares from 0 to 6 is " + sumOfSquares);
	}
}
