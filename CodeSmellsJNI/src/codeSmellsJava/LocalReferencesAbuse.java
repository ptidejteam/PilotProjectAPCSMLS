package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class LocalReferencesAbuse {

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	public native int isAnyElementNull(Integer[] numbers);

	public static void main(String args[]) {
		LocalReferencesAbuse test = new LocalReferencesAbuse();
		System.out.println("*********** Code Smell: Local References Abuse ***************");
		int length = 100;
		Integer[] numbers = new Integer[length];
		for (int i = 0; i < length - 1; i++)
			numbers[i] = i;
		numbers[length - 1] = null;
		int nullElement = test.isAnyElementNull(numbers);
		if (nullElement == -1)
			System.out.println("An exception occurred while going through the array.");
		else if (nullElement == 0)
			System.out.println("There is no null element in the array.");
		else
			System.out.println("There is a null element in the array.");
	}
}
