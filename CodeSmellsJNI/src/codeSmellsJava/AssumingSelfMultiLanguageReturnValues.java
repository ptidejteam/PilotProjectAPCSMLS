package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class AssumingSelfMultiLanguageReturnValues {
	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

//	public static void output() {
//		System.out.println("Output from class");
//	}

	public native void callMethodOutputFromClass();

	public static void main(String args[]) {
		AssumingSelfMultiLanguageReturnValues test = new AssumingSelfMultiLanguageReturnValues();
		System.out.println("*********** Code Smell: Assuming Safe Multi-Language Return Values ***************");
		test.callMethodOutputFromClass();
	}
}
