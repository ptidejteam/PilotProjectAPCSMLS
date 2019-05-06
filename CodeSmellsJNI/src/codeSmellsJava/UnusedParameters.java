package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class UnusedParameters {

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	public native int distance(int time, int speed, int acceleration, int fuelVolume);

	public static void main(String args[]) {
		UnusedParameters test = new UnusedParameters();
		System.out.println("*********** Code Smell: Unused Parameter ***************");
		System.out.println("The distance is " + test.distance(3, 2, 1, 5));
	}
}