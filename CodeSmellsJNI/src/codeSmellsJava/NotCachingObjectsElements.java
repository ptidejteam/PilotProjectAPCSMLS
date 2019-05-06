package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class NotCachingObjectsElements {

	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;
	int e = 5;
	int f = 6;

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	public native int sumValues();

	public static void main(String args[]) {
		NotCachingObjectsElements test = new NotCachingObjectsElements();
		System.out.println("*********** Code Smell: Not Caching Object's Elements ***************");
		System.out.println("The sum is " + test.sumValues());
	}

}
