package antiPatternsJava.excessiveInterLanguageCommunication;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class ExcessiveInterLanguageCommunication5 {
	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	public native int square(int n);

	public native int factorial(int n);

	public static void main(String args[]) {
		ExcessiveInterLanguageCommunication5 test = new ExcessiveInterLanguageCommunication5();
		System.out.println("*********** Anti-Pattern: Excessive Inter-language Communication ***************");
		int n = 5;
		int result = javaSquare(n) + javaFactorial(n);

		System.out.println(n + "^2 + " + n + "! is " + result);
	}
	
	public int javaSquare(int n) {
		return square(n);
	}
	
	public int javaFactorial(int n) {
		return factorial(n);
	}
}
