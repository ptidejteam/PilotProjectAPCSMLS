package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class NotHandlingExceptions {

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	public native char getCharField(String fieldName);

	char charField = 'a';

	public static void main(String args[]) {
		NotHandlingExceptions test = new NotHandlingExceptions();
		System.out.println("*********** Code Smell: Not Handling Exceptions across Languages ***************");
		System.out.println("Value of field \"charField\": " + test.getCharField("charField"));
		System.out.println("Value of non-existent field: ");
		System.out.println(test.getCharField("nonExistent"));
	}

}
