package antiPatternsJava.excessiveInterLanguageCommunication;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class ExcessiveInterLanguageCommunication {
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
		ExcessiveInterLanguageCommunication test = new ExcessiveInterLanguageCommunication();
		System.out.println("*********** Anti-Pattern: Excessive Inter-language Communication ***************");
		int max = 10;
		int sumOfSquares = 0;
		for (int i = 1; i < max; i++)
			sumOfSquares += test.square(i);
		System.out.println("The sum of the squares from 0 to " + max + " is " + sumOfSquares);
	}
}
