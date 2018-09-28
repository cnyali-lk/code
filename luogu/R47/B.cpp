
/*
Author: CNYALI_LK
LANG: C++
PROG: B.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
typedef long long ll;
typedef pair<int,int> pii;
template<class T>int chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>int chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
#define min mmin
#define max mmax
#define abs aabs
int read(){
    int s=0,base=1;
    char c;
    while(!isdigit(c=getchar()))if(c=='-')base=-base;
    while(isdigit(c)){s=s*10+(c^48);c=getchar();}
    return s*base;
}
double x[102424],y[102424],xx,yy,a,b;
int main(){
#ifdef cnyali_lk
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
#endif
    srand(time(0));
    int n,l;
    scanf("%d%d",&n,&l);
    for(int i=1;i<=n;++i){
        scanf("%lf%lf",x+i,y+i);
    }
//	printf("%d\n",CLOCKS_PER_SEC);
    while(clock()<1950000){
        a=(rand()*1./2147483647)*l;

        b=rand()&1?0:l;
        if(rand()&1)xx=b,yy=a;
        else xx=a,yy=b;
        int ok=1;
        for(int i=1;i<=n;++i){
            if(sqr(xx-x[i])+sqr(yy-y[i])-sqr(l*1./n)<-eps){ok=0;break;}
        }
        if(ok){printf("%lf %lf\n",xx,yy);return 0;}
    }
    printf("GG\n");
    return 0;
}

