### system-designs

# How to run C++ system designs 

1. Header files are stored in models
2. Its definitions are stored in controllers
3. main.cpp is the entry point
3. To run - g++ main.cpp controllers/*.cpp -o <output_file>

### Important OOPS concepts

1. A pointer to a base class (Vehicle) can refer to an object of any of its derived classes (Car, Bike), which allows you to treat a Car or Bike object as if it were a Vehicle object. This is useful in cases like factory patterns, where the return type of a method can be a base class pointer but the actual object can be any derived class.