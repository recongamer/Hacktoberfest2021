/*
    Prim’s algorithm using priority_queue in STL
    Time complexity : O(E Log V))
*/

/*
    Given an undirected, connected and weighted graph, find Minimum Spanning Tree (MST) of the graph using Prim’s algorithm.
*/
#include<bits/stdc++.h>
using namespace std;

 /* Initialize keys of all vertices as infinite and 
   parent of every vertex as -1. 
   Create an empty priority_queue Q.  Every item
   of Q is a pair (weight, vertex). Weight (or 
   key) is used used as first item  of pair
   as first item is by default used to compare
   two pairs.
   Initialize all vertices as not part of MST yet.
   We use boolean array inMST[] for this purpose.
   This array is required to make sure that an already
   considered vertex is not included in pq again. This
   is where Prim's implementation differs from Dijkstra.
   In Dijkstr's algorithm, we didn't need this array as
   distances always increase. We require this array here 
   because key value of a processed vertex may decrease
   if not checked.
    
   Insert source vertex into Q and make its key as 0.
   
       While either Q doesn't become empty 
    a) Extract minimum key vertex from pq. 
       Let the extracted vertex be u.
    b) Include u in MST using inMST[u] = true.
    c) Loop through all adjacent of u and do 
       following for every vertex v.
           // If weight of edge (u,v) is smaller than
           // key of v and v is not already in MST
           If inMST[v] = false && key[v] > weight(u, v)
               (i) Update key of v, i.e., do
                     key[v] = weight(u, v)
               (ii) Insert v into the Q
               (iv) parent[v] = u
   
       Print MST edges using parent array.
       
*/
int main()
{
   int n,m,source,i,j,a,b,wt;
   cin>>n>>m>>source;
   vector<pair<int,int>>adj[n];
   for(i=0;i<m;i++){
       cin>>a>>b>>wt;
       adj[a].push_back({b,wt});adj[b].push_back({a,wt});
   }

    // Create a priority queue to store vertices that
    // are being preinMST.
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >Q;
    
    // Create a vector for keys and initialize all
    // keys as infinite (INF)
   vector<int>key(n,INT_MAX);
     // To store parent array which in turn store MST
   vector<int>parent(n,-1);
    
    // To keep track of vertices included in MST
   vector<bool>inMST(n,0);

   key[source]=0;
    
 
    // Insert source itself in priority queue and initialize
    // its key as 0.
   Q.push({0,source});

   while(!Q.empty()){
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
         int u=Q.top().second;Q.pop();
       
        //Different key values for same vertex may exist in the priority queue.
        //The one with the least key value is always processed first.
        //Therefore, ignore the rest.
            if(inMST[u]) continue;

         inMST[u]=1; // Include vertex in MST

           for(auto it:adj[u]){
               // Get vertex label and weight of current adjacent
               // of u.
               int v=it.first;
               int weight=it.second;
               
             //  If v is not in MST and weight of (u,v) is smaller
              // than current key of v
               if(!inMST[v] && key[v]>weight){
                   // Updating key of v
                   key[v]=weight;
                   parent[v]=u;
                   Q.push({key[v],v});
               }
           }
   }
    
    // Print edges of MST using parent array
   for(i=0;i<n;i++) if(i!=source) cout<<parent[i]<<" "<<i<<"\n";
    return 0;
}
