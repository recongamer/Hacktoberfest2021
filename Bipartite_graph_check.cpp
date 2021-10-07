#include <iostream>
#include <queue>
using namespace std;
bool helper(bool** adj,int vertices,int* color,int start,bool* visited){
    queue<int> left;
    color[start]=1;
    visited[start]=true;
    left.push(start);
    while(!left.empty()){
        int a=left.front();
        left.pop();
        for(int i=0;i<vertices;i++){
            if(adj[a][i]){
                if(visited[i] && color[i]!=1-color[a]){
                    return false;
                }
                if(!visited[i]){
                    color[i]=1-color[a];
                    left.push(i);
                    visited[i]=true;
                }
            }
        }
    }
    return true;
}

int main()
{
    int vertices,edges;
    cin>>vertices>>edges;
    bool** adj=new bool*[vertices];
    for(int i=0;i<vertices;i++){
        adj[i]=new bool[vertices];
        for(int j=0;j<vertices;j++){
            adj[i][j]=false;
        }
    }
    for(int i=0;i<edges;i++){
        int a,b;
        cin>>a>>b;
        adj[a][b]=true;
        adj[b][a]=true;
    }
    int* color=new int[vertices];
    bool* visited=new bool[vertices];
    for(int i=0;i<vertices;i++){
        visited[i]=false;
    }
    for(int i=0;i<vertices;i++){
        color[i]=0;
    }
    bool bipartite=true;

    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            if(helper(adj,vertices,color,i,visited)==false){
                    bipartite=false;
               break;
            }
        }
    }
    if(bipartite){
        cout<<"bipartition is possible"<<endl;
    }
    else{
        cout<<"bipartition is not possible"<<endl;
    }

    return 0;
}
