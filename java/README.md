# Java Memeory Leek
## Java Memeory Collector
The Java memeory allocation strategy are static allocation, stack allocation and heap allocation. Correspondingly, these three memeory allocation strategy has their major memory area: static meory(also known as method), stack and heap.

### Heap
1. Stores objects, each object include a corresponding class informaiton
2. jvm has only one heap that is shared by all threads, the heap don't store basic type and reference. It only stores objects
3. It is usually allocate and release by developer. If the developer don't release, the os will relese when the program goes out of scope

### Stack
1. Every thread include a stack area, the stack only stores basic data type object and reference, all objects are in the heap
2. Every stack data (primary type and object reference) are private, they are not accessable to other stack
3. The stack is divided into 3 parts: primary and variable, execution context, and functions
4. The compiler automatically allocate and release to store function parameter and local variable

### Method
1. The method is also called static area. It is shared by all thread like heap. The method include all class and static variable
2. The method include unique element in the program, such as class and static variable
3. The global variable and static variable are stored in the same palce, initialzied global variable and static variable share the same area. Uninitialized global and static variable are in the neighboring area.

1. Static set cause memory leak
The use of HashMap and Vector may cause memory leak, these static meory's life cycle are the same as the application. Their reference object can't be released. Therefore they will be referenced by the vector.
For example:
'''
Static Vector v = new Vector(10);
for (int i = 1; i < 100l i++)
{
	Object o = new Object();
	v.add(o);
	o = null;
}
'''
In this case, iteratively allocate Object objects, and adding the allocated object into a Vector. Thus releasing the object itself (o = null) doesn't delete the reference from the Vector, which cause memory leak

2. Remove doesn't work when the element has a different hash(character)
''' 
public static void main(String[] args)
{
	Set<Person> set = new HashSet<Person>();
	Person p1 = new Person(25);
	Person p2 = new Person(26);
	Person p3 = new Person(27);
	set.add(p1);
	set.add(p2);
	set.add(p3);
	p3.setAge(2);
	set.remove(p3);
	set.add(p3);
}
'''

3. Listener
We use Listener in Java. Usually an app will use many Listener. We will allocate a module's function such as addXXXListener() to add Listener. But we usually forget to delete these Listener when deleting these object. Thus causing the opportunity for memeory leak.

4. Connection
Not closing connection such as database (dataSource.getConnection()), internet (socket) and io connection will cause memeory leak unless calling the close() method explicitly. For Resultset and Statement objects there is no need to do explicit releaseing memory, but Connection must be explicitly released.

5. Inside and outside module reference
The inside object's reference is easy to forget. For example, if module A calls module B using
public void registerMsg(Object b);
Call like this must be caucious. Passing object b by reference might make module B store the reference to b, thus whether B release the reference determine if there is memeory leak.

6. Singleton Pattern
Not using Singleton Pattern correctly cause memory leak. If singleton object hold an external refernece, then this object will not be able to be collected by JVM. Consider the following example:
```
class A{
	public A(){
		B.getInstance().setA(this);
	}
}
// B use singleton pattern
class B {
	private A a;
	private static B instance = new B();
	public B(){};
	public static B getInstance(){
		return instance;
	}
	public void setA(A a){
		this.a = a;
	}
}
```
A instance can't be collected. Imaging if A is a complicated object.	
Android memory leak 
set memory leak
If set class only has methods to add element, but don't have the delete methods, the memory will not be relesed properly. 
Singleton cause memory leak 
```
public class AppManager {
	private static AppManager instance;
	private Context context;
	private AppManager(Context context) {
		this.context = context;
	}
	public static AppManager getInstance(Context context) {
		if (instance == null) {
			instance = new AppManager(context);
		}
	return instance;
	}
}
```
If we pass a context of an Activity, when the Context's activity goes out of scope, as the Context reference is hold by the singleton object, its lifecycle will be equal to the life cycle of the entire program. Therefore when the former Activity exits memeory leak occurs.
THe following way is correct:
``````
public class AppManager {
	private static AppManager instance;
	private COntext context;
	private AppManager(Context context) {
		this.context = context.getApplicationContext(); /// make use of context of application
	}
	public static AppManager getInstance(Context context) {
		if (instance == null) {
			instance = new AppManager(context);
		}
		return instance;
	}
}
``````
Otherwise you can add a static method in Application, getContext() which returns the context of Application
``````
context = getApplicationContext();
/**
* Get the global context
* @return a global context object
* /
public static Context getContext() {
	return context;
}
public class AppManager {
	private static AppManager instance;
	private Context context;
	private AppManager() {
		this.context = MyApplication.getContext(); // use the context of Application
	}
	public static AppManager getInstance() {
		if (instance == null) {
			instance = new AppManager();
		}
	return instance;
	}
}
``````