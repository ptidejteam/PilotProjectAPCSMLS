package noCodeSmell;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class NoCodeSmell {

	static {
		AccessController.doPrivileged(
			new PrivilegedAction <Void>()  {
				public  Void  run ()   {
					System.loadLibrary ("JNILIB"); // Code smell "Not using relative path"
					return  null ;
					}
				});
		}

	// Instance variables
	int number = 100;
	String message = "modificationvalue from Java";		

	// Print: Native method that receives a Java String and returns a Java String
	native String sayHello(String msg);

	/* Average */		   
	native double average(int n1, int n2);

	// Declare a native method that modifies the instance variables
	native void modifyInstanceVariable();

	// Array sum
	native double[] sumAndAverage(int[] numbers);


	// Test Driver   
	public static void main(String args[]) {
		NoCodeSmell test = new NoCodeSmell();
		System.out.println("*********** No Code Smell ***************");
		test.modifyInstanceVariable();
		System.out.println("1- In Java, int is " + test.number);
		System.out.println("2- In Java, String is " + test.message);

		// Print
		String result = test.sayHello("Hello from Java");
		System.out.println("3- In Java, the returned string is: " + result);

		// Average
		System.out.println("4- In Java, the average is " + test.average(3, 2));	    


		// Array 
		int[] numbers = {11, 22, 33};
		double[] results = test.sumAndAverage(numbers);
		System.out.println("5- In Java, the sum is " + results[0]);
		System.out.println("6- In Java, the average is " + results[1]);

	}
}
