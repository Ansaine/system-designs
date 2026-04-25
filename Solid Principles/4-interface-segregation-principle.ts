// Interface segregation - 
// Clients should not be forced to depend on interfaces they do not use. In simpler terms - 
// Don’t create large interfaces. Split them into smaller, specific ones. In reduces undecessary methods of classes


// ❌ BAD EXAMPLE
interface IWorker {
  work(): void;
  eat(): void;
  sleep(): void;
}

class Robot implements IWorker {
  work(): void {
    console.log("Working...");
  }

  eat(): void {
    // ❌ Forced to implement unnecessary method
    throw new Error("Robots don't eat");
  }

  sleep(): void {
    // ❌ Forced to implement unnecessary method
    throw new Error("Robots don't sleep");
  }
}


//  ✅ GOOD EXAMPLE - Split into smaller, focused interfaces
interface Workable {
  work(): void;
}

interface Eatable {
  eat(): void;
}

interface Sleepable {
  sleep(): void;
}

// Human implements all relevant behaviors
class Human implements Workable, Eatable, Sleepable {
  work() {
    console.log("Working...");
  }

  eat() {
    console.log("Eating...");
  }

  sleep() {
    console.log("Sleeping...");
  }
}

// Robot only implements what it actually needs
class RobotWorker implements Workable {
  work() {
    console.log("Working...");
  }
}
