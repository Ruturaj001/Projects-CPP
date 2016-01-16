/**
 * Solving the Jump-Peg Puzzle using Breadth first search
 * 
 *
 * @version	1.0
 * @author	Ruturaj
 * @author	Rikin
 * Revisions:
 *	Initial version
 */
#ifndef _JUMP_PEG_H_
#define _JUMP_PEG_H_
#include "JumpState.h"
#include "Puzzle.h"
#include<iostream>
#include <vector>

using namespace std;

class Jump_peg:public Puzzle<JumpState>{
    private: 
    int xco,yco;
    public:
        vector<JumpState> getNext(JumpState);
        JumpState init();
        bool solved(JumpState); 
        void print(JumpState);
        void jump(JumpState,int,int,vector<JumpState>&);
};
#endif
