# Pilot Project for Anti-Patterns in Multi-Language Systems

## Java & C (JNI)

### Information about some files

* _config.properties_: values of the parameters of code smells and antipatterns
* _JNILIB.dll_: library with all C functions

### How to use _config.parameters_ in a Java class


```java
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Properties;

class SomeAntiPattern {

	private static void someMethod() throws FileNotFoundException, IOException {
		Path appConfigPath = Paths.get("rsc/config.properties").toAbsolutePath().normalize();
		Properties params = new Properties();
		params.load(new FileInputStream(appConfigPath.toString()));
		String aParam = appProps.getProperty("SomeAntiPattern.Param");
		...
	}

}
```
