#ifndef _PUZZLE_H_
#define _PUZZLE_H_
#include<iostream>
#include <vector>

using namespace std;
template<typename State>
class Puzzle{
    public:
        virtual vector<State> getNext(State) = 0;
        virtual State init() = 0;
        virtual bool solved(State) = 0; 
        virtual void print(vector<State>) = 0;   
};
#endif
