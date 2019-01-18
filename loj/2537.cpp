/*
Author: CNYALI_LK
LANG: C++
PROG: 2537.cpp
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
typedef long long ll;
typedef pair<int,int> pii;
const signed inf=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
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
namespace io {
	const int SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; int f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// print the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed integer
	inline void read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}

	inline void read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	inline void read (char &x) {
		x=gc();
	}
	inline void read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
	}
	template<typename A,typename ...B>
	inline void read(A &x,B &...y){
		read(x);read(y...);
	}
	// print a signed integer
	inline void write (signed x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}

	inline void write (long long x) {
		if (!x) putc ('0'); if (x < 0) putc ('-'), x = -x;
		while (x) qu[++ qr] = x % 10 + '0',  x /= 10;
		while (qr) putc (qu[qr --]);
	}
	inline void write (char x) {
		putc(x);
	}
	inline void write(const char *x){
		while(*x){putc(*x);++x;}
	}
	inline void write(char *x){
		while(*x){putc(*x);++x;}
	}
	template<typename A,typename ...B>
	inline void write(A x,B ...y){
		write(x);write(y...);
	}
	//no need to call flush at the end manually!
	struct Flusher_ {~Flusher_(){flush();}}io_flusher_;
}
using io :: read;
using io :: putc;
using io :: write;
const int p=998244353,I=796898467;
int sum(int a,int b){return (a+=b)>=p?a-p:a;}
int ans,cnt;
int pSum;
struct smt{
	int ls,rs,tag,pall;
#define mid ((ls+rs)>>1)
	smt *l,*r;
	smt *visl(){return l?l:l=new smt(ls,mid);}
	smt *visr(){return r?r:r=new smt(mid+1,rs);}
	smt(int la,int ra){ls=la;rs=ra;l=r=0;tag=1;pall=0;}
	void push_up(){
		pall=0;
		if(l)pall=sum(pall,l->pall);
		if(r)pall=sum(pall,r->pall);
	}
	void put_tag(int w){
		tag=(ll)tag*w%p;
		pall=(ll)pall*w%p;
	}
	void push_down(){
		if(l)l->put_tag(tag);
		if(r)r->put_tag(tag);
		tag=1;
	}
	void getans(){			
		if(ls==rs){++cnt;ans=sum(ans,(ll)cnt*pall%p*pall%p*ls%p);pSum=sum(pSum,pall);return;}
		push_down();
		if(l)l->getans();
		if(r)r->getans();
	}
	void insert(int x){
		tag=pall=1;
		if(ls==rs)return;
		if(x<=mid)visl()->insert(x);
		else visr()->insert(x);
	}
};
smt *rt[300005];
int fa[300005],w[300005];
vector<int> son[300005];
smt *merge(smt *a,smt *b,int pa,int pb,int pmx){
	if(!a && !b)return NULL;
	if(!a){b->put_tag(pa);return b;}
	if(!b){a->put_tag(pb);return a;}
	a->push_down();
	b->push_down();
	int pal=sum(pa,a->r?((ll)(a->r->pall)*sum(p-pmx,1)%p):0),pbl=sum(pb,b->r?((ll)(b->r->pall)*sum(p-pmx,1)%p):0),
		par=sum(pa,a->l?((ll)(a->l->pall)*pmx%p):0),pbr=sum(pb,b->l?((ll)(b->l->pall)*pmx%p):0);
	a->l=merge(a->l,b->l,pal,pbl,pmx);
	a->r=merge(a->r,b->r,par,pbr,pmx);
	a->push_up();
	return a;
} 
void dfs(int x){
	if(son[x].empty()){
		rt[x]=new smt(0,(1<<30)-1);
		rt[x]->insert(w[x]);
	}
	else{w[x]=(ll)w[x]*I%p;for(auto i:son[x])dfs(i);if(son[x].size()==1)rt[x]=rt[son[x][0]];else rt[x]=merge(rt[son[x][0]],rt[son[x][1]],0,0,w[x]);}
}
int main(){
#ifdef cnyali_lk
	freopen("2537.in","r",stdin);
	freopen("2537.out","w",stdout);
#endif
	int n;	
	read(n);
	for(int i=1;i<=n;++i){
		read(fa[i]);	
		son[fa[i]].push_back(i);
	}
	for(int i=1;i<=n;++i){
		read(w[i]);
	}
	dfs(1);
	rt[1]->getans();
	printf("%d\n",ans);
	return 0;
}
