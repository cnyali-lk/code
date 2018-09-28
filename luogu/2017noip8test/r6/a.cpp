/*
Author: CNYALI_LK
LANG: C++
PROG: a.cpp
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
	int s=0,base=1;
	char c;
	while(!isdigit(c=getchar()))if(c=='-')base=-base;
	while(isdigit(c)){s=s*10+(c^48);c=getchar();}
	return s*base;
}
char a[1000005],b[1005];
int nxt[1000005][27],f[1005][1005];
int main(){
#ifdef cnyali_lk
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	scanf("%s%s",a+1,b+1);
	int n=strlen(a+1),m=strlen(b+1);
	for(int i=0;i<26;++i)nxt[n+1][i]=nxt[n+2][i]=n+1;
	for(int i=n;i;--i){
		for(int j=0;j<26;++j)nxt[i][j]=nxt[i+1][j];	
		nxt[i][a[i]-'a']=i;
	}
	for(int i=1;i<=m;++i)for(int j=1;j<=m;++j)f[i][j]=n+1;
	for(int i=0;i<m;++i)for(int j=0;j<=i;++j){
		chkmin(f[i+1][j],f[i][j]);
		chkmin(f[i+1][j+1],nxt[f[i][j]+1][b[i+1]-'a']);
	}
//	for(int i=0;i<=m;++i)for(int j=0;j<=i;++j)printf("%d%c",f[i][j],j==i?'\n':' ');
	for(int i=m;~i;--i)if(f[m][i]<=n){printf("%d\n",i);return 0;}
	return 0;
}

