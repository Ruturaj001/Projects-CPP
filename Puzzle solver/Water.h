#ifndef _WATER_H_
#define _WATER_H_
#include "Puzzle.h"
#include<iostream>
#include <vector>

using namespace std;

class Water:public Puzzle<Water_State>{
    private: 
    int want,noOfBuckets;
    string outputfile;
    bool fileoutput;
    public:
        vector<Water_State> getNext(Water_State);
        Water_State init();
        bool solved(Water_State); 
        void print(vector<Water_State>);
};
#endif
