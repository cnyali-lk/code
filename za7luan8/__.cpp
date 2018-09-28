/*
Author: CNYALI_LK
LANG: C++
PROG: __.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
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
int a[3023],f[3023];
int main(){
#ifdef cnyali_lk
	freopen("__.in","r",stdin);
	freopen("__.out","w",stdout);
#endif
	int t,n,b,l,k;
	t=read();
	for(;t;--t){
	
		b=read();l=read();k=read();n=read();
		for(int i=1;i<=n;++i)a[i]=read();
		a[n+1]=0;
		for(int i=1;i<=n+1;++i){
			f[i]=0x3f3f3f3f;
			for(int j=1;j<=i&&j<=l;++j)chkmin(f[i],f[i-j]);
			f[i]+=max(a[i]-k,0);
		}
		if(f[n+1]<=b)printf("%d\n",b-f[n+1]);
		else printf("-1\n");
	}

	return 0;
}

