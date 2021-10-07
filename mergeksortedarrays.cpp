//in this question i had to merge k sorted array , for which i have used priority queue . each element of queue
//contain three things the no. of the array in which that number is present , inside that array where it is present and the value of the number.
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,pair<int,int>> pii;
vector<int> outputarray(vector<vector<int>> array){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<int> output;
    for(int i=0;i<array.size();i++){
        pq.push({array[i][0],{i,0}});

    }
    while(!pq.empty()){
        pii curr=pq.top();
        pq.pop();
        output.push_back(curr.first);
        int i=curr.second.first;
        int j=curr.second.second;
        if(j+1<array[i].size()){
            pq.push({array[i][j+1],{i,j+1}});
        }
    }
    return output;
}
int main(){
    vector<vector<int>> array={{1,3,5},
                                {2,7},
                                {6,8,9}};
    vector<int>output=outputarray(array);
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<endl;
    }
    return 0;
}
