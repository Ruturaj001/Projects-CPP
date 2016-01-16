/**
 * It keep tracks of the configurations.
 * 
 *
 * @version	1.0
 * @author	Ruturaj
 * @author	Rikin
 * Revisions:
 *	Initial version
 */
#ifndef _JUMP_STATE_H_
#define _JUMP_STATE_H_
#include<iostream>

class JumpState{
    public:
    bool **mat;
    int xco,yco;
	/**
	*	Parametrised Constructor
	*	@param x - intakes the x coordinate of the peg
	*	@param y - intakes the y coordinate of the peg
	*/
    JumpState(int x,int y){
        xco=x;
        yco=y;
        mat = new bool*[x];
        for(int i = 0; i < x; ++i)
            mat[i] = new bool[y];
    }
	/**
	*	@param - other - refers to the object of class jumpstate. 
	*/
    JumpState(JumpState *other){
        xco=other->xco;
        yco=other->yco;
        mat = new bool*[xco];
        for(int i = 0; i < xco; ++i)
            mat[i] = new bool[yco];
        for(int i=0;i<xco;i++){
            for(int j=0;j<yco;j++){
                mat[i][j]=other->mat[i][j];
            }
        }
        
    }
    JumpState(){
        mat=NULL;
    }
};
#endif
