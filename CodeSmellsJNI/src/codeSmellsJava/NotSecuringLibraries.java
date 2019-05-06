package codeSmellsJava;

public class NotSecuringLibraries {

	static {
		System.loadLibrary("JNILIB");
		// Code smell "Not securing libraries", refactoring Add AccessController
		// Code smell "Not using relative path"
	}

	public native int distance(int time, int speed);

	public static void main(String args[]) {
		NotSecuringLibraries test = new NotSecuringLibraries();
		System.out.println("*********** Code Smell: Not Securing Libraries ***************");
		System.out.println("The distance is " + test.distance(3, 2));
	}
}
