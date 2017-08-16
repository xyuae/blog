The interpreter is one of the design patterns publisehd in the GoF which is not really used. Usually the Interpreter Pattern
is described in terms of formal grammars, like it was described in the original form in the GoF
but the area where this design pattern can be applied can be extended.

## Intent
Given a language, define a representation for its grammar along with an interpreter that
uses teh representation to interpret sentences in the language.
Map a domain to a language, the language to a grammar, and the grammar to a hierarchical object-oriented design

Implementation
The implementation of the Interpreter pattern is just the use of the composite pattern applied
to represent a grammar. The Interpreter defines teh behaviour where the conposite defines only the structure.

## Applicabilty & Examples
Teh template method pattern should be used:
- The interpreter pattern is used exaustively in defining grammars, tokenize input and stroe it.
- A specific area where Interpreter can be used are the rules engines
- The Interpreter pattern can be used to add functionality to the copositte pattern. 

THe interpreter design pattern allows you to build the rules as classes. This design patern is very powerful in building the rules
 in a very logical manner. Most of the examples you see uses a programming language grammar as teh rules because it's the eariest to demonstrate.
 However, once you realize the essence of the interpreter pattern you will see taht you can apply the rules to any streams of inputs or objects.
 
 The easiest way to understand how the interpreter pattern works is by looking at an example that will leads us to the UML of the interpreter pattern.
 AddExpression = Expression + Expression
 SubtractExpreesion = Expression - Expression
 Expression = NumberExpression | AddExpressoin | SubtractExpressioin
 
 We can use these rules to give us a variety of ways to evaluate a statement:
 
 
 ## Composite Design Pattern
 When we want to represent part-whole hierarchy, use tree structure and compose objects. We know 
 tree structure but some of us don't know what a part-whole hierarchy is. A system consists of subsystems or components.
 Components can further be divided into smaller coponents. Further smaller components can be divided into smaller elements.
 
 Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual 
 objects and compositions of objects uniformly.
 
 Real World Example
 In this article, let us take a real world example of part-whole hierarchy and use compsite design pattern using java. 
 Let us consider the game of building blocks to practice composite pattern. Assume that our kit has only three unique pieces and let us call these as primitive blocks as they will be the end nodes in teh tree strcutues.
 
 ## Important Points
 - Importance of composite pattern is, the group of objects should be treated similarly as a single object
 - Manipulating a single object should be as similar to manipulating a group of objects. In sync with our example, we join primitive blocks to create strutures and similarly join strcutres to create house
 - Clients access the whole hierarchy through the comopnents and they are not aware about if they are dealing with leaf or composites.
 
 ## UML design for composite pattern
 Components: Structure
 1. COmponent is at the top of hierarcy. It is an abstraction for the composite.
 2. It declares the interface for objects in composition
 
 

