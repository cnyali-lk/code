/*
Author: CNYALI_LK
LANG: C++
PROG: d.cpp
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
template<class T>int dcmp(T a,T b){return a>b;}
template<int *a>int cmp_a(int x,int y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
int read(){
	int s=0;
	int base=0;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=1;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	if(base)s=-s;
	return s;
}
int t[204847],fa[19][204847],mx[19][204847],dp[204847];
int main(){
#ifdef cnyali_lk
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
#endif
	int n;
	n=read();
	for(int i=2;i<=n;++i)fa[0][i]=read();
	for(int i=n;i;--i)t[read()]=i;
	for(int i=2;i<=n;++i)mx[0][i]=t[fa[0][i]];
	for(int i=1;i<=18;++i)for(int j=1;j<=n;++j){
		fa[i][j]=fa[i-1][fa[i-1][j]];
		mx[i][j]=max(mx[i-1][j],mx[i-1][fa[i-1][j]]);
	}
	dp[1]=1;
	printf("1\n");
	for(int i=2;i<=n;++i){
		int x=i;
		for(int j=18;~j;--j)if(mx[j][x]<=t[i])x=fa[j][x];
		dp[i]=dp[fa[0][x]]+1;
		printf("%d\n",dp[i]);
	}

	return 0;
}

