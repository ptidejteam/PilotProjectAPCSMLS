package antiPatternsJava.unnecessaryUseOfMultiLanguageProgramming;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class UserFactory {

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	public native User createUser(String name, double balance);
}