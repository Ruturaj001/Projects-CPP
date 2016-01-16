#ifndef _WATER_STATE_H_
#define _WATER_STATE_H_
#include<iostream>
#include<vector>
using namespace std;
class Water_State{
    public:
    vector<int> capacity;
    vector<int> holding;
    Water_State(vector<int> in){
        capacity=in;
        for(int i=0;i<in.size();i++){
            holding.push_back(0);
        }
    }
    Water_State(Water_State *other){
        for(int i=0;i<other->capacity.size();i++){
            capacity.push_back(other->capacity[i]);
            holding.push_back(other->holding[i]);
        }
    }
    Water_State(){
    }
};
#endif
