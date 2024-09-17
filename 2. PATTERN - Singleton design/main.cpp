#include<iostream>
#include<thread>
#include "Logger.hpp"
using namespace std;

void user1(){
    Logger* myLogger1 = Logger::getLogger();
    myLogger1->Log("this is user 1");
}

void user2(){
    Logger* myLogger2 = Logger::getLogger();
    myLogger2->Log("this is user 2");
}


int main(){

    thread t1(user1);
    thread t2(user2);

    t1.join();
    t2.join();

    return 0;
}