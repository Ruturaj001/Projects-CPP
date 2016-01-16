#ifndef _PUZZLE_SOLVER_H_
#define _PUZZLE_SOLVER_H_
#include<iostream>
#include <queue>  
#include <set>  
#include "Puzzle.h"
using namespace std;
template<typename T>
class S{
    public:
    T data;
    S *parent;
    S(T &in,S* father){
        data=new T(&in);
        parent=father;
    }
    S(T &in){
        data=new T(&in);
        parent=NULL;
    }
};

template<typename T>
class Puzzle_solver{
    private:
    Puzzle<T> *game;
    
    public:
        Puzzle_solver(Puzzle<T>*);
        void solve();
};
template<typename T>
Puzzle_solver<T>::Puzzle_solver(Puzzle<T> *myGame){
    game=myGame;
}
template<typename T>
void Puzzle_solver<T>::solve(){
        queue<S<T> *> q;
        T first(game->init());
        S<T> *temp=new S<T>(first);
        q.push(temp);
        S<T> *toAdd;
        while(!q.empty()){
            temp= q.front();
            q.pop();
            //game->print(temp->data);
            if(game->solved(temp->data)){//if game solved
                break;
            }
            vector<T> nextSteps=game->getNext(temp->data);
            typename vector<T>::iterator it;
            for(it=nextSteps.begin();it != nextSteps.end();++it){
                        toAdd=new S<T>(*it,temp);
                        q.push(toAdd);
            }
        }
        if(game->solved(temp->data)){
            vector<T> answer;
            do{
                answer.insert(answer.begin(),temp->data);
                temp=temp->parent;
            }while(temp!=NULL);                
            game->print(answer);
            //cout<<"Total steps needed :"<<answer.size()<<endl;
        }   
        else{
            cout<<"No Solution Exists!!!";
        }
    }
#endif
