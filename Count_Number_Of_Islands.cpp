#include <iostream>
using namespace std;

struct queue 
{
    int size=100;
    int rear=-1;
    int front=-1;
    int elements[100][2];
};

void enqueue(struct queue &q,int x,int y)
{
    if(((q.rear+1)%(q.size))==q.front)
    cout<<"Queue is Full :\n";
    else if(q.front==-1)
    {
        q.rear=0;q.front=0;
    }
    else
        q.rear=(q.rear+1)%(q.size);
        q.elements[q.rear][0]=x;
        q.elements[q.rear][1]=y;
}
int dequeue(struct queue &q)
{
    int t=-1;
    if(q.front==-1)
    cout<<"empty \n";
    else if(q.front==q.rear)
    {
        t=q.front;
        q.front=-1;q.rear=-1;
    }
    else
    {
        t=q.front;
        q.front=((q.front+1)%(q.size));
    }
    return t;
}
bool check(int island[][10],int visit[][10],int x,int y)
{
    return (x<10 && x>-1 && y<10 && y>-1 && island[x][y] && !visit[x][y]);
}
int main()
{
    int island[10][10]={{1,0,1,0,0,0,1,1,1,1},
                     {0,0,1,0,1,0,1,0,0,0},
                     {1,1,1,1,0,0,1,0,0,0},
                     {1,0,0,1,0,1,0,0,0,0},
                     {1,1,1,1,0,0,0,1,1,1},
                     {0,1,0,1,0,0,1,1,1,1},
                     {0,0,0,0,0,1,1,1,0,0},
                     {0,0,0,1,0,0,1,1,1,0},
                     {1,0,1,0,1,0,0,1,0,0},
                     {1,1,1,1,0,0,0,1,1,1}};
    
    int i,j,x,y,z,count=0;
    int visited[10][10]={0};
    struct queue q ;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
           if(island[i][j] && !visited[i][j])
            {
                
               count++;
               visited[i][j]==1;
               enqueue(q,i,j);
               while(q.front!=-1 && q.rear!=-1)
               {
                   z=dequeue(q);
                   x=q.elements[z][0];
                   y=q.elements[z][1];
                   if(check(island,visited,x-1,y))
                   {
                       visited[x-1][y]=1;
                       enqueue(q,x-1,y);
                   }
                   if(check(island,visited,x+1,y))
                   {
                       visited[x+1][y]=1;
                       enqueue(q,x+1,y);
                   }
                   if(check(island,visited,x,y-1))
                   {
                       visited[x][y-1]=1;
                       enqueue(q,x,y-1);
                   }
                   if(check(island,visited,x,y+1))
                   {
                       visited[x][y+1]=1;
                       enqueue(q,x,y+1);
                   }
                    if(check(island,visited,x-1,y+1))
                   {
                       visited[x-1][y+1]=1;
                       enqueue(q,x-1,y+1);
                   }
                   if(check(island,visited,x+1,y+1))
                   {
                       visited[x+1][y+1]=1;
                       enqueue(q,x+1,y+1);
                   }
                   if(check(island,visited,x-1,y-1))
                   {
                       visited[x-1][y-1]=1;
                       enqueue(q,x-1,y-1);
                   }
                   if(check(island,visited,x+1,y-1))
                   {
                       visited[x+1][y-1]=1;
                       enqueue(q,x+1,y-1);
                   }
               }
            } 
        }
    }
    cout<<count<<"\n";
    return 0;
    
}


