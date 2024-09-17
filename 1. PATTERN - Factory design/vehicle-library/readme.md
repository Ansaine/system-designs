### Important OOPS concepts used

1. A pointer to a base class (Vehicle) can refer to an object of any of its derived classes (Car, Bike), which allows you to treat a Car or Bike object as if it were a Vehicle object. This is useful in cases like factory patterns, where the return type of a method can be a base class pointer but the actual object can be any derived class.