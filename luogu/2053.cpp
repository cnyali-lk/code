/*
Author: CNYALI_LK
LANG: C++
PROG: 2053.cpp
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
char WriteIntBuffer[1024];
template<class T>void write(T a,char end){
	int cnt=0,fu=1;
	if(a<0){putchar('-');fu=-1;}
	do{WriteIntBuffer[++cnt]=fu*(a%10)+'0';a/=10;}while(a);
	while(cnt){putchar(WriteIntBuffer[cnt]);--cnt;}
	putchar(end);
}
struct MCF{
	int to[260817],lst[260817],w[260817],beg[192608],c[260817],n,e;
	MCF(){e=1;}
	void add(int u,int v,int wa,int cost){
		to[++e]=v;lst[e]=beg[u];beg[u]=e;c[e]=cost;w[e]=wa;
		to[++e]=u;lst[e]=beg[v];beg[v]=e;c[e]=-cost;w[e]=0;
	}
	int mincost,dis[1926081],flw[1926081],pre[1926081],inq[1926081];
	int q[19260817],*l,*r;
	int spfa(int s,int t){
		for(int i=1;i<=n;++i)dis[i]=0x3f3f3f3f,pre[i]=flw[i]=0;
		flw[s]=0x3f3f3f3f;
		pre[s]=0;
		*(l=r=q)=s;
		dis[s]=0;
		while(l<=r){
			inq[*l]=0;
			for(int i=beg[*l];i;i=lst[i])if(w[i]&&chkmin(dis[to[i]],dis[*l]+c[i])){
				pre[to[i]]=i;
				flw[to[i]]=min(flw[*l],w[i]);
				if(!inq[to[i]]){
					inq[to[i]]=1;
					*(++r)=to[i];
				}
			}
			++l;
		}
		if(!flw[t])return 0;
		int flow=flw[t];
		mincost+=flow*dis[t];
		while(pre[t]){
			s=pre[t];	
			w[s]-=flow;
			w[s^=1]+=flow;	
			t=to[s];
		}
		return flow;
	}
	int Min_Cost_Flow(int s,int t){
		while(spfa(s,t));
		return mincost;
	}
};
MCF Min_Cost_Flow;
int car[19260],xc[192][192],wx[192][192];
int main(){
#ifdef cnyali_lk
	freopen("2053.in","r",stdin);
	freopen("2053.out","w",stdout);
#endif
	int n,m;
	m=read();n=read();	
	int s=1,t=2,poicnt=2;
	for(int i=1;i<=n;++i){
		car[i]=++poicnt;
	}
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){
		xc[i][j]=read();
		wx[j][i]=++poicnt;
	}
	Min_Cost_Flow.n=poicnt;
	for(int i=1;i<=n;++i){
		Min_Cost_Flow.add(s,car[i],1,0);
		for(int j=1;j<=m;++j){
			Min_Cost_Flow.add(wx[j][i],t,1,0);
			for(int k=1;k<=n;++k)Min_Cost_Flow.add(car[i],wx[j][k],1,xc[i][j]*k);
		}
	}
	printf("%.2lf",Min_Cost_Flow.Min_Cost_Flow(s,t)*1./n);
	return 0;
}

