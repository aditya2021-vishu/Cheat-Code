// https://www.codechef.com/JAN222C/problems/SUMANDOR
#include<bits/stdc++.h>
using namespace std;

bool possible(long long x, long long s, long long cnt){
    long long sum = s-x;
    cnt--;
    int B = 29;
    for(int b=B;b>=0;b--){
        if(((x>>b)&1)==0) continue;
        long long times = min(cnt,sum/(1L<<b));
        sum = sum - times*(1L<<b);
    }
    return sum == 0;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,s;
        cin>>x>>s;

        long long l = 1, r = 1e9+1;
        while(l<r){
            int m = l + (r-l)/2;
            if(possible(x,s,m)){
                r = m;
            }
            else{
                l = m+1;
            }
        }
        if(r > 1e9) r = -1;
        cout<<r<<"\n";
    }
}


