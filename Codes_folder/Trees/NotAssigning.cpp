// https://codeforces.com/contest/1627/problem/C

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        // adjacency list representation of tree
        vector<vector<int>> adj(n+1); 

        // stores position of each edge in the input
        map<pair<int,int>,int> pos;

        // for each edge in the input what is the valid weight corresponding to input position
        vector<int> ans(n);

        // deg stores the number of adjucent nodes
        vector<int> deg(n+1,0);

        // visited vector keep check of is the given node visited or not
        vector<bool> vis(n+1,false);

        for(int i=1;i<=(n-1);i++){
            int u,v;
            cin>>u>>v;

            adj[u].push_back(v);
            adj[v].push_back(u);

            deg[u]++;
            deg[v]++;
            pos[{u,v}] = i;
            pos[{v,u}] = i;
        }

        // check whether deh[i] <= 2 for all i's
        bool is = true; 
        // this represent start ans end of an chain graph or line graph
        int s = -1, e = -1;

        for(int i=1;i<=n;i++){
            if(deg[1]>=3){
                is = false;
                break;
            }
            if(deg[i]==1){
                if(s == -1){
                    s = i;
                }
                else{
                    e = i;
                }
            }
        }

        if(!is){
            cout<<-1<<"\n";
            continue;
        }

        int currentNode = s;
        int weight = 2; // current edge weight

        while(currentNode != e){
            int nextNode = adj[currentNode][0];

            if(vis[nextNode]){
                nextNode = adj[currentNode][1];
            }

            // stores the weight of edge in input to be equal to currebt weight
            ans[pos[{currentNode,nextNode}]] = weight;

            if(weight == 2){
                weight = 3;
            }
            else{
                weight = 2;
            }

            vis[currentNode] = true;
            currentNode = nextNode;
        }

        for(int i=1;i<=(n-1);i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}