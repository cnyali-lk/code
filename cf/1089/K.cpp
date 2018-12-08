/*
Author: CNYALI_LK
LANG: C++
PROG: K.cpp
Mail: cnyalilk@vip.qq.com
*/
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define DEBUG printf("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define Debug debug("Passing [%s] in LINE %lld\n",__FUNCTION__,__LINE__)
#define all(x) x.begin(),x.end()
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const signed inf=0x3f3f3f3f;
const double eps=1e-8;
const double pi=acos(-1.0);
template<class T>ll chkmin(T &a,T b){return a>b?a=b,1:0;}
template<class T>ll chkmax(T &a,T b){return a<b?a=b,1:0;}
template<class T>T sqr(T a){return a*a;}
template<class T>T mmin(T a,T b){return a<b?a:b;}
template<class T>T mmax(T a,T b){return a>b?a:b;}
template<class T>T aabs(T a){return a<0?-a:a;}
template<class T>ll dcmp(T a,T b){return a>b;}
template<ll *a>ll cmp_a(ll x,ll y){return a[x]<a[y];}
#define min mmin
#define max mmax
#define abs aabs
namespace io {
	const ll SIZE = (1 << 21) + 1;
	char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c, qu[55]; ll f, qr;
	// getchar
	#define gc() (iS == iT ? (iT = (iS = ibuf) + fread (ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS ++)) : *iS ++)
	// prll the remaining part
	inline void flush () {
		fwrite (obuf, 1, oS - obuf, stdout);
		oS = obuf;
	}
	// putchar
	inline void putc (char x) {
		*oS ++ = x;
		if (oS == oT) flush ();
	}
	// input a signed lleger
	inline void read (signed &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}

	inline void read (long long &x) {
		for (f = 1, c = gc(); c < '0' || c > '9'; c = gc()) if (c == '-') f = -1;
		for (x = 0; c <= '9' && c >= '0'; c = gc()) x = x * 10 + (c & 15); x *= f;
	}
	inline void read (char &x) {
		while((x=gc())=='\n' || x==' '||x=='\r');
	}
	inline void read(char *x){
		while((*x=gc())=='\n' || *x==' '||*x=='\r');
		while(!(*x=='\n'||*x==' '||*x=='\r'))*(++x)=gc();
	}
	template<typename A,typename ...B>
	inline void read(A &x,B &...y){
		read(x);read(y...);
	}
	// prll a signed lleger
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
pii operator +(pii a,pii b){
	return make_pair(max(a.x,b.x-a.y),a.y+b.y);
}
ll willdel[300005];
struct smt{
	ll ls,rs;
	smt *l,*r;
	pii sum;	
	smt(ll la,ll ra){
		ls=la;rs=ra;
		if(ls==rs){
			sum.x=ls;
			sum.y=0;
			l=r=0;
		
		}
		else{
			ll mid=(la+ra)>>1;
			l=new smt(la,mid);
			r=new smt(mid+1,ra);
			sum=l->sum+r->sum;
		}	
	}
	void update(ll x,ll y){
		if(ls==rs){sum.y=y;return;}
		if(x<=l->rs)l->update(x,y);
		else r->update(x,y);
		sum=l->sum+r->sum;
	}
	pii query(ll R){
		if(rs<=R)return sum;
		if(R>l->rs)return l->sum+r->query(R);
		return l->query(R);
	}
};
smt *rt;
ll toll(pii a){return a.x+a.y;}
int main(){
#ifdef cnyali_lk
	freopen("K.in","r",stdin);
	freopen("K.out","w",stdout);
#endif
	ll q,x,y;
	char c;
	rt=new smt(1,1e6);
	read(q);
	for(ll i=1;i<=q;++i){
		read(c,x);
		if(c=='+'){willdel[i]=x;read(y);rt->update(x,y);}
		else if(c=='-')rt->update(willdel[x],0);
		else write(toll(rt->query(x))-x,'\n');
	}
	return 0;
}
