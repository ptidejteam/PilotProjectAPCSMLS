package codeSmellsJava;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.security.AccessController;
import java.security.PrivilegedAction;

public class NotUsingRelativePath {

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				Path lib = Paths.get("../CodeSmellsC/Release/JNILIB.dll").toAbsolutePath().normalize();
				System.load(lib.toString());
				return null;
			}
		});
	}

	public native int distance(int time, int speed);

	public static void main(String args[]) {
		NotUsingRelativePath test = new NotUsingRelativePath();

		System.out.println("The distance is " + test.distance(3, 2));
	}
}
