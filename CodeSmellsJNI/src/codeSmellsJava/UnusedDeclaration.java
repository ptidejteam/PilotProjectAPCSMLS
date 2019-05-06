package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class UnusedDeclaration {

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	public native void sayHelloJanuary();

	public native void sayHelloFebruary();

	public native void sayHelloMarch();

	public native void sayHelloApril();

	public native void sayHelloMay();

	public native void sayHelloJune();

	public native void sayHelloJuly();

	public native void sayHelloAugust();

	public native void sayHelloSeptember();

	public native void sayHelloOctober();

	public native void sayHelloNovember();

	public native void sayHelloDecember();

	public native void sayHelloMonday();

	public native void sayHelloTuesday();

	public native void sayHelloWednesday();

	public native void sayHelloThursday();

	public native void sayHelloFriday();

	public native void sayHelloSaturday();

	public native void sayHelloSunday();

	public static void main(String[] args) {
		UnusedDeclaration testImp = new UnusedDeclaration();
		System.out.println("*********** Code Smell: Unused Native Method Declaration ***************");
		testImp.sayHelloJanuary();
		testImp.sayHelloFebruary();
		testImp.sayHelloMarch();
		testImp.sayHelloApril();
		testImp.sayHelloMay();
		testImp.sayHelloJune();
		testImp.sayHelloJuly();
		testImp.sayHelloAugust();

	}
}
