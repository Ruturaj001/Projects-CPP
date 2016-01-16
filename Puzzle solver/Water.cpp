#include "Water_State.h"
#include "Water.h"
#include <iostream>
#include <vector>
#include<fstream>

using namespace std;

vector<Water_State> Water:: getNext(Water_State current){
        vector<Water_State> toReturn;
        //fill every bucket to its capacity
        for(int i=0;i<noOfBuckets;i++){
            if(current.holding[i]!=current.capacity[i]){
                Water_State toAdd(&current);
                toAdd.holding[i]=toAdd.capacity[i];
                toReturn.push_back(toAdd);
            }
        }
        //empty every bucket
        for(int i=0;i<noOfBuckets;i++){
            if(current.holding[i]!=0){
                Water_State toAdd(&current);
                toAdd.holding[i]=0;
                toReturn.push_back(toAdd);
            }
        }
        //transfer
        for(int i=0;i<noOfBuckets;i++){
            for(int j=0;j<noOfBuckets;j++){
                //check if i th bucket is not empty and j th bucket is not full
                if(i!=j && current.holding[i]!=0 && current.holding[j]!=current.capacity[j]){
                    Water_State toAdd(&current);
                    //transfer till j is full
                    if(current.holding[j]+current.holding[i]>current.capacity[j]){
                        toAdd.holding[i]-=toAdd.capacity[j]-toAdd.holding[j];
                        toAdd.holding[j]=toAdd.capacity[j];
                    }else{//transfer till i is empty
                        toAdd.holding[j]=toAdd.holding[j]+toAdd.holding[i];
                        toAdd.holding[i]=0;
                    }
                    toReturn.push_back(toAdd);
                }
            }
        }
        return toReturn;
}

Water_State Water::init(){
    vector<int> capacity;
    int temp;
    bool gotinput=false;
    cout<<"You want to give input \n1.terminal\n2.file\n";
    cin>>temp;
    do{
        if(temp==2){
            string filename;
            bool gotFile=false;
            do{
                cout<<"Enter file name\n";
                cin>>filename;
                ifstream myfile (filename.c_str());
                if (myfile.is_open()){
                    myfile>>want;
                    myfile>>noOfBuckets;
                    for(int i=0;i<noOfBuckets;i++){
                        myfile>>temp;
                        capacity.push_back(temp);
                    }
                    myfile.close();
                    gotFile=true;
                    gotinput=true;
                } else { 
                    cout << "Unable to open file\n";
                }
            }while(!gotFile); 
        } else if(temp==1){
            cout<<"How much water you want?\n";
            cin>>want;
            cout<<"Enter number of buckets\n";
            cin>>noOfBuckets;
            cout<<"Enter capacity of each bucket\n";
            for(int i=0;i<noOfBuckets;i++){
                cin>>temp;
                capacity.push_back(temp);
            }
            gotinput=true;
        }else{  
            cout<<"Wrong input\n";
        }
    }while(!gotinput);
    
    cout<<"You want output on \n1.terminal\n2.file\n";
    cin>>temp;
    if(temp==2){
        cout<<"Enter outputfile name\n";
        cin>>outputfile;
        fileoutput=true;
    }else
        fileoutput=false;
    Water_State first(capacity);
    return first;
}

bool Water::solved(Water_State current){
    for(int i=0;i<current.holding.size();i++){
        if(current.holding[i]==want)
            return true;
    }
    return false;
} 

void Water:: print(vector<Water_State> answer){
    if(fileoutput){
        ofstream myfile (outputfile.c_str());
        if (myfile.is_open()){
            for(int i=0;i<answer.size();i++){
                for(int j=0;j<noOfBuckets;j++){
                    myfile<<answer[i].holding[j]<<"/"<<answer[i].capacity[j]<<"\t";
                }
                myfile<<endl;
            }
        }
        else cout << "Unable to open file";
    } else{
        for(int i=0;i<answer.size();i++){
            for(int j=0;j<noOfBuckets;j++){
                cout<<answer[i].holding[j]<<"/"<<answer[i].capacity[j]<<"\t";
            }
            cout<<endl;
        }
    }
}
