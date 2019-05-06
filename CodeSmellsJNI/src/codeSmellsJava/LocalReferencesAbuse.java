package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class LocalReferencesAbuse {

	int[] anArray = new int[1000];

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	public native void goThroughArray(Integer[] numbers);

	public static void main(String args[]) {
		LocalReferencesAbuse test = new LocalReferencesAbuse();
		System.out.println("*********** Code Smell: Local References Abuse ***************");
		int length = 100;
		Integer[] numbers = new Integer[length];
		for (int i = 0; i < length; i++)
			numbers[i] = i;
		test.goThroughArray(numbers);
	}
}
