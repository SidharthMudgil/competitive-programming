## Object Oriented Programming
Object oriented programming is programming model based on the concept of objects. It aims to implement real-world entities like inheritance, abstraction, etc. In OOPs the classes acts as blueprints while objects are instances of the blueprint that holds values. The main goal of the OOPs is code reusability.

### Classes & Objects
> Classes are like blueprint for creating objects, They defines a set of attributes and methods for creating objects.
>
> Objects are the instances of the class. They occupies space in the memory.
>
> For example: If Animal is a class with attributes eating habits then Lion will be an object with eating habit carnivores.

### Inheritance
> By the name suggests, Inheritance allows classes to inherit all the attributes and methods of the parent class. The main goal of inheritance is code reusability.

### Polymorphism
> It referes the ability of an object to be present in many forms. For example at a time person can be both Father and Son for 2 different person. As in above below we can see that objects of both Son and Daughter can be treated as an object of Father class
``` kotlin
open class Father {
  open fun greetings() = print("Hi Son!")
}

class Son: Father {
  override fun greetings() = print("Hi Dad!")
}

class Daughter: Father {
  override fun greetings() = print("Hi Father!")
}

fun main() {
  val son: Father = Son()
  val daughter: Father = Daughter()
}
```

#### Types
- **Compile Time:** Also known as method overloading, It allows a class to have multiple methods of same name but different parameters.
- **Runtime:** Also known as method overriding, It allows the child classes to have their own implementation of methods.

### Abstraction
> The act of showing only necessary attributes and hiding unnecessary details from the user is called abstraction. By abstraction we can create abstract classes and methods where internal representation is hidden from outside and only a simplified interface is exposed. For example as in the below example we can see that we're exposing the interface to the user which does not contain any implementation and hiding the actual implementation.

``` kotlin
interface Math {
  fun sum(a: Int, b: Int): Int
}

class Sum: Math {
  override fun sum(a: Int, b: Int): Int = a + b
}

fun main() {
  val sum: Math = Sum()
}
```

### Encapsulation
> Also known as data hiding is used to wrap up the data into a single capsule like unit. By encapsulating the data into a single unit we create a protective shield that prevents the data from being accessed by outside of this shield. As we can see in the example below that we are hiding the member SECRET from outside the class by making it private now only methods and attributes from that class can access it.
``` kotlin
class Decrypter {
  private const val SECRET: String = "this is secret"
  fun decrypt() {
    return getMessage(SECRET, "aih afe")
  }
}
```

### Coupling
> Refers to how dependent a class/module is on another class/module. Loose coupling is preferred because it makes the code more maintainable & flexible. As in below example we can see that without class Key, ckass Cipher can't work properly hence they are tightly coupled.
``` kotlin
class Key {}
class Cipher(key: Key) {}
```

### Cohesion
> Refers to how closely elements in class/module are related. High cohesion is generally preferred. As we can see in below example that all methods of class Math are highly related as they are mathematical operations hence class has high cohesion.
```
class Math {
  fun Sum() {}
  fun Sub() {}
}
```

### Association
> Represents the general relationship between 2 or more classes, It may be one-to-one, one-to-many, etc. For example, in the code below, there is a one-to-one relationship between the user. The user lives at the address.
```
class Address {}
class User(name: String, address: Address) {}
```

### Aggregation
> It is a weak form of association in which an object contains a reference to another object, but the reference object exists independently. For example in the code below we can see that both objects are independent and if I delete the tv object the remote object will be still there.
```
class Remote
class TV(remote: Remote)

fun main() {
  val remote = Remote()
  vak tv = TV(remote)
}
```

### Composition
> It is a strong form of association in which an object contains a reference to another object, but the reference object can not exist independently the referenced object has no meaning and purpose on its own. For example in the code below we can see that the remote object is dependent on tv and if I delete the tv object the remote object will also be deleted.
```
class Remote
class TV {
  val remote = Remote()
}

fun main() {
  vak tv = TV()
}
```

### SOLID
#### Single-responsibility Principle
> class should have only one responsibility.
```
class NotificationManager() {
    fun sendNotification(notification: String) {}
}

class UserManager {
    fun addUser(user: User) {}
    fun deleteUser(user: User) {}
}
```

#### Open-closed Principle
> classes should be open for extension but closed for modification. In other words, you should be able to extend a class's behavior without modifying its source code.
```
interface Shape {
    fun area(): Double
}

class Rectangle(val width: Double, val height: Double) : Shape {
    override fun area() = width * height
}

class Circle(val radius: Double) : Shape {
    override fun area() = Math.PI * radius * radius
}

fun calculateArea(shape: Shape) = shape.area()
```

#### Liskov Substitution Principle
> objects of a superclass should be replaceable with objects of its subclasses without affecting the correctness of the program.
```
abstract class Animal {
    abstract fun makeSound(): String
}

class Dog : Animal() {
    override fun makeSound(): String {
        return "Woof!"
    }
}

fun makeAnimalSound(animal: Animal) {
    println(animal.makeSound())
}

fun main() {
    val dog: Animal = Dog()
    makeAnimalSound(dog)
}
```

#### Interface Segregation Principle
> clients should not be forced to depend on interfaces they do not use. It encourages creating smaller, cohesive interfaces rather than large ones.
```
interface Walker {
    fun walk()
}

interface Swimmer {
  fun swim()
}

class Dog : Walker {
  override fun walk() {}
}

class Fish : Swimmer {
  override fun swim() {}
}
```

#### Dependency Inversion Principle
>  high-level modules should not depend on low-level modules. Both should depend on abstractions, and abstractions should not depend on details.
```
interface PaymentProcessor {
    fun processPayment(amount: Double): Boolean
}

class PaypalPaymentProcessor : PaymentProcessor {
    override fun processPayment(amount: Double): Boolean {
        return true
    }
}

class StripePaymentProcessor : PaymentProcessor {
    override fun processPayment(amount: Double): Boolean {
        return true
    }
}

class PaymentService(private val paymentProcessor: PaymentProcessor) {
    fun processPayment(amount: Double): Boolean {
        return paymentProcessor.processPayment(amount)
    }
}

fun main() {
    val paymentProcessor = PaypalPaymentProcessor()
    val paymentService = PaymentService(paymentProcessor)
    println(paymentService.processPayment(50.0)) // Process payment via Paypal API
}
```