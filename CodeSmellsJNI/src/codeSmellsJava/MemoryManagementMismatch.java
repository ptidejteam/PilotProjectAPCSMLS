package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class MemoryManagementMismatch {

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	native void printStringInC(String msg);

	public static void main(String args[]) {
		MemoryManagementMismatch test = new MemoryManagementMismatch();
		System.out.println("*********** Code Smell: Memory Management Mismatch ***************");
		test.printStringInC("This String should be printed in C code.");
	}
}
