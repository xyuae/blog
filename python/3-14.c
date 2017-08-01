Lec 18
Exceptions
Stack unwinding: when an exception occurs, the program begins to pop the call stack
until a handler is found
Handling exceptions in multiple stages
try {}
catch (SomeExn s) {
  // somerecovery
}
throw SomeOthers Exn{};
or throw s;
or throw;

throw s; vs throw;
throw s
- the actual exception might have been a subclass of SomeExn
- The exception object that is caught might be sliced(to store in s)
- throw s; thros the possibly sliced object
throw:
- throw teh original exception that was caught

- All c++ library exceptions inherit from a class called "exception"
- But c++ does not restrict you from having to inherit from the "exception" class
- Special syntax for catching all exceptions:
try {}
catch (...){}
- three dots indicate catch all exceptions
In C++ you can throw anything e.g. int
- Exceptions should only be used in "exceptional" situations
- Determine where catch block is takes CPU time
- Throw objects of existing exception clases as one you have created

class BadInputExn{}
try {
  int n;
  if(!(cin>>n)) throw BadInputExn();
} catch(BadInputExn &e){}
- Advice: catch by referenece
  - Suppress copying + no Slicing

- out_of_range : vector at
- length_error: resize string/vector fails
- bad_alloc: when No heap space left
- Advice: Don't let the dtor throw exceptions
- Suppose a dtor is running druing stock unwinding, suppose the dtor throws an
exception, so we have 2 simultaneously live exceptions (unhandled), C++ rule:
program terminates immediately

Observer Pattern
Publish/Subscribe system
One class that generates data: Subject
One or more classes interested in this data: Observer
An object can be both subject and observer: ex. when a cell in excell need to
observe other cells


/* ASubject
----------------
+ attach(AObserver*)
+ detach(AObserver*)
+ notifyObservers

AObserver
-----------------
+ notify__pure virtual

CSubject
-----------------
+ getState()

CObserver
-----------------
+ notify()
*/

At any time, a concrete observer can call CSubject::attach
When something changes in CSubje t, CSubject::notifyObservers is called
which calls AObserver::notify
- which means taht the appropriate CObserver::notify runs
CObserver calls CSubject::getState to gain more information
If a class has no pure virtual method but we want it to be abstract, make the
dtor pure virtual
Problem: The base class dtors needs to be implemented as it is called automatically
when subclass objects are destroyed
Solution: implement the P. V. dtor
A pure virtual method must be implemented by the subclass for it to be concrete

Decorator Pattern
Add/modify functionality from exisitng object, adding additional feature of an
object without destroying the object

/*
Component(Abstrct) // abstract window
-------------------
+ operation (p.v method)

ConcreteComponent
-------------------

Decorator
--------------------
has a reference to the abstract Component

ConcreteDecoraterA (menu)
-----------------

ConcreteDecoraterB (scrollBar)
-----------------------------

*/
AbsWindow *w = new Window;
w = new Menu(w);
w - new scrollBar(w);
