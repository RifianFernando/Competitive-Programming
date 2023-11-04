#include<bits/stdc++.h>
using namespace std;

long long max(long long a, long long b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    int n;
    long long p,x;
    scanf("%d %lld %lld",&n,&p,&x);
    
    long long b[n+5], sum=0LL, hsl=p;
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
        sum+=b[i];
    }
    
    long long pos;
    b[0]=0;  
    for(int i=0;i<=n-1;i++){
        p+=b[i];
        //printf("p: %lld\n",p);
        //printf("p-1: %lld\n",p+1*sum);
        //printf("p-2: %lld\n",p+2*sum);
        pos = max(0LL, ((p-x) / abs(sum)));
        if(p+pos*sum>=x){
            hsl=min(hsl,p+pos*sum); 
        } 
    }
    
    if(hsl < x) printf("-1\n");
    else printf("%lld\n",hsl);
}