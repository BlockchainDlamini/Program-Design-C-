#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>
#include <sstream>
#include <iostream>
#include "Disk.h"

template<class U>
static std::string toString(U val){
    std::stringstream ss; 
    ss << val;
    std::string res;
    ss >> res;
    return res;
}

template<class T>
class Exception{
    private:
        Exception(std::string msg){
            message = msg;
        }
    public:
        std::string message;
        static Exception<T>* incorrectDiskMove(int dep, int dest){
            return new Exception<T>("Incorrect disk move from tower " + toString<int>(dep) + " to " + toString(dest));
        }

        static void movePlan(Disk<T>* d, int dep, int dest){
            if(d == NULL)
                std::cout << "A null disk was moved" << std::endl;            
            else
                std::cout << d->getLabel() << " was moved from " << dep << " to " << dest << std::endl;
        }

        static Exception<T>* emptyStack(int tower){
            return new Exception<T>("Tower " + toString<int>(tower) + " is empty");
        }

        static Exception<T>* invalidDiskAdd(int tower, T label){
            return new Exception<T>("Disk with label " + toString<T>(label) + " was attempted to be added to invalid tower: " + toString<int>(tower));
        }

        static Exception<T>* invalidGame(){
            return new Exception<T>("Game is invalid");
        }

        static Exception<T>* invalidTower(int tower){
            return new Exception<T>("A tower will have an invalid state");
        }

        static Exception<T>* invalidMoves(int moves){
            return new Exception<T>("Invalid moves was attempted with: " + toString<int>(moves));
        }
};

#endif // __EXCEPTION_H__