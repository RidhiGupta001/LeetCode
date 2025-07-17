#include <iostream>
#include <vector>
#include <string>
using namespace std;

//reusable code snippet

class DisjointSet{
vector<int> rank,parent ;
public:
DisjointSet(int n){
 rank.resize(n+1,0);
 parent.resize(n+1,0);
 for(int i = 1;i<=n ; i++){
    parent[i] = i;    //initial every node is disconnected 
 }   
 }
 int findUParent(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = findUParent(parent[node]); //finding the ultimate parent 
    }

void unionbyrank(int u, int v){
    int u_par_u = findUParent(u);
    int u_par_v = findUParent(v);

    if(u_par_u == u_par_v){
        return;
    }else if(rank[u_par_u > u_par_v]){
        parent[u_par_v] = u_par_u;
    }else if(rank[u_par_u < u_par_v]){
        parent[u_par_u] = u_par_v;
    }else{
        parent[u_par_u] = u_par_v;
        rank[u_par_v]++;
    }
}
};

//using the code snippet 

int main(){
    DisjointSet ds(7);  //7 nodes
    ds.unionbyrank(1,2);
    ds.unionbyrank(3,4);
    ds.unionbyrank(6,7);

    int p_3 = ds.findUParent(3);
    int p_7 = ds.findUParent(7);
    if(p_3 == p_7){
        cout<<"in the same component"<<endl;
    }else{
        cout<<"not in the same component"<<endl;
    }
    ds.unionbyrank(3,7);

    p_3 = ds.findUParent(3);
    p_7 = ds.findUParent(7);
    if(p_3 == p_7){
        cout<<"in the same component"<<endl;
    }else{
        cout<<"not in the same component"<<endl;
    }
    return 0;
}