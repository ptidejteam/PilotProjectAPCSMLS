package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class HardCodingLibraries {

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				try {
					System.loadLibrary("JNILIB");
				} catch (UnsatisfiedLinkError e1) {
					try {
						System.loadLibrary("JNILIB"); // some other library
					} catch (UnsatisfiedLinkError e2) {
					}
				}
				return null;
			}
		});
	}

	public native int distance(int time, int speed);

	public static void main(String args[]) {
		HardCodingLibraries test = new HardCodingLibraries();
		System.out.println("*********** Code Smell: Hard Coding Libraries ***************");
		System.out.println("The distance is " + test.distance(3, 2));
	}
}
