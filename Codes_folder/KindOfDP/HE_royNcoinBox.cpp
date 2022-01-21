/*
https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/roy-and-coin-boxes-1/?utm_source=header&utm_medium=search&utm_campaign=he-search
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;
    vector<long long> arr(n+1,0);
    while(m--){
        long long u,v;
        cin>>u>>v;
        arr[u]++;
        if(v+1 <= m){
            arr[v+1] -= 1;
        }
    }
    for(long long i=1;i<=n;i++){
        arr[i] = arr[i]+arr[i-1];
    }
	vector<long long> answer(100005,0);
    for(long long i=0;i<=n;i++){
        answer[arr[i]]+=1;
    }
    for(long long i=answer.size()-2;i>=0;i--){
        answer[i] = answer[i]+answer[i+1];
    }
    long long q;
    cin>>q;
    while(q--){
        long long x;
        cin>>x;
        cout<<answer[x]<<"\n";
    }
}