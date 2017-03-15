# blog Interview preparation
* [HashMap's implementation](http://yikun.github.io/2015/04/01/Java-HashMap%E5%B7%A5%E4%BD%9C%E5%8E%9F%E7%90%86%E5%8F%8A%E5%AE%9E%E7%8E%B0/)
* [Lifecycle of a Thread](http://www.cnblogs.com/sunddenly/p/4106562.html)
* [A story about thread](http://mp.weixin.qq.com/s?__biz=MjM5NzA1MTcyMA==&mid=403498894&idx=2&sn=219c1a6001b5bb7e6bdc7963b1af8450&scene=2&srcid=0330UDNmQ2GlTOLo1CY8IZfH&from=timeline&isappinstalled=0#wechat_redirect) Very nice to read
* [Cache](http://blog.chinaunix.net/uid-26817832-id-3244916.html)


## Note
* Hash Map is a Hash table based implementaion of the Map interface. It does not guarantee that the order will remain constant over time.
* HashMap has two important factor: capacity and load factor
* Initial capacity is the number of buckets in the hash table
* Load factor is a measure of how full the hash table is allowed to get before its capacity is automatically increased
* work flow of put: hashCode(key) -> index = hashCode % capacity -> store in Map[index], when collision, store in the beginning of the linkedList. 