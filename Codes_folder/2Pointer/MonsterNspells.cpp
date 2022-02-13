// https://codeforces.com/contest/1626/problem/C


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].first; // appearance time of monsters
        }
        for(int i=0;i<n;i++){
            cin>>v[i].second; // health of monsters
        }
        int totalmana = 0;
        
        int maxa = v[n-1].second; // this store power to kill last monster
        int maxId = v[n-1].first; // appearance time of last monster
        int last = v[n-1].first;
        int now = maxa;
        
        for(int i=n-2;i>=0;i--){
            if(last-now >= v[i].first){
                totalmana = totalmana + (maxa*(maxa+1))/2;
                maxa = v[i].second,last=v[i].first,now=maxa,maxId=last;
            }
            else if(now-(last-v[i].first)>=v[i].second){
                continue;
            }
            else{
                maxa = v[i].second + maxId - v[i].first;
                last = v[i].first;
                now = v[i].second;
            }
        }
        totalmana = totalmana + (maxa*(maxa+1))/2;
        cout<<totalmana<<"\n";
    }
}
