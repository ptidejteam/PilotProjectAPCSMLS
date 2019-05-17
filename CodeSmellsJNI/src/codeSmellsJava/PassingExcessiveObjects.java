
package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class PassingExcessiveObjects {

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	private class User {
		public int bruttoSalary = 2000;
		public int federalTax = 250;
		public int stateTax = 300;
		public String name = "John Doe";

	}

	public native int getNettoSalary(User user);

	public static void main(String args[]) {
		PassingExcessiveObjects test = new PassingExcessiveObjects();
		User aUser = test.new User();
		System.out.println("*********** Code Smell: Passing Excessive Objects ***************");
		System.out.println("The salary is " + test.getNettoSalary(aUser));
	}

}
