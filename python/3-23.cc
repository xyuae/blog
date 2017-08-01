Visitor Design Pattern
Double Dispatch
Enemy

Weapon: Stick & Rock

implement Enemy:: stike(weapon &w): e.strike(w),
implement Weapon:: strike(Enemy &e);
  w -> strike(e);

Visitor D.P enables double Dispatch through combinaiton of:
1. overiding(what you get with virtual methods)
2. Overloading (methods with same name but different types for parameters)

class Enemy{
public:
  virtual void stirke(Weapon &w) = 0;
};

class Turtle: public Enemy {
public:
  void strike(Weapon &w){
    w.useOn(*this);
  }
};

class Bullet: public Enemy {
public:
  void stike(Weapon &w){
    w.useOn(*this);
  }
};

class Weapon{
public:
  virtual void useOn(Turle &t)=0;
  virtual void useOn(Bullet &b)=0;
};

class Stick:public Weapon{
public:
  void useOn(Turtle &t){// use stick on turtle
  }
  void useOn(Bullet &b){}
};

class Rock: public Weapon{
public:
  void useOn(Turtle &t){}
  void useOn(Bullet &b){}
};

Enemy *e = l -> createEnemy();
Weapon *w = Bullet
e -> strike(w)
V.D.P allows adding new functionality to exisitng class hiearchies
without modifying the classes in the hierarchy(as long as the hierachy clases come configured to "asccept visitors")

Catalog
Normal Books, author -> # of Books
       Text, topic -> # of Text
       Comic, hero -> # of comic

 class Book {
 public:
   virtual void accept(BookVisitor &v){
     v.visit(*this);
   }
 };

 class Text: public Book {
 public:
   void accept(BookVisitor &v){
     v.visit(*this);
   }
 };

 class Comic: public Book {
 public:
   void accept(BookVisitor &v){
     v.visit(*this);
   }
 };

class BookVisitor{
public:
  virtual void visit(Book &b) = 0;
  virtual void visit(Text &t) = 0;
  virtual void visit(Comic &c) = 0;
}

class Catqalog: public BookVisitor{
  std::map<String, int> cat;
public:
  void visit(Book &b){
    cat[b.getAuthor()] = cat[b.getAuthor()] + 1;
  }

  void visit(Text &t) {
    ++cat[t.getTopic()];
  }

  void visit(comic &c){
    ++cat[c.getHero()];
  }
}

Vector<Book *> v;
Catalog calVisitor;
for (auto &b = v){
  b.accept(catVisitor);
}

Compilation Dependencies
When you include a header file you create a compilaiton dependency.
- whenever the included header changes, the file that did the include must recompile.
If possible forward decleared a class rather than including its headers
  + reduces compliation Dependencies
  + reduces compile time
  + avoid circular Dependencies

class 
