//
// Created by beck on 2017/10/23.
//
#include "first.h"
#include "log.h"
//#include <iostream>
//using namespace std;

class Human{
private:
    char *name;
    int age;
public:
    void setAge(int age){
        this->age=age;
    }
    int getAge(){
        return this->age;
    }
    void setName(char *name){
        this->name=name;
    }
    char* getName(){
        return name;
    }
};


void print(){
    //cout<<"xhp---------------------------"<<endl;
//    char *log="this is c++ io print";
    LOGD("this is c++ io print");
    Human human;
    human.setAge(20);
    human.setName("xhp");
    LOGD("Human name=%s,age=%d",human.getName(),human.getAge());
}
