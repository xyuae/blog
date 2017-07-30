/**
 * Created by Xiaojun YU on 2017-07-29.
 */
public class AppMain {
    // when running, the jvm put the information of AppMain into method area
    public static void main(String[] args) // main method is in the method area
    {
        Sample test1 = new Sample("test1"); // test1 is a reference, it is stored in the stack
        // Sample is a user-defined object, it is stored in heap area
        Sample test2 = new Sample("test2");
        test1.printName();
        test2.printName();
    }

    private static class Sample {

        private String name; // when new sample object is created, name reference in stack, name object in heap

        // ctor
        public Sample(String name)
        {
            this.name = name;
        }

        public void printName() { // print method in method area
            System.out.println(name);
        }
    }
}

/**
 系统收到了我们发出的指令，启动了一个JVM thread, 这个进程首先从classpath中找到AppMain.class文件，读取这个文件中的二进制数据，然后把Appmain类的类信息存放到运行时数据区的方法区中。这一过程成为AppMain类的加载过程。
 接着，Java虚拟机定位到方法区中AppMain类的Main()方法的字节码，开始执行它的指令。这个Main()方法的第一条语句就是：
 Sample test1 = new Sample("测试“）；
 1. JVM reach method area, find the class inforamtion of Sample, which is not found.
 So JVM load the Sample class information, and store the inforamtion in the method area
 2. when the information is found, JVM allocate memory for a new Sample instance in the heap area. This Sample instance has a reference that ponts to the class inforamtion in Sample.
 3. In the JVM, every thread has a function call stack to track the function call in the thread execution. stack中的每一个元素就被成为stack帧，每当县城调用一个方法的时候就会向方法stack压入一个新帧。
 这里的帧用来储存方法的参数、局部变量和运算过程中的临时数据。
 位于"="前的test1 是一个在main() function 中定义的变量， 是一个局部变量。因此，他会被舔脚到执行main()方法的主线程的java 方法调用栈中。而"="将把这个test1变量指向堆区中的Sample实例，也就是说，他持有指向Sample实例的引用。

 */