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

	private class NestedClass extends Object {
		int a = 1;
		int b = 2;
		int c = 3;
		int d = 4;
		int e = 5;
		int f = 6;
	}

	public native int sumValues(Object anObject);

	public static void main(String args[]) {
		PassingExcessiveObjects test = new PassingExcessiveObjects();
		NestedClass nested = test.new NestedClass();
		System.out.println("The sum is " + test.sumValues(nested));
	}

}
