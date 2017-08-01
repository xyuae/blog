Consider
  Text b1{"A", "Normal", 200, "Physics"};
  Text b2{"B", "Brad", 100, "CS"};
  New problem: Mixed Assignment Problem
  - Code that tries to assign a Book/Comic object to a Text will now compile
  - How are we going to set the topic fields

  One way to prevent partial assignemnt is to disallow assignment through base class pointers
  - we can make Book::operator = protected
  New problem: this prevents us from assigning a book to another book
  This is because our base class is not an abstract class
  Advice: Base classes should be abstract

  Class AbstractBook {
    String title;
    String another;
    int numPages;
  protected:
    AbstractBook &operator=(const AbstractBook & other);
  public:
    virtual AbstractBook() = 0;

  }

I can't wirte the following code to compile:
Text b1(), b2();
AbstractBook *pb1 = &b1;
AbstractBook *pb2 = &b2;
*pb1 = *pb2; //won't compile becasue abstractbook::operator= is protected

class NormalBook:: public AbstractBook{
public:
  NormalBook &operator=(const NormalBook &others)
  {
    AbstractBook::operator=(others);
    return *this;
  }
}

Factory Method Pattern
2 kinds of enemies,: Tustle, Bullet
Player *p;
Level *e;
Enemy *e = nullptr;
while (p -> notDead()) {
  // generate Enemy

  // attack player
}
Generating enemies
- We don't want to hardcode emeny ctor calls;
- we don't want to place enemy generation logic in this loop.
- Since enemy generation logic depends on level, let's put it in the level class

class Level {
public:
  virtual Enemy *createEnemy()=0;
}
class Normal: public Level{
public:
  Enemy *createEnemy() override {// more tustle}
};

class Castle: public Level{
public:
  Enemy *createEnemy() override{// more enemy}
};
A factory method will return a pointer to one of a few kinds of objects

Template Method Pattern
Want subclass to override some aspect of superclass behavior, but other aspects must remain the same.
There are Red & Green turtles
class Turtle: public Enemy{
public:
  void Draw() {
    drawHead();
    drawShell();
    drawFeet();
  }
private:
  void drawHead() {};
  void drawFeet() {};
  virtual void drawShell()=0;
};

class RedTurtle: public Turtle{
  void drawShell(){ // red turtle shell }
};

-Draw is not virtual
- if you want to draw a turtle call Turtle::Draw
- drawhead/drawFeet are private non virtual
  - private not allowed to call directly
  - non-virtual subclasses cannot replace implementation
drawShell is pure virtual
  - it is the blank that subclasses must fill
Philosophy: use template methods everywhere
Suppose: have a pubic virtual method:
public: to the client, this is my interface, call me to do the following
virtual: tell subclass: you can replace this behavior
How then are we going to keep the promise made to the client if subclasses have full control to replace behavior
Use NVI: non virtual interface
- all public methods are not virtual
- all vritual methods are private
(dtor being an exception)

class DigitalMedia {
public:
  virtual void play()=0;
}
In NVI
class DigitalMedia {
public:
  void play() {doPlay();}
private:
  virtual void doPlay()=0;
}

std::map<key, value> map;
- Generation in the form of a lookup table
- Template class with 2 type parameters; key value
