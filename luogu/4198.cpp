/*
Author: CNYALI_LK
LANG: C++
PROG: 4198.cpp
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
struct frac{
	ll a,b;
	frac(ll x=0,ll y=1){a=x;b=y;}	
	bool operator ==(frac other){
		return a*other.b == other.a*b;
	}
	bool operator <(frac other){
		return a*other.b < other.a*b;
	}
	bool operator >(frac other){
		return a*other.b > other.a*b;
	}
	bool operator <=(frac other){
		return a*other.b <= other.a*b;
	}
	bool operator >=(frac other){
		return a*other.b >= other.a*b;
	}
};
struct smt{
	frac mx;		
	int len,ls,rs;
	smt *l,*r;
	int push_up(frac a){
		if(ls==rs){return a<mx;}	
		else return l->mx<=a?r->push_up(a):l->push_up(a)+len-l->len;
	}
	void pushup(){
		mx=max(l->mx,r->mx);
		len=l->len+r->push_up(l->mx);
	}
	smt(int la,int ra){
		ls=la;rs=ra;
		if(ls==rs){
			mx.b=la;
			len=1;
			l=r=0;
		}
		else{
			int mid=(ls+rs)>>1;
			l=new smt(ls,mid);
			r=new smt(mid+1,rs);
			pushup();
		}
	}
	void update(int x,int y){
		if(ls==rs){
			mx.a=y;
			return;
		}
		if(x<=l->rs)l->update(x,y);	
		else r->update(x,y);
		pushup();
	}
};
smt *r;
int a[100005];
int main(){
#ifdef cnyali_lk
	freopen("4198.in","r",stdin);
	freopen("4198.out","w",stdout);
#endif
	int n,m,x;
	read(n,m);
	r=new smt(1,n);
	for(;m;--m){
		read(x);
		read(a[x]);
		r->update(x,a[x]);
		if(a[1]==0)write(r->len-1,'\n');
		else write(r->len,'\n');
	}
	return 0;
}

