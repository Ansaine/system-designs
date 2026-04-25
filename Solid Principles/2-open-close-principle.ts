// Open/Close principle
// Software entities/code should be open for extension but closed for modification

// This is wrong 
class DiscountCalculator1 {
  calculate(type: string, amount: number): number {
    if (type === "regular") {
      return amount * 0.1;
    } else if (type === "premium") {
      return amount * 0.2;
    }
    return 0;
  }
}

// Correct way

//  1. create an interface
interface Discount {
  calculate(amount: number): number;
}

// 2. create implementations
class RegularDiscount implements Discount {
  calculate(amount: number): number {
    return amount * 0.1;
  }
}

class PremiumDiscount implements Discount {
  calculate(amount: number): number {
    return amount * 0.2;
  }
}

// 3. Use abstraction
// we simply call the old code with new discount types, so old code remains same
class DiscountCalculator2 {
  calculate(discount: Discount, amount: number): number {
    return discount.calculate(amount);
  }
}

// 4. Add new behaviour without modifying existing code 
// here we add another discount type
class VIPDiscount implements Discount {
  calculate(amount: number): number {
    return amount * 0.3;
  }
}


/* 
Real-World Analogy

Think of a mobile phone:
* You don’t modify the phone every time
* You just install a new app

👉 The phone is closed for modification
👉 But open for extension

*/