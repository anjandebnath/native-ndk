### What is JNI

Java Native Interface (JNI) It allows certain methods of Java
classes to be implemented natively while letting them be called and used as ordinary Java methods.

### Declaration of Native Methods

The method declaration of stringFromJNI contains the native keyword to
inform the Java compiler that the implementation of this method is provided in another language.

    public native String stringFromJNI();
    

### Loading the Shared Libraries
 
Native methods are compiled into a shared library. This shared
library needs to be loaded first for the virtual machine to find the native method implementations.
The `java.lang.System` class provides two static methods, `load` and `loadLibrary`, for loading shared libraries
during runtime.
The caveat here is that `loadLibrary` will load the shared library as soon as it finds a library with the
same name while going through the Java library path. 

    static {
            System.loadLibrary("native-lib");
        }
        
   
### Implementing the Native Methods

`Java_com_pm_nativeapp01_MainActivity_stringFromJNI()` This explicit function naming allows the
 virtual machine to automatically find native functions in loaded shared libraries  
 
 
### Method Declarations

    JNIEXPORT jstring JNICALL Java_com_example_hellojni_HelloJni_stringFromJNI
    (JNIEnv *, jobject);
    
  JNIEnv, is an interface pointer that **points to a function table** of available JNI 
  jobject, is a Java object reference to the native-lib.cpp class instance. 
  
  
 >> Depending on whether the native code is a C or C++ source file, the syntax for calling JNI functions
differs.  

  - In C code, JNIEnv is a pointer to JNINativeInterface structure.
  - Since the JNI functions in C code do not know
    the current JNI environment, the JNIEnv instance should be passed as the first argument to each JNI
    function call
    
        return (*env)->NewStringUTF(env, "Hello from JNI !");
        
  - In C++ code, JNIEnv is actually a C++ class instance.  
  - Since JNI methods in C++ code have access to the current JNI environment, the JNI method calls do
    not require the JNIEnv instance as an argument.
    
         return env->NewStringUTF("Hello from JNI !");  
         
         
### Instance vs. Static Methods

- Instance methods are associated with a class instance, and they can only be called on a class
  instance.  
  
      JNIEXPORT jstring JNICALL Java_com_example_hellojni_HelloJni_stringFromJNI
      (JNIEnv * env, jobject thiz);
  
- Static methods are not associated with a class instance, and they can be called directly
  from a static context.
  
      JNIEXPORT jstring JNICALL Java_com_example_hellojni_HelloJni_stringFromJNI
      (JNIEnv * env, jclass clazz);
  
  
  

        