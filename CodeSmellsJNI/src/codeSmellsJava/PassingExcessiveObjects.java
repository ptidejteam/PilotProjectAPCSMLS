package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class PassingExcessiveObjects {

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;

	public native int sumValues(PassingExcessiveObjects anObject);

	public static void main(String args[]) {
		PassingExcessiveObjects test1 = new PassingExcessiveObjects();
		PassingExcessiveObjects test2 = new PassingExcessiveObjects();
		System.out.println("*********** Code Smell: Passing Excessive Objects ***************");
		System.out.println("The sum is " + test1.sumValues(test1));
		test2.a += 100;
		System.out.println("The sum is " + test1.sumValues(test2));
	}

}
