// Liskov's Substitution
// Objects of a superclass should be replaceable with objects of a subclass without breaking the program.

// vehicle -> two-wheeler -> cycle/bike
// superclass                 subclass

// means, wherever vehicle object is used, we should be able to use bike object there also
// The mistake is we are forcing a subclass to behave in a way it shouldn’t


/*
🔑 Golden Rule to Remember

👉 Subclasses should NOT surprise you
👉 No hidden exceptions, no broken expectations

Example - 

❌ Bad thinking:

* Bird → fly()
* Then forcing Penguin to fly ❌
* So we have a different class itself for penguin, not bird as we wont be able to do bird.fly()

✅ Good thinking:

* Bird → eat()
* FlyingBird → fly()
*/