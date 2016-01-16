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
#include "JumpState.h"
#include "Jump_peg.h"
#include <iostream>
#include <vector>

using namespace std;
/**
*	This function is responsible for checking all the legit moves which a peg can make
*	horizontally,verticalls & diagonally along with checking if the 
*	multiple moves are possible.
*	@param - current -  the current position of peg
*	@param - x- the new x position of the peg on board 
*	@param - y- the new y position of the peg on board 
*	@param - a- the vector to store the new configuration(position) of the peg
*/
void Jump_peg:: jump(JumpState current,int x,int y,vector<JumpState> &a){
    //try Horizontal Left, Horizontal Right, Virtical Up, Vertical Down
    //for each HL HR VU VD recursively after every successful jump

    //for Horizontal Right
    if(x<xco-2 && current.mat[x+1][y] && !current.mat[x+2][y]){
        JumpState nextStep(&current);
        nextStep.mat[x][y]=false;
        nextStep.mat[x+1][y]=false;
        nextStep.mat[x+2][y]=true;
        a.insert(a.begin(),nextStep);
        jump(nextStep,x+2,y,a);
    }
    //for Horizontal Left
    if(x>1 && current.mat[x-1][y] && !current.mat[x-2][y]){
        JumpState nextStep(&current);
        nextStep.mat[x][y]=false;
        nextStep.mat[x-1][y]=false;
        nextStep.mat[x-2][y]=true;
        a.insert(a.begin(),nextStep);
        jump(nextStep,x-2,y,a);
    }
    //for Vertical Up
    if(y>1 && current.mat[x][y-1] && !current.mat[x][y-2]){
        JumpState nextStep(&current);
        nextStep.mat[x][y]=false;
        nextStep.mat[x][y-1]=false;
        nextStep.mat[x][y-2]=true;
        a.insert(a.begin(),nextStep);
        jump(nextStep,x,y-2,a);
    }
    //for Vertical Down
    if(y<yco-2 && current.mat[x][y+1] && !current.mat[x][y+2]){
        JumpState nextStep(&current);
        nextStep.mat[x][y]=false;
        nextStep.mat[x][y+1]=false;
        nextStep.mat[x][y+2]=true;
        a.insert(a.begin(),nextStep);
        jump(nextStep,x,y+2,a);
    }
    //Diagonal Left Up
    if(x>1 && y>1 && current.mat[x-1][y-1] && !current.mat[x-2][y-2]){
        JumpState nextStep(&current);
        nextStep.mat[x][y]=false;
        nextStep.mat[x-1][y-1]=false;
        nextStep.mat[x-2][y-2]=true;
        a.insert(a.begin(),nextStep);
        jump(nextStep,x-2,y-2,a);
    }
    //Diagonal Left Down
    if(x>1 && y<yco-2 && current.mat[x-1][y+1] && !current.mat[x-2][y+2]){
        JumpState nextStep(&current);
        nextStep.mat[x][y]=false;
        nextStep.mat[x-1][y+1]=false;
        nextStep.mat[x-2][y+2]=true;
        a.insert(a.begin(),nextStep);
        jump(nextStep,x-2,y+2,a);
    }
    //Diagonal Rigt Up
    if(x<xco-2 && y>1 && current.mat[x+1][y-1] && !current.mat[x+2][y-2]){
        JumpState nextStep(&current);
        nextStep.mat[x][y]=false;
        nextStep.mat[x+1][y-1]=false;
        nextStep.mat[x+2][y-2]=true;
        a.insert(a.begin(),nextStep);
        jump(nextStep,x+2,y-2,a);
    }
    //Diagonal Right Down
    if(x<xco-2 && y<yco-2 && current.mat[x+1][y+1] && !current.mat[x+2][y+2]){
        JumpState nextStep(&current);
        nextStep.mat[x][y]=false;
        nextStep.mat[x+1][y+1]=false;
        nextStep.mat[x+2][y+2]=true;
        a.insert(a.begin(),nextStep);
        jump(nextStep,x+2,y+2,a);
    }
}

/**
*	Gets the new configuration based on the current configuration.
*	@param - current - refers to the current configuration
*/
vector<JumpState> Jump_peg:: getNext(JumpState current){
        vector<JumpState> toReturn;
        for(int i=0;i<xco;i++){
            for(int j=0;j<yco;j++){
                if(current.mat[i][j]){
                    vector<JumpState> temp;
                    jump(current,i,j,temp);
                    toReturn.insert(toReturn.end(), temp.begin(), temp.end());
                }
            }
        }
        return toReturn;
}

/**
*	Initialises the board by taking input from the user such as start position and size of board.
*	
*/
JumpState Jump_peg::init(){
    int x,y;
    cout<<"Enter the board size:";
    cin>>xco>>yco;
    JumpState first(xco,yco);
    cout<<"Enter starting position:";
    cin>>x>>y;
    x=x-1;
    y=y-1;
    for(int i=0;i<xco;i++){
        for(int j=0;j<yco;j++){
            first.mat[i][j]=true;
        }
    }
    first.mat[x][y]=false;
    return first;
}

/**
* Checks wheather the solution is found or not
*	@param - current - refers to the current configuration
*	@return bool - returns true if the solution is found, false otherwise
*/
bool Jump_peg::solved(JumpState current){
    int count=0;
    for(int i=0;i<xco;i++){
        for(int j=0;j<yco;j++){
            if(current.mat[i][j]==true){
                count++;
            }
            if(count==2)
                return false;
        }
    }
    return true;
} 

/**
*	prints the board
*	@param - current - refers to the current configuration
*/
void Jump_peg:: print(JumpState current){
    for(int i=0;i<xco;i++){
        for(int j=0;j<yco;j++){
            if(current.mat[i][j]==true){
                cout<<" +";
            }else{
                cout<<" .";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
