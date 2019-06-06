package antiPatternsJava.excessiveInterLanguageCommunication;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class ExcessiveInterLanguageCommunication3 {
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
		ExcessiveInterLanguageCommunication3 test = new ExcessiveInterLanguageCommunication3();
		System.out.println("*********** Anti-Pattern: Excessive Inter-language Communication ***************");
		int n = 5;
		int result = test.square(n) + test.factorial(n);

		System.out.println(n + "^2 + " + n + "! is " + result);
	}
}
