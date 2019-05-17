# Pilot Project for Anti-Patterns in Multi-Language Systems

## Java & C (JNI)

### Information about some files

* _config.properties_: values of the parameters of code smells and antipatterns
* _JNILIB.dll_: library with all C functions

### How to use _config.properties_ in a Java class


```java
import java.io.FileInputStream;
import java.io.IOException;
import java.util.Properties;

	
	try {
        	Properties props = new Properties();
			props.load(new FileInputStream("../MLS SAD/rsc/config.properties"));
			int aProp = Integer.parseInt(props.getProperty("SomeCodeSmell.Param"));
		} catch (IOException e) {
			e.printStackTrace();
		}

}
```
