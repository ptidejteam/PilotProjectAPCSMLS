package antiPatternsJava.excessiveInterLanguageCommunication;

import java.security.AccessController;
import java.security.PrivilegedAction;

public class ExcessiveInterLanguageCommunication4 {
	static {
		AccessController.doPrivileged(new PrivilegedAction<Void>() {
			public Void run() {
				System.loadLibrary("JNILIB"); // Code smell "Not using relative path"
				return null;
			}
		});
	}

	public native int a(int n);

	public native int b(int n);

	public native int c(int n);

	public native int d(int n);

	public native int e(int n);

	public native int f(int n);

	public native int g(int n);

	public native int h(int n);

	public native int i(int n);

	public native int j(int n);

	public native int k(int n);

	public native int l(int n);

	public native int m(int n);

	public native int n(int n);

	public native int o(int n);

	public native int p(int n);

	public native int q(int n);

	public native int r(int n);

	public native int s(int n);

	public native int t(int n);

	public native int u(int n);

	public native int v(int n);

	public native int w(int n);

	public native int x(int n);

	public native int y(int n);

	public native int z(int n);

	public static void main(String args[]) {
		ExcessiveInterLanguageCommunication4 test = new ExcessiveInterLanguageCommunication4();
		System.out.println("*********** Anti-Pattern: Excessive Inter-language Communication ***************");

		int result = 0;
		result += test.a(1);
		result += test.b(1);
		result += test.c(1);
		result += test.d(1);
		result += test.e(1);
		result += test.f(1);
		result += test.g(1);
		result += test.h(1);
		result += test.i(1);
		result += test.j(1);
		result += test.k(1);
		result += test.l(1);
		result += test.m(1);
		result += test.n(1);
		result += test.o(1);
		result += test.p(1);
		result += test.q(1);
		result += test.r(1);
		result += test.s(1);
		result += test.t(1);
		result += test.u(1);
		result += test.v(1);
		result += test.w(1);
		result += test.x(1);
		result += test.y(1);
		result += test.z(1);

		System.out.println("The result is " + result);
	}
}
