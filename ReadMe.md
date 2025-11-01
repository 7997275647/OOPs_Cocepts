# OOP Concepts in C++

This repository defines the four core Object-Oriented Programming (OOP) concepts and gives concise C++ usage examples for each: Encapsulation, Inheritance, Polymorphism, and Abstraction.

---

## 1. Encapsulation

Definition:
- Encapsulation is the practice of bundling data (attributes) and the methods that operate on that data into a single unit (a class) and restricting direct access to some of the object's components (using access specifiers: private, protected, public). It protects object integrity by preventing outside code from setting the object into an invalid state.

Benefits:
- Data hiding, controlled access, easier maintenance, and improved modularity.

Example (Account with private balance and public interface):

    #include <iostream>
    class Account {
    private:
        double balance;
    public:
        Account(double b) : balance(b) {}
        void deposit(double amount) {
            if (amount > 0) balance += amount;
        }
        bool withdraw(double amount) {
            if (amount > 0 && amount <= balance) { balance -= amount; return true; }
            return false;
        }
        double getBalance() const { return balance; }
    };

    int main() {
        Account a(100.0);
        a.deposit(50.0);
        if (a.withdraw(30.0)) std::cout << a.getBalance(); // prints 120
        return 0;
    }

---

## 2. Inheritance

Definition:
- Inheritance allows a class (derived) to acquire properties and behaviors (members) of another class (base). It enables code reuse and models "is-a" relationships. C++ supports single, multiple, and multi-level inheritance; access specifiers (public/protected/private) control visibility.

Benefits:
- Reuse, specialization, polymorphic behavior via base pointers/references.

Example (Base `Animal` and derived `Dog`):

    #include <iostream>
    class Animal {
    public:
        void eat() { std::cout << "Eating\n"; }
    };
    class Dog : public Animal {
    public:
        void bark() { std::cout << "Bark\n"; }
    };

    int main() {
        Dog d;
        d.eat();  // inherited
        d.bark();
        return 0;
    }

---

## 3. Polymorphism

Definition:
- Polymorphism means "many forms." In C++ it appears as compile-time (static) polymorphism — function overloading, templates, operator overloading — and run-time (dynamic) polymorphism — virtual functions and overriding allowing calls through base-class pointers to invoke derived-class behavior.

Compile-time example (function overloading):

    #include <iostream>
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }

    int main() {
        std::cout << add(1,2) << '\n';     // int overload
        std::cout << add(1.5,2.3) << '\n'; // double overload
    }

Run-time example (virtual functions):

    #include <iostream>
    #include <vector>

    class Shape {
    public:
        virtual ~Shape() = default;           // virtual destructor
        virtual void draw() const = 0;        // pure virtual (also shows abstraction)
    };

    class Circle : public Shape {
    public:
        void draw() const override { std::cout << "Draw Circle\n"; }
    };
    class Rectangle : public Shape {
    public:
        void draw() const override { std::cout << "Draw Rectangle\n"; }
    };

    int main() {
        std::vector<Shape*> shapes{ new Circle(), new Rectangle() };
        for (auto s : shapes) s->draw(); // runtime chooses correct override
        for (auto s : shapes) delete s;
    }

Key points:
- Use virtual functions and a virtual destructor for proper cleanup.
- Polymorphism enables writing generic code that works on base pointers/references.

---

## 4. Abstraction

Definition:
- Abstraction is exposing only the necessary features of an object while hiding implementation details. In C++, abstraction is commonly achieved using abstract classes (classes with pure virtual functions) and interfaces.

Benefits:
- Defines contracts, separates interface from implementation, improves decoupling.

Example (abstract base class `Logger` and concrete implementations):

    #include <iostream>
    class Logger {
    public:
        virtual ~Logger() = default;
        virtual void log(const std::string& msg) = 0; // pure virtual => abstract
    };

    class ConsoleLogger : public Logger {
    public:
        void log(const std::string& msg) override { std::cout << msg << '\n'; }
    };

    int main() {
        Logger* logger = new ConsoleLogger();
        logger->log("Hello abstraction");
        delete logger;
        return 0;
    }

Note: You cannot instantiate an abstract class directly.

---

## Usage tips / Best practices

- Prefer encapsulation: keep members private/protected and expose a clear public API.
- Use inheritance for "is-a" relationships, composition for "has-a" relationships.
- Use virtual functions only when polymorphic behavior is required; prefer interfaces (abstract classes) to define contracts.
- Remember the Rule of Five / Rule of Three when classes manage resources.
- Make destructors virtual in base classes that are intended to be used polymorphically.

---

This README provides definitions and minimal examples to illustrate each OOP concept in C++. Expand examples and add unit tests or small projects to practice each