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

	public native int goThroughArray(Integer[] numbers);

	public static void main(String args[]) {
		LocalReferencesAbuse test = new LocalReferencesAbuse();
		int length = 100;
		Integer[] numbers = new Integer[length];
		for (int i = 0; i < length; i++)
			numbers[i] = i;
		if (test.goThroughArray(numbers) == 0)
			System.out.println("Test of code smell \"Local References Abuse\"");
		else
			System.out.println("Problem in test of code smell \"Local References Abuse\"");
	}
}
