package codeSmellsJava;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class NotCachingObjectsElements {

	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	private class User {
		public int group;

		public native void setGroup(int g);

		public native void checkGroup();
	}

	public static void main(String args[]) {
		NotCachingObjectsElements test = new NotCachingObjectsElements();
		User aUser = test.new User();
		User anotherUser = test.new User();
		System.out.println("*********** Code Smell: Not Caching Objects' Elements ***************");
		for (int i = 0; i < 10; i++)
			aUser.setGroup(i);
		aUser.checkGroup();
		anotherUser.checkGroup();
	}

}
