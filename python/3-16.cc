class Pizza{
public:
  virtual float price() = 0;
  virtual std::string description() = 0;
  virtual ~Pizza();
}


class Decorator: public Pizza{
protected:
  Pizza *component;
public:

}

Iterator Pattern
Advice: Use abstract classes to define the interface
- Use pointers of Base class to call virtual methods
  -This allows subclass objects to be swapped in as needed.
