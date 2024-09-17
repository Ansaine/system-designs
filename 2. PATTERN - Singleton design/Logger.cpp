#include "Logger.hpp"
#include<mutex>

// Initialize the static members outside class definition
Logger* Logger::loggerInstance = nullptr;
int Logger::counter = 0;
mutex Logger::mu;

// this will run one time only
Logger::Logger(){
    counter++;
}

void Logger::Log(string text){
    cout<<"\nLogged message : "<<text<<" and Instance count : "<<counter;
}

Logger* Logger::getLogger(){

    if(loggerInstance==nullptr){
        mu.lock();
        if(loggerInstance==nullptr){
            loggerInstance = new Logger();
        }
        mu.unlock();
    }

    return loggerInstance;
}