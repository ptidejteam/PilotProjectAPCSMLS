package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class PassiveExcessiveObjects {

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	private class NestedClass {
		int a = 1;
		int b = 2;
		int c = 3;
		int d = 4;
		int e = 5;
		int f = 6;
	}

	public native int sumValues();

	public static void main(String args[]) {
		PassiveExcessiveObjects test = new PassiveExcessiveObjects();
		NestedClass nested = new NestedClass();
		System.out.println("The sum is " + test.sumValues());	  
	}

}
