scanf("%d", &x);
cin >> x;
operator>>(cin, x); //why are we not sending an address?
c++ has another pointer like type: reference
Lvalue reference
int y = 10;
int &z = y; // z is a lvalue reference to y
A lvalue refernece acts like a constant pointer with automatic dereferencing
int *p = &z; // p points to y
Lvalue vs Rvalue
Lvalue refers to a storage location
Rvalue - computed value
1. You cannot leave references unitiailized
2. cannot create a pointer to a references
3. Cannot create a reference to a references
4. Cannot create an array of references

Pass by reference
void inc(int &n){
  n = n + 1;
}
int x = 5;
inc(x);
cout << x << endl;
istream &operator >>(istream &in, int &x)
The 1st argument is passed by reference
 - streams cannot be copied
why return istream : for chaining to work ex. cin >> x >> y; operator >> (operator >> (cin, x), y)

struct ReallyBig{};
void f(ReallyBig rb){};
ReallyBig db = {};
f(db); // expensive, a copy of db is made for f

If we want to avoid the copy: pass by ptr
void g(ReallyBig *rb){};
call: g(&db);

c++ Pass by reference
void h(ReallyBig &rb){};
call: h(db);
// rb cannot be pointer to somewhere else
// Advice: always try to pass by reference to a constant unless there is a good reason not to.

void g(const int& x){}
g(5) and g(x+y) is allowed because the reference is never going to change the value of the variable it point to

Dyanmic/heap allocate memeory
int *p = malloc(length * size(int));
free(p);

In c++, use new & delete
struct Node {
  int data;
  Node *next;
};
Node *np = new Node;
delte np;

A heap value continue to live beyond the life/scope of a ptr to that value.
-if no ptr points to a heap value, we say that memory has "leaked"
Check memory leak by valgrind

Node getMeANode(){};
-Dangling pointer
Node *getMeANode(){
  Node n;
  return &n;
}
//Never ever returns a ptr/refernce to stack allocated data

Node *getMeNode(){
  Node  *np = new Node;
  return np;
}
