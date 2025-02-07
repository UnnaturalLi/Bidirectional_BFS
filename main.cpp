
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
struct State {
    int mapLayout[4][3];
    int depth;
    State* lastState;
    string lastMove;
    long long code;
    long long GenerateCode(){
        code=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            code*=10;
            code+=mapLayout[i][j];
        }
    }
    code*=10;
    code+=mapLayout[3][2];
    return code;
    }
};
bool CheckFinish(State current){
    if(current.mapLayout[3][2]!=0){
        
        return false;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(current.mapLayout[i][j]!=i*3+j+1){
                return false;
            }
        }
    }
    return true;
}
bool CheckMeet(State current,vector <long long> codes){
    for(int i=0;i<codes.size();i++){
        if(current.code==codes[i]){
            return true;
        }
    }
    return false;
}
State* BFS(vector<long long>& codes,queue<State*>& BFSQ,bool map[4][3],State* searchState,bool& finishedFlag,vector<State*>& list,bool isBack,vector<State*> frontList,vector<long long>& Fcodes){
    //cout<<searchState->code<<endl;
    if(isBack&&CheckMeet(*searchState, Fcodes)){
        finishedFlag=true;
        cout<<"Meet";
        for(int i=0;i<frontList.size();i++){
            if(frontList[i]->code==searchState->code){
                cout<<"Return";
                return frontList[i];
            }
        }
    }else if(searchState->depth>40){
        return  nullptr;
    }else {
        bool found=false;
        int i=0;
        int j=0;
        for(i=0;i<4&&found==false;i++){
            for(j=0;j<3&&found==false;j++){
                if(searchState->mapLayout[i][j]==0&&map[i][j]==true){
                    found=true;
                }
            }
        }
        i--;
        j--;
        if(!isBack){
            if(i+1<=3&&map[i+1][j]){
                State* down = new State;
                down->lastMove = "move " + std::to_string(i + 2) + " " + std::to_string(j + 1) +
                " to " + std::to_string(i + 1) + " " + std::to_string(j + 1);
                down->lastState = searchState;
                
                // 复制状态
                for(int m = 0; m < 4; m++) {
                    for(int n = 0; n < 3; n++) {
                        down->mapLayout[m][n] = searchState->mapLayout[m][n];
                    }
                }
                
                // 交换位置
                int tem = down->mapLayout[i+1][j];
                down->mapLayout[i+1][j] = down->mapLayout[i][j];
                down->mapLayout[i][j] = tem;
                
                down->depth = searchState->depth + 1;
                
                down->GenerateCode();
                bool sameFlag=false;
                for(int i=0;i<codes.size();i++){
                    if(codes[i]==down->code){
                        sameFlag=true;
                    }
                }
                if(sameFlag==false){
                    BFSQ.push(down);
                    list.push_back(down); codes.push_back(down->code);}
            }
            if(i-1>=0&&map[i-1][j]){
                State* down = new State;
                down->lastMove = "move " + to_string(i) + " " +to_string(j + 1) +
                " to " +to_string(i + 1) + " " +to_string(j + 1);
                down->lastState = searchState;
                
                // 复制状态
                for(int m = 0; m < 4; m++) {
                    for(int n = 0; n < 3; n++) {
                        down->mapLayout[m][n] = searchState->mapLayout[m][n];
                    }
                }
                
                // 交换位置
                int tem = down->mapLayout[i-1][j];
                down->mapLayout[i-1][j] = down->mapLayout[i][j];
                down->mapLayout[i][j] = tem;
                
                down->depth = searchState->depth + 1;
                
                down->GenerateCode();
                bool sameFlag=false;
                for(int i=0;i<codes.size();i++){
                    if(codes[i]==down->code){
                        sameFlag=true;
                    }
                }
                if(sameFlag==false){
                    
                    BFSQ.push(down);codes.push_back(down->code);
                    list.push_back(down);}
                
            }
            
            if(j+1<=2&&map[i][j+1]){
                State* down = new State;
                down->lastMove = "move " + std::to_string(i + 1) + " " + std::to_string(j + 2) +
                " to " + std::to_string(i + 1) + " " + std::to_string(j + 1);
                down->lastState = searchState;
                
                // 复制状态
                for(int m = 0; m < 4; m++) {
                    for(int n = 0; n < 3; n++) {
                        down->mapLayout[m][n] = searchState->mapLayout[m][n];
                    }
                }
                
                // 交换位置
                int tem = down->mapLayout[i][j+1];
                down->mapLayout[i][j+1] = down->mapLayout[i][j];
                down->mapLayout[i][j] = tem;
                
                down->depth = searchState->depth + 1;
                
                down->GenerateCode();
                bool sameFlag=false;
                for(int i=0;i<codes.size();i++){
                    if(codes[i]==down->code){
                        sameFlag=true;
                    }
                }
                if(sameFlag==false){
                    
                    BFSQ.push(down);
                    codes.push_back(down->code);
                    list.push_back(down);
                }
            }
            
            if(j-1>=0&&map[i][j-1]){
                State* down = new State;
                down->lastMove = "move " + std::to_string(i + 1) + " " + std::to_string(j) +
                " to " + std::to_string(i + 1) + " " + std::to_string(j + 1);
                down->lastState = searchState;
                
                // 复制状态
                for(int m = 0; m < 4; m++) {
                    for(int n = 0; n < 3; n++) {
                        down->mapLayout[m][n] = searchState->mapLayout[m][n];
                    }
                }
                
                // 交换位置
                int tem = down->mapLayout[i][j-1];
                down->mapLayout[i][j-1] = down->mapLayout[i][j];
                down->mapLayout[i][j] = tem;
                
                down->depth = searchState->depth + 1;
                
                down->GenerateCode();
                bool sameFlag=false;
                for(int i=0;i<codes.size();i++){
                    if(codes[i]==down->code){
                        sameFlag=true;
                    }
                }
                BFSQ.push(down);codes.push_back(down->code);
                list.push_back(down);
            }
            
        }else{
            
                if(i+1<=3&&map[i+1][j]){
                    State* down = new State;
                    down->lastMove = "move " +  std::to_string(i + 1) + " " + std::to_string(j + 1) +
                    " to " +std::to_string(i + 2) + " " + std::to_string(j + 1);
                    down->lastState = searchState;
                    
                    // 复制状态
                    for(int m = 0; m < 4; m++) {
                        for(int n = 0; n < 3; n++) {
                            down->mapLayout[m][n] = searchState->mapLayout[m][n];
                        }
                    }
                    
                    // 交换位置
                    int tem = down->mapLayout[i+1][j];
                    down->mapLayout[i+1][j] = down->mapLayout[i][j];
                    down->mapLayout[i][j] = tem;
                    
                    down->depth = searchState->depth + 1;
                    
                    down->GenerateCode();
                    bool sameFlag=false;
                    for(int i=0;i<codes.size();i++){
                        if(codes[i]==down->code){
                            sameFlag=true;
                        }
                    }
                    if(sameFlag==false){
                        BFSQ.push(down);
                        list.push_back(down); codes.push_back(down->code);}
                }
                if(i-1>=0&&map[i-1][j]){
                    State* down = new State;
                    down->lastMove = "move " + to_string(i + 1) + " " +to_string(j + 1) +
                    " to " +to_string(i) + " " +to_string(j + 1);
                    down->lastState = searchState;
                    
                    // 复制状态
                    for(int m = 0; m < 4; m++) {
                        for(int n = 0; n < 3; n++) {
                            down->mapLayout[m][n] = searchState->mapLayout[m][n];
                        }
                    }
                    
                    // 交换位置
                    int tem = down->mapLayout[i-1][j];
                    down->mapLayout[i-1][j] = down->mapLayout[i][j];
                    down->mapLayout[i][j] = tem;
                    
                    down->depth = searchState->depth + 1;
                    
                    down->GenerateCode();
                    bool sameFlag=false;
                    for(int i=0;i<codes.size();i++){
                        if(codes[i]==down->code){
                            sameFlag=true;
                        }
                    }
                    if(sameFlag==false){
                        
                        BFSQ.push(down);codes.push_back(down->code);
                        list.push_back(down);}
                    
                }
                
                if(j+1<=2&&map[i][j+1]){
                    State* down = new State;
                    down->lastMove = "move " +  std::to_string(i + 1) + " " + std::to_string(j + 1)+
                    " to " + std::to_string(i + 1) + " " + std::to_string(j + 2);
                    down->lastState = searchState;
                    
                    // 复制状态
                    for(int m = 0; m < 4; m++) {
                        for(int n = 0; n < 3; n++) {
                            down->mapLayout[m][n] = searchState->mapLayout[m][n];
                        }
                    }
                    
                    // 交换位置
                    int tem = down->mapLayout[i][j+1];
                    down->mapLayout[i][j+1] = down->mapLayout[i][j];
                    down->mapLayout[i][j] = tem;
                    
                    down->depth = searchState->depth + 1;
                    
                    down->GenerateCode();
                    bool sameFlag=false;
                    for(int i=0;i<codes.size();i++){
                        if(codes[i]==down->code){
                            sameFlag=true;
                        }
                    }
                    if(sameFlag==false){
                        
                        BFSQ.push(down);
                        codes.push_back(down->code);
                        list.push_back(down);
                    }
                }
                
                if(j-1>=0&&map[i][j-1]){
                    State* down = new State;
                    down->lastMove = "move " + std::to_string(i + 1) + " " + std::to_string(j + 1) +
                    " to " + std::to_string(i + 1) + " " + std::to_string(j);
                    down->lastState = searchState;
                    
                    // 复制状态
                    for(int m = 0; m < 4; m++) {
                        for(int n = 0; n < 3; n++) {
                            down->mapLayout[m][n] = searchState->mapLayout[m][n];
                        }
                    }
                    
                    // 交换位置
                    int tem = down->mapLayout[i][j-1];
                    down->mapLayout[i][j-1] = down->mapLayout[i][j];
                    down->mapLayout[i][j] = tem;
                    
                    down->depth = searchState->depth + 1;
                    
                    down->GenerateCode();
                    bool sameFlag=false;
                    for(int i=0;i<codes.size();i++){
                        if(codes[i]==down->code){
                            sameFlag=true;
                        }
                    }
                    BFSQ.push(down);codes.push_back(down->code);
                    list.push_back(down);
                }
        }
        }
    
    return nullptr;
    
}
int main(){
    vector<State*> frontStatesList;
    vector<State*> backStatesList;
    vector<long long> frontStateCode;
    vector<long long> backStateCode;
    queue<State*> frontBFSQ;
    queue<State*> backFSQ;
    bool finish=false;
    bool map[4][3];
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){map[i][j]=true;}}
    map[3][0]=false;
    map[3][1]=false;
    int initState[4][3];
    State s;
    State back;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>initState[i][j];
            s.mapLayout[i][j]=initState[i][j];
            back.mapLayout[i][j]=i*3+j+1;
        }
    }
    back.mapLayout[3][2]=0;
    cin>>initState[3][2];
    s.mapLayout[3][2]=initState[3][2];
    s.mapLayout[3][0]=100;
    s.mapLayout[3][1]=100;
    s.lastMove="Start:\n";
    back.lastMove="End\n";
    s.lastState=nullptr;
    back.lastState=nullptr;
    s.depth=0;
    back.depth=0;
    s.GenerateCode();
    back.GenerateCode();
    cout<<back.code;
    frontBFSQ.push(&s);
    backFSQ.push(&back);
    
    State* finialS;
    State* first=&s;
    State* meetPoint=nullptr;
    cout<<"StartSearch..\n\n";
    while((frontBFSQ.size()>0||backFSQ.size()>0)&&finish==false){
        if(frontBFSQ.size()>0){
            BFS(frontStateCode, frontBFSQ,map,frontBFSQ.front(),finish,frontStatesList,false,frontStatesList,frontStateCode);
            frontBFSQ.pop();}
        if(backFSQ.size()>0){
            meetPoint=backFSQ.front();
            State* st=BFS(backStateCode, backFSQ,map,backFSQ.front(),finish,backStatesList,true,frontStatesList,frontStateCode);
            if(st!=nullptr){
                finish=true;
                cout<<"Set";
                finialS=st;
            };
            backFSQ.pop();
        }
    }
    cout<<"Search END\n";
    if(!finish){
        cout<<"Cannot solve"<<endl;
    }else{
        stack<State*> outStack;
        outStack.push(finialS);
        while (finialS->lastState!=nullptr&&finialS->lastState!=finialS&&finialS!=first) {
            outStack.push(finialS->lastState);
            finialS=finialS->lastState;
        }
        while (outStack.size()>0) {
            cout<<outStack.top()->lastMove<<endl;
            outStack.pop();
        }
        while(meetPoint->lastState!=nullptr){
            cout<<meetPoint->lastMove<<endl;
            meetPoint=meetPoint->lastState;
        }
    }
    return 0;
}
