#ifndef Logger_hpp
#define Logger_hpp

#include<iostream>
#include<mutex>
using namespace std;

class Logger{

    static int counter;
    static Logger* loggerInstance;
    static mutex mu;
    Logger();

public:
    void Log(string text);
    static Logger* getLogger();
};

#endif