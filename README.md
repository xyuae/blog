<<<<<<< HEAD
# Blog -- Technical Knowledge
- [HashMap's implementation](http://yikun.github.io/2015/04/01/Java-HashMap%E5%B7%A5%E4%BD%9C%E5%8E%9F%E7%90%86%E5%8F%8A%E5%AE%9E%E7%8E%B0/)
- [Lifecycle of a Thread](http://www.cnblogs.com/sunddenly/p/4106562.html)
- [A story about thread](http://mp.weixin.qq.com/s?__biz=MjM5NzA1MTcyMA==&mid=403498894&idx=2&sn=219c1a6001b5bb7e6bdc7963b1af8450&scene=2&srcid=0330UDNmQ2GlTOLo1CY8IZfH&from=timeline&isappinstalled=0#wechat_redirect) Very nice to read
- [Cache](http://blog.chinaunix.net/uid-26817832-id-3244916.html)
=======
# blog Interview preparation
* [HashMap's implementation](http://yikun.github.io/2015/04/01/Java-HashMap%E5%B7%A5%E4%BD%9C%E5%8E%9F%E7%90%86%E5%8F%8A%E5%AE%9E%E7%8E%B0/)
* [Lifecycle of a Thread](http://www.cnblogs.com/sunddenly/p/4106562.html)
* [A story about thread](http://mp.weixin.qq.com/s?__biz=MjM5NzA1MTcyMA==&mid=403498894&idx=2&sn=219c1a6001b5bb7e6bdc7963b1af8450&scene=2&srcid=0330UDNmQ2GlTOLo1CY8IZfH&from=timeline&isappinstalled=0#wechat_redirect) Very nice to read
* [Cache](http://blog.chinaunix.net/uid-26817832-id-3244916.html)
* [Interview SDE2](http://www.geeksforgeeks.org/amazon-interview-set-25/)
* [Phone Interview](http://cv.qiaobutang.com/post/55c3148f0cf242d2e7fded7c)
* [static and final keyword in java](https://www.youtube.com/watch?v=gTk_F61_-9k)
* [Interview fulltime](http://codeanalysis111.blogspot.ca/2014/12/blog-post.html)
* [Allocation of memeory in stack and heap in JVM](http://lz12366.iteye.com/blog/639873) Find out what static memeory is and where class and funciton are stored
* [Amortized analysis](https://en.wikipedia.org/wiki/Amortized_analysis)
* [HashMap get and put complexity](http://stackoverflow.com/questions/4553624/hashmap-get-put-complexity)
* [Hash table and hash mehtods](https://en.wikipedia.org/wiki/Hash_table)
* [Heap](https://www.youtube.com/watch?v=t0Cq6tVNRBA)
>>>>>>> fd604201c4c6d0955e556115937d8460bd7c840c


## Intern Experience
* [Do well in intern](https://www.quora.com/What-are-the-best-ways-to-excel-in-a-summer-internship/answer/Vishnu-Jayavel)
* 

## LeetCode
* [Valid-parentheses](https://leetcode.com/problems/valid-parentheses)
* [Lowest common ancestor](https://www.youtube.com/watch?v=GnliEfQo114)
* [QuickSort in linkedlist](http://www.cnblogs.com/danbing/p/5148608.html)
* 

## OOP
* What is oop?: Programming using objects/ organize things using objects, three characteristics are encapsulation, polymorphism, and inheritance
    1. Modularity: codes are modular, easy to change one module without affecting others
    2. Information-hiding: information is hidden from other objects, it is easier to change internal state without effecting external interface
    3. Code reuse
    4. Extensibility: Extra functionality is easy to add without affecting other functions
* Encapsulatin: hide detialed information of an object to the public
* Polymorphism: Treat an ojects in many forms. Let one object to be used as another object.
* Inheritance: Describes the relatinship between parent class and child class. The child class inheirts the fields and behavior of the parent class.
* 

## Linux
* [Linux commands](https://www.youtube.com/watch?v=l0QGLMwR-lY)
* The kernel version: uname -v; uname -a
* The ip address of current system: ifconfig eth0; ip addr show eth0
* Check free space left in system: df -ah
* How would you start/check/stop a service in system: service udev status; systemctl status udev;
* How to check the disk use of a directory: du -sh directory
* How to check network sockets/net stack/tcp udp services: 
* How to check CPU usage of a given process: ps aux | grep <ssh>; ps aux shows all the current running processes
* How to look for things you don't know: man <command>, goole, stackoverflow
* [-find](https://www.youtube.com/watch?v=KCVaNb_zOuw) How to look for a file in linux: find . -type f -name <test.txt>; -name case sensitivy; -iname case insensitive

## Note
* Hash Map is a Hash table based implementaion of the Map interface. It does not guarantee that the order will remain constant over time.
* HashMap has two important factor: capacity and load factor
* Initial capacity is the number of buckets in the hash table
* Load factor is a measure of how full the hash table is allowed to get before its capacity is automatically increased
* work flow of put: hashCode(key) -> index = hashCode % capacity -> store in Map[index], when collision, store in the beginning of the linkedList. 
* Difference between Abstract class and Interface
    1. A class can extends one abstract class but multiple interface
    2. You can implement an abstract class method, an interface has no concrete method implementations
    3. An interface can only hold constants fields(final), while an abstract class can have non-constant fileds or non-initialized fields 
    4. All the abstract method signatures in an abstract class requires the keyword "abstract" appended in front of the modifier list, but it is not required in an interface
* Add the modifier final in front of a field makes the field constant, the content of the field cannot be changed
* Add the modifier 'static' in front of a field makes a persisting field(one and only one copy in the memory map), so that the value in the field persists across all instances of the class
* Add the modifier 'static' in front of a method allows the method to be called/invoked with the class itself, without creating an instance of the class. 
* [LinkedList and ArrayList in C++](http://alrightchiu.github.io/SecondRound/linked-list-introjian-jie.html) 
* ArrayList
    1. O(1) random access
    2. O(n) resize
    3. O(n) delete
    3. Save memeory space
* LinkedLIst
    1. No need to resize
    2. O(n) access
    3. Waste memory space for pointer
    4. O(1) delete
* Method override： a programmer can choose to re-implement the contents in a method inherited from the superclass, compiler annotation @Override is optional
* Method overload: a programmer can design multiple methods with identical name but different input parameter list and return types, convenient for downstream programmers
* Polymorphism is an application of inheritance in a way that downstream programmers can invoke methods that are common among all the similar objects without the detail knowledge of each object.
* Scope of field:
    1. public: accessible from any class
    2. private: accessible from this class
    3. protected: accessible only from this class and its subclasses
    4. no modifier: accessible from any class within the same package, don't use
    5. 
* Final scope:
    1. class and nested classes: cannot be subclassed
    2. field: its value cannot be changed
    3. it cannot be overriden by a subclass
* Static:
    1. Nested class: not an inner class
    2. Field: exactly one instance exisits for all objects of the class
    3. Exactly one instance exists for all objects of the class.
* HashMap: A hashtable use a hash function to compute an index to an array of buckets or slots. Hash collision happens where the hash function generates the same index for more than one key 
    1. get amortized O(1) without hash collision
    2. get O(1) without hash collision
    3. Methods to resolve collision: open addressing - linear probing, double probing; seperate chaining - using linkedlist

## Design
* Aggregation: B is part of A, musicion is part of a band, band has many musicions
* Composition: no sharing policy, room is part of a building, building is composed of rooms. 
* Association: Committe formulates the policy 

## Anroid
[Problem installing APK](http://stackoverflow.com/questions/37015030/session-app-error-installing-apk) rename the domain name might fix it.
[Import properly](https://learn.uwaterloo.ca/d2l/le/content/302446/viewContent/1754074/View)


## Amazon
* Consumer Website: Consumer website owns the technology stack for Amazon.com websites worldwide form the front-end customer experience to back-end service technology
and website hosting. This includes ownership of core website pages like gateway, nav, detail page, and checkout, along with localization, media services, website rendering,
content management, content optimizaiton, weblab, clickstream, web analytics, Robot Detection and Mitigation, traffic routing, DDoS protection, service frameworks, operations
automation and more.
* eCFT is responsible for protecting customer and corporate data acrss all f Amazon, whether it's the retail websie, Kindle or AWS, we secure the data. Every aspect
of our business interacts with our systems, if our systems are not up and running the company stops, and if we're not rapidly delivering new, easy to use features the whole
company slows down. We're at the interseciton of can never go down, and need to move at agile, internet speed. We're connected to al aspects of Amazon's business. We are 
looking for software engineers who thrive on complex problems and relish the challenge of operating a complex and mission critical system under extreme loads. Our system responds
to millions of service requests per minute. We do security software for high availability systems. 

* Marketplace: Millions of Sellers from countries around the world (and growing) list their products for sale on the Amazon.com Marketplace.
Sellers are a critical part of Amazon's ecosystem to deliver on our vision of offering the earth's largest selection and lowest prices. 
These Sellers offer millions of unique products, providing a broad and diverse inventory of products from Books, Electronics, Apparel to Consumables and beyongd.
Our system use technology appropriate to our needs, including Hadoop, Machine learning, highly scaled java services, AWS technologies, Ajax rich UI's, and more. Ecommerce
