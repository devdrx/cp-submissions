

    //#define SUPPORT_128
    //#define LONG_DOUBLE
    //#define FORCE_FLOAT
    //#define ANGRY_FAST
    //#define ANGRY_LONG
    //#define ANGRY_LONG128
    //#define BETTER_128
    //#define CUSTOM_RAND
    //#define MT_RAND
    //#define LOCAL
    //#define _GLIBCXX_DEBUG 1
    //#pragma optimize( "", on )
    //#pragma GCC optimize("Ofast")
    //#define FAST_MEM
    //#include <sys/mman.h>
    #ifdef ANGRY_FAST
    #pragma optimize( "", on )
    #pragma GCC optimize("O3,fast-math,unroll-loops")
    //#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
    //#pragma GCC target("bmi2,sse4.2,popcnt,lzcnt")
    #ifdef SUPPORT_128
    #pragma GCC target("bmi2,popcnt,lzcnt")
    #endif
    //#pragma GCC ivdep
    #pragma GCC optimize "Ofast"
    //#define FAST_MEM
    #define NDEBUG
    #endif
    #include <bitset>
    #include <iostream>
    #include <string>
    #include <complex>
    #include <climits>
    #include <chrono>
    #include <cassert>
    #include <list>
    #include <iomanip>
    #include <iterator>
    #include <map>
    #include <unordered_set>
    #include <vector>
    #include <set>
    #include <algorithm>
    #include <cmath>
    #include <cassert>
    #include <list>
    #include <unordered_map>
    #include <fstream>
    #include <memory>
    #include <random>
    #include <sstream>
    #include <deque>
    #include <queue>
    //#include <variant>
    //#include <any>
    //#include <signal.h>
     
    using namespace std;
     
    #define PPIIPII pair<PII,PII>
    #define MPIIPIPII map<PII,PIPII>
    #define PILD pair<int,ld>
    #define VPILD vector<PILD>
    #define VVPILD vector<VPILD>
    //#define map unordered_map
    #define cont continue;
    #ifdef SUPPORT_128
    //#define int128 int128_t
    #define int128 __int128
    #else
    #define int128 long long
    #endif
    #ifndef ANGRY_FAST
    #define int long long
    #endif
    #ifdef ANGRY_LONG
    #define int long long
    #define float ld
    #endif
    #ifdef ANGRY_LONG128
    #undef int
    #define int int128
    #endif
    #define endl '\n'
    #define endlf '\n'<<flush
    #define pb push_back
    #define pf push_front
    #define ins insert
    #define x first
    #define sz size
    #define era erase
    #define pp pop_back
    #define ppf pop_front
    #define y second
    #define fori(i, n) for(int i=0;i<(n);++i)
    #define fori1(i, n) for(int i=1;i<(n);++i)
    #define forir(i, n) for(int i=(n-1);i>=(0);--i)
    #define foris(i, n) for(int i=0;i<(n.sz());++i)
    #define foris1(i, n) for(int i=1;i<(n.sz());++i)
    #define foriab(i, a, b) for(int i=(a);i<(b);++i)
    #define forirab(i, a, b) for(int i=(b)-1;i>=(a);--i)
    #define VI vector<int>
    #define DI deque<int>
    #define VVI vector<VI>
    #define VVVI vector<VVI>
    #define PLDLD pair<ld,ld>
    #define VPLDLD vector<PLDLD>
    #define MSLD map<string, ld>
    #define SI set<int>
    #define SPII set<PII>
    #define VSPII vector<SPII>
    #define VPSI vector<PSI>
    #define PSI pair<string,int>
    #define SP set<PAR>
    #define MII map<int, int>
    #define MSI map<string, int>
    #define PII pair<int, int>
    #define PAR PII
    #define PIVI pair<int,VI>
    #define VPIVI vector<PIVI>
    #define VP vector<PAR>
    #define PPIII pair<PII,int>
    #define VPPIII vector<PPIII>
    #define byte unsigned char
    //#define byte bool
    #define VB vector<byte>
    #define VVB vector<VB>
    #define VVP vector<VP>
    #define MPIIVVI map<PII,VVI>
    #define MPIIPII map<PII,PII>
    #define VB vector<byte>
    #define VVSI vector<VSI>
    #define VSB vector<SB>
    #define VVS vector<VS>
    #define INF 2000000000000000000LL
    #define BIG 1000000LL
    #define EPS 1e-8
    #define MIMII map<int, MII>
    #define VMII vector<MII>
    #define MIVI map<int,VI>
    #define MISI map<int,SI>
    #define MIPII map<int,PII>
    #define PILD pair<int,ld>
    #define MPPIIII map<PPIII,int>
    #define MIVPII map<int,VPII>
    #define UMIPII unordered_map<int,PII>
    #define wall(x) ((x).begin()), ((x).end())
    #ifdef LONG_DOUBLE
    #define ld long double
    #else
    #define ld double
    #endif
    #ifdef FORCE_FLOAT
    #undef ld
    #define ld float
    #endif
    #define MOD 1000000007LL
    //#define MOD 1000000009LL
    #undef MOD
    #define MOD 998244353LL
    #define VPII vector<PII>
    #define DPII deque<PII>
    #define VVPII vector<VPII>
    #define VMIPII vector<MIPII>
    #define VUMIPII vector<UMIPII>
    #define MPIII map<PII, int>
    #define VDB vector<DB>
    #define VPIPII vector<PIPII>
    #define PIPII pair<int, PII>
    #define ava(X) cout<<(X)<<endl;exit(0);
    #define VS vector<string>
    #define VSI vector<SI>
    #define MPIPIII map<PIPII, int>
    #define VC vector<char>
    #define MBB map<byte, byte>
    #define SB set<byte>
    #define ret return
    #define VPIB vector<PIB>
    #define PIB pair<int,byte>
    #define VVPIPII vector<VPIPII>
    #define PLDI pair<ld,int>
    #define VPLDI vector<PLDI>
    #define SPLDI set<PLDI>
    #define DI deque<int>
    #define DB deque<byte>
    #define DDI deque<DI>
    #define DDB deque<DB>
    #define MPIISI map<PII,SI>
    #define VPN vector<Node*>
    #define sstream stringstream
    #define what(X) cerr<<(#X)<<" = "<<X<<endlf;
     
    #define abs LCC_ABS
    #ifdef MT_RAND
    #define rand MT_RAND_RAND
    random_device MT_RAND_RD;
    mt19937 MT_RAND_GEN(MT_RAND_RD());
    uniform_int_distribution<int> MT_RAND_DIST(0, LONG_MAX);
    int rand(){
    	ret MT_RAND_DIST(MT_RAND_GEN);
    }
    #endif
     
    #ifdef FAST_MEM
    const signed MAX_MEM=100000000;
    signed mpos=0;
    char mem[MAX_MEM];
    inline void* operator new(size_t n){
    	mpos+=n;
    	assert(mpos<=MAX_MEM);
    	ret(void*)(mem+mpos-n);
    }
    void operator delete(void*)noexcept{}
    void operator delete(void*,size_t)noexcept{}
    #endif
     
    template<class A> bool is_sorted(const A& arr){
    	fori1(i,arr.sz()){
    		if(arr[i-1]>arr[i]){
    			ret 0;
    		}
    	}
    	ret 1;
    }
    template<class I> I emgcd(I a,I b,I&x,I&y){
    	pair<I,I> Va({1,0});
    	pair<I,I> Vb({0,1});
    	while(b){
    		Va.x-=a/b*Vb.x;
    		Va.y-=a/b*Vb.y;
    		a%=b;
    		swap(a,b);
    		swap(Va,Vb);
    	}
    	x=Va.x;
    	y=Va.y;
    	ret a;
    }
    template<class I> I mgcd(I a,I b){
    	while(b){
    		a%=b;
    		swap(a,b);
    	}
    	ret a;
    }
    template<class I> I egcd(I a,I b,I&x,I&y){
    	bool as,bs;
    	as=bs=0;
    	if(a<0){
    		a=-a;
    		as=1;
    	}
    	if(b<0){
    		b=-b;
    		bs=1;
    	}
    	I ans=emgcd(a,b,x,y);
    	if(as){
    		x=-x;
    	}
    	if(bs){
    		y=-y;
    	}
    	ret ans;
    }
    template<class I> I gcd(I a,I b){
    	if(a<0){
    		a=-a;
    	}
    	if(b<0){
    		b=-b;
    	}
    	ret mgcd(a,b);
    }
    template<class I> I lcm(I a,I b){
    	if(a<0){
    		a=-a;
    	}
    	if(b<0){
    		b=-b;
    	}
    	ret a/gcd(a,b)*b;
    }
    template<class I> I lcm(I a,I b,I c){
    	ret lcm(lcm(a,b),c);
    }
    template<class I> I gcd(I a,I b,I c){
    	ret gcd(gcd(a,b),c);
    }
    template<class A, class B> bool rmax(A& a, const B& b){
    	A t=b;
    	if(a<t){
    		a=move(t);
    		ret 1;
    	}
    	ret 0;
    }
    template<class A, class B> bool rmin(A& a, const B& b){
    	A t=b;
    	if(a>t){
    		a=move(t);
    		ret 1;
    	}
    	ret 0;
    }
    template<class A, class B> bool rset(A& a, const B& b){
    	A t=b;
    	if(a!=t){
    		a=move(t);
    		ret 1;
    	}
    	ret 0;
    }
    #ifdef SUPPORT_128
    istream& operator>>(istream& i, int128& v){
    	long long x;
    	i>>x;
    	v=x;
    	ret i;
    }
    #ifdef BETTER_128
    ostream& operator<<(ostream& i, int128 v){
    	if(!v){
    		ret i<<'0';
    	}
    	if(v<0){
    		i<<'-';
    		v=-v;
    	}
    	string s;
    	while(v){
    		s.pb(48+v%10);
    		v/=10;
    	}
    	while(s.sz()){
    		i<<s.back();
    		s.pp();
    	}
    	ret i;
    #else
    ostream& operator<<(ostream& i, const int128& v){
    	long long x=v;
    	ret i<<x;
    #endif
    }
    #endif
    template<class T, class U> istream& operator>>(istream& i, pair<T, U>& v){
    	ret i>>v.x>>v.y;
    }
    template<class T, class U> ostream& operator<<(ostream& i, const pair<T, U>& v){
    	ret i<<v.x<<' '<<v.y<<endl;
    }
    template<class T> istream& operator>>(istream& i, deque<T>& v){
    	for(auto& x:v){
    		i>>x;
    	}
    	ret i;
    }
    template<class T> istream& operator>>(istream& i, vector<T>& v){
    	for(auto& x:v){
    		i>>x;
    	}
    	ret i;
    }
    template<class T> ostream& operator<<(ostream& i, const set<T>& v){
    	for(auto& x:v){
    		i<<x<<' ';
    	}
    	ret i<<endl;
    }
    template<class T> ostream& operator<<(ostream& i, const vector<T>& v){
    	for(const auto& x:v){
    		i<<x<<' ';
    	}
    	ret i<<endl;
    }
    template<class T> ostream& operator<<(ostream& i, const deque<T>& v){
    	for(auto& x:v){
    		i<<x<<' ';
    	}
    	ret i<<endl;
    }
    /*
    template<class T> vector<T>& operator+=(vector<T>& a, const vector<T>& b){
    	for(const auto& x:b){
    		a.pb(x);
    	}
    	ret a;
    }
    */
    template<class T> set<T> merge(const set<T>& a, const set<T>& b){
    	set<T> ans;
    	for(auto x:a){
    		ans.ins(x);
    	}
    	for(auto x:b){
    		ans.ins(x);
    	}
    	ret ans;
    }
    template<class T> set<T> intersect(const set<T>& a, const set<T>& b){
    	set<T> ans;
    	if(a.sz()<b.sz()){
    		for(auto x:a){
    			if(b.count(x)){
    				ans.ins(x);
    			}
    		}
    	}else{
    		for(auto x:b){
    			if(a.count(x)){
    				ans.ins(x);
    			}
    		}
    	}
    	ret ans;
    }
    int isqrt(int _){
    	assert(_>=0);
    	int l=0;
    	int r=1LL<<30;
    	while(r-l>1){
    		int m=l+r>>1;
    		if(m*m<=_){
    			l=m;
    		}else{
    			r=m;
    		}
    	}
    	ret l;
    }
    PII operator-(PII a, PII b){
    	ret {a.x-b.x, a.y-b.y};
    }
    PII operator+(PII a, PII b){
    	ret {a.x+b.x, a.y+b.y};
    }
    int fpowm(int i, int k){
    	if(k){
    		int t=fpowm((i*i)%MOD, k>>1);
    		if(k&1){
    			t*=i;
    			t%=MOD;
    		}
    		ret t;
    	}
    	ret 1;
    }
    int invm(int k){
    	ret fpowm(k, MOD-2);
    }
    int fpow(int a,int b){
    	int _=1;
    	while(b){
    		if(b%2==1){
    			_*=a;
    		}
    		a*=a;
    		b/=2;
    	}
    	ret _;
    }
    template<class T> T abs(T x){
    	if(x<0){
    		ret -x;
    	}
    	ret x;
    }
    int delup(int a, int b){
    	int c=a/b;
    	if(a%b){
    		++c;
    	}
    	ret c;
    }
    int fpowmod(int a,int k,int MOO){
    	a%=MOO;
    	int _=1;
    	while(k){
    		if(k%2){
    			_*=a;
    			_%=MOO;
    		}
    		k/=2;
    		a*=a;
    		a%=MOO;
    	}
    	ret _;
    }
    int invmod(int k, int MOO){
    	ret fpowmod(k, MOO-2, MOO);
    }
    #define YES {cout<<"YES"<<endl;ret;}
    #define NO {cout<<"NO"<<endl;ret;}
    #define NE1 {cout<<"-1"<<endl;ret;}
    #define ZERO {cout<<"0"<<endl;ret;}
    #define ANS(x) {cout<<(x)<<endl;ret;}
    #define YESNO(x) if(x){YES;}NO;
    #define MYESNO(x) if(x){MYES;}else{MNO;}
    #define First ANS("First")
    #define Second ANS("Second")
    #define FirstSecond(x) if(x){First}else{Second}
     
    PII limit_den(int m, int n, int l){
    	int a=n, b=m%n, p=1, q=0, r=m/n, s=1, v=1;
    	while(0<b&&q+a/b*s<=l){
    		int na, nb, np, nq, nr, ns, nv;
    		na=b;
    		nb=a%b;
    		np=r;
    		nq=s;
    		nr=p+a/b*r;
    		ns=q+a/b*s;
    		nv=-v;
    		a=na;
    		b=nb;
    		p=np;
    		q=nq;
    		r=nr;
    		s=ns;
    		v=nv;
    	}
    	int t=p+(l-q)/s*r, u=q+(l-q)/s*s;
    	if(2*b*u<=n){
    		ret {r, s};
    	}
    	ret {t, u};
    }
    struct R{
    	int a, b;
    	R(int x, int y){
    		assert(y);
    		a=x;
    		b=y;
    		norm();
    	}
    	R(int x, int y, bool){
    		a=x;
    		b=y;
    	}
    	R(int x){
    		a=x;
    		b=1;
    	}
    	R(){
    		a=0;
    		b=1;
    	}
    	R& operator*=(const R& s){
    		a*=s.a;
    		b*=s.b;
    		ret norm();
    	}
    	R& operator/=(const R& s){
    		assert(s.a);
    		a*=s.b;
    		b*=s.a;
    		ret norm();
    	}
    	R& operator+=(const R& s){
    		int x=b;
    		a*=s.b;
    		b*=s.b;
    		a+=s.a*x;
    		ret norm();
    	}
    	R& operator-=(const R& s){
    		int x=b;
    		a*=s.b;
    		b*=s.b;
    		a-=s.a*x;
    		ret norm();
    	}
    	R& norm(){
    		int d=gcd(a, b);
    		a/=d;
    		b/=d;
    		if(b<0){
    			a*=-1;
    			b*=-1;
    		}
    		ret *this;
    	}
    	int intval() const{
    		ret a/b;
    	}
    	ld ldval() const{
    		ret (ld)a/(ld)b;
    	}
    	R& limit_den(int l){
    		PII aa=::limit_den(a, b, l);
    		a=aa.x;
    		b=aa.y;
    		ret *this;
    	}
    };
    R operator+(R a, const R& b){
    	a+=b;
    	ret a;
    }
    R operator-(R a, const R& b){
    	a-=b;
    	ret a;
    }
    R operator*(R a, const R& b){
    	a*=b;
    	ret a;
    }
    R operator/(R a, const R& b){
    	a/=b;
    	ret a;
    }
    bool operator==(const R&a,const R&b){
    	ret a.a==b.a&&a.b==b.b;
    }
    bool operator!=(const R&a,const R&b){
    	ret a.a!=b.a||a.b!=b.b;
    }
    bool operator<(const R&a,const R&b){
    	ret a.a*b.b<b.a*a.b;
    }
    bool operator>(const R&a,const R&b){
    	ret b<a;
    }
    bool operator<=(const R&a,const R&b){
    	ret !(b<a);
    }
    bool operator>=(const R&a,const R&b){
    	ret b<=a;
    }
    ostream& operator<<(ostream& o, const R& r){
    	//ret o<<r.a<<'/'<<r.b<<endl;
    	ret o<<(((ld)(r.a))/((ld)(r.b)));
    }
    istream& operator>>(istream& i, R& r){
    	int x;
    	i>>x;
    	r.a=x;
    	r.b=1;
    	ret i;
    }
     
    #define has holds_alternative
    struct suset{
    	set<R> sr;
    	bool inv=0;
    	suset(){
    	}
    	suset(const set<R>& srr){
    		sr=srr;
    	}
    	suset(const set<R>& srr,bool invv){
    		sr=srr;
    		inv=invv;
    	}
    	suset(R r){
    		sr.ins(r);
    	}
    	suset(R r,bool invv){
    		sr.ins(r);
    		inv=invv;
    	}
    	void ins(R r){
    		if(inv){
    			sr.era(r);
    		}else{
    			sr.ins(r);
    		}
    	}
    	void era(R r){
    		if(inv){
    			sr.ins(r);
    		}else{
    			sr.era(r);
    		}
    	}
    };
    suset merge(const suset& a,const suset& b){
    	if(a.inv||b.inv){
    		if(a.inv&&b.inv){
    			return suset(intersect(a.sr,b.sr),1);
    		}
    		if(a.inv){
    			suset ans=a;
    			for(auto x:b.sr){
    				ans.sr.era(x);
    			}
    			ret ans;
    		}else{
    			suset ans=b;
    			for(auto x:a.sr){
    				ans.sr.era(x);
    			}
    			ret ans;
    		}
    	}
    	ret suset(merge(a.sr,b.sr));
    }
    suset intersect(suset a,suset b){
    	a.inv^=1;
    	b.inv^=1;
    	suset ans=merge(a,b);
    	ans.inv^=1;
    	ret ans;
    }
    suset invert(suset a){
    	a.inv^=1;
    	ret a;
    }
    PII intersect(PII a,PII b){
    	rmin(a.y,b.y);
    	rmax(a.x,b.x);
    	ret a;
    }
    bool eq(ld a,ld b){
    	ret abs(a-b)<EPS;
    }
    bool lo(ld a,ld b){
    	ret a<b&&!eq(a,b);
    }
    bool leq(ld a,ld b){
    	ret a<=b||eq(a,b);
    }
    bool gr(ld a,ld b){
    	ret a>b&&!eq(a,b);
    }
    bool geq(ld a,ld b){
    	ret a>=b||eq(a,b);
    }
    void solve();
    void precalc();
    int intval(ld a){
    	int i=a;
    	int d=abs(i-a);
    	if(rmin(d,abs(i+1-a))){
    		++i;
    	}
    	if(rmin(d,abs(i-1-a))){
    		--i;
    	}
    	ret i;
    }
    int pokm(int a,int p){
    	int pk=p-1;
    	VI ps;
    	{
    		int m=pk;
    		for(int d=2;d*d<=m;++d){
    			if(m%d==0){
    				ps.pb(d);
    				while(m%d==0){
    					m/=d;
    				}
    			}
    		}
    		if(m-1){
    			ps.pb(m);
    		}
    	}
    	for(auto x:ps){
    		while(pk%x==0&&fpowmod(a,pk/x,p)==1){
    			pk/=x;
    		}
    	}
    	ret pk;
    }
    /*
    int phi(int n){
    	int k=__builtin_ctzll(n);
    	n>>=k;
    	int _=1<<k;
    	_-=_/2;
    	for(int d=3;d*d<=n;d+=2){
    		int pk=1;
    		while(n%d==0){
    			n/=d;
    			pk*=d;
    		}
    		_*=pk-pk/d;
    	}
    	if(n-1){
    		_*=n-1;
    	}
    	ret _;
    }
    */
    template<class T> T sq(const T& x){
    	ret x*x;
    }
     
    int mod(int a,int b){
    	//ret (a%b+b)%b;
    	a%=b;
    	if(a<0){
    		a+=b;
    	}
    	ret a;
    }
    int modm(int a){
    	ret mod(a,MOD);
    }
    int sum(const VI& v){
    	int _=0;
    	for(int x:v){
    		_+=x;
    	}
    	ret _;
    }
    int mex(const VI& v){
    	SI s;
    	fori(i,v.sz()+1){
    		s.ins(i);
    	}
    	for(auto x:v){
    		s.era(x);
    	}
    	ret *s.begin();
    }
     
    #define VLD vector<ld>
    #define VVLD vector<VLD>
    #define MIVI map<int,VI>
    #define VMIVI vector<MIVI>
    #define VMISI vector<MISI>
    template<class T>void reverse(pair<T,T>&a){
    	swap(a.x,a.y);
    }
    template<class T>void swap(pair<T,T>&a){
    	swap(a.x,a.y);
    }
    template<class T>void reverse(vector<T>&a){
    	reverse(wall(a));
    }
    void reverse(string&a){
    	reverse(wall(a));
    }
    template<class T,class F>deque<T> sorted(deque<T>a,const F&f){
    	sort(wall(a),f);
    	ret a;
    }
    template<class T,class F>vector<T> sorted(vector<T>a,const F&f){
    	sort(wall(a),f);
    	ret a;
    }
    template<class T,class F>void sort(deque<T>&a,const F&f){
    	sort(wall(a),f);
    }
    template<class T,class F>void sort(vector<T>&a,const F&f){
    	sort(wall(a),f);
    }
    template<class T>void sort(vector<T>&a){
    	sort(wall(a));
    }
    void sort(PII& a){
    	if(a.y<a.x){
    		swap(a);
    	}
    }
    PII sorted(PII a){
    	if(a.y<a.x){
    		swap(a);
    	}
    	ret a;
    }
    /*
    int n;
    VVI mul(const VVI&a,const VVI&b){
    	int x=a.sz();
    	int y=b.sz();
    	int z=b.back().sz();
    	VVI v(x,VI(z));
    	fori(i,x){
    		fori(j,z){
    			fori(k,y){
    				v[i][j]+=a[i][k]*b[k][j];
    			}
    			v[i][j]%=n;
    		}
    	}
    	ret v;
    }
     
    VVI id(int n){
    	VVI _(n,VI(n));
    	fori(i,n){
    		_[i][i]=1;
    	}
    	ret _;
    }
     
    VVI fpow(VVI a,int k){
    	VVI _=id(a.sz());
    	while(k){
    		if(k%2){
    			_=mul(_,a);
    		}
    		k/=2;
    		a=mul(a,a);
    	}
    	ret _;
    }
    */
     
    //#define MYES [](){YES}();
    //#define MNO [](){NO}();
    #define MYES {cout<<"YES\n";}
    #define MNO {cout<<"NO\n";}
     
    bool is_prime(int n) {
    	if(n<2){
    		ret 0;
    	}
    	if(n==2){
    		ret 1;
    	}
    	if(n%2==0){
    		ret 0;
    	}
    	int d=n-1;
    	while(d%2==0)d/=2;
    	int bases[]={2,3,5,7,11,13,17,19};
    	for(int a:bases) {
    		if(a==n){
    			ret 1;
    		}
    		int t=d;
    		int y=fpowmod(a,t,n);
    		while(t-n+1&&y-1&&y-n+1) {
    			y=y*y%n;
    			t<<=1;
    		}
    		if(y!=n-1&&t%2==0){
    			ret 0;
    		}
    	}
    	ret 1;
    }
     
     
    template<class T>int sgn(const T&a){
    	ret a!=0?a>0?1:-1:0;
    }
    void prec(int x = 20){
    	cout<<setprecision(x)<<fixed;
    }
     
    VI razl(int A,int p){
    	VI v;
    	while(A){
    		v.pb(A%p);
    		A/=p;
    	}
    	ret v;
    }
    int slozh(VI v,int p){
    	int A=0;
    	while(v.sz()){
    		A*=p;
    		A+=v.back();
    		v.pp();
    	}
    	ret A;
    }
    int gcd(PII x){
    	ret gcd(x.x,x.y);
    }
     
    VVI mul(const VVI& a,const VVI& b){
    	int f=a.sz();
    	int t=b.back().sz();
    	int mid=b.sz();
    	VVI m(f,VI(t));
    	fori(i,f){
    		fori(j,t){
    			fori(k,mid){
    				m[i][j]+=a[i][k]*b[k][j];
    			}
    		}
    	}
    	ret m;
    }
    template<class T>vector<T>& operator+=(vector<T>&a,const vector<T>& b){
    	if(a.sz()<b.sz()){
    		a.resize(b.sz());
    	}
    	foris(i,b){
    		a[i]+=b[i];
    	}
    	ret a;
    }
    template<class T>vector<T> operator+(vector<T> a,const vector<T>&b){
    	ret a+=b;
    }
    template<class T>vector<T> operator+(const vector<T>&a){
    	ret a;
    }
    template<class T>vector<T>& operator-=(vector<T>&a,const vector<T>& b){
    	if(a.sz()<b.sz()){
    		a.resize(b.sz());
    	}
    	foris(i,b){
    		a[i]-=b[i];
    	}
    	ret a;
    }
    template<class T>vector<T> operator-(vector<T> a,const vector<T>&b){
    	ret a-=b;
    }
    template<class T>vector<T> operator-(const vector<T>&a){
    	ret a-a-a;
    }
    template<class T>vector<T>& operator*=(vector<T>&a,const T&b){
    	for(auto&x:a){
    		x*=b;
    	}
    	ret a;
    }
    template<class T>vector<T> operator*(vector<T>a,const T&b){
    	a*=b;
    	ret a;
    }
    template<class T>vector<T> operator*(const T&b,vector<T>a){
    	a*=b;
    	ret a;
    }
    template<class T>vector<T> operator*(const vector<T>&a,const vector<T>&b){
    	if(b.empty()){
    		ret b;
    	}
    	if(a.empty()){
    		ret a;
    	}
    	vector<T> ans((a.sz()-1)+(b.sz()-1)+1);
    	foris(i,a){
    		foris(j,b){
    			ans[i+j]+=a[i]*b[j];
    		}
    	}
    	while(ans.sz()&&ans.back()==0){
    		ans.pp();
    	}
    	ret ans;
    }
    VVI fpow(VVI a,int m){
    	int n=a.sz();
    	VVI one(n,VI(n));
    	fori(i,n){
    		one[i][i]=1;
    	}
    	while(m){
    		if(m%2){
    			one=mul(one,a);
    		}
    		a=mul(a,a);
    		m/=2;
    	}
    	ret one;
    }
    VVI trans(const VVI& v){
    	int n=v.sz();
    	int m=v.back().sz();
    	VVI vv(m,VI(n));
    	fori(i,n){
    		fori(j,m){
    			vv[j][i]=v[i][j];
    		}
    	}
    	ret vv;
    }
    template<class T> T accumulate(const set<T>& v){
    	T z=0;
    	for(const auto& x:v){
    		z+=x;
    	}
    	ret z;
    }
    template<class T> T accumulate(const vector<T>& v){
    	T z=0;
    	for(const auto& x:v){
    		z+=x;
    	}
    	ret z;
    }
     
    namespace std {
    	template<typename T1, typename T2>
    		struct hash<std::pair<T1, T2>> {
    			std::size_t operator()(std::pair<T1, T2> const &p) const {
    				ret p.x*239+p.y;
    			}
    		};
    }
     
    int abs2(PII p){
    	ret sq(p.x)+sq(p.y);
    }
    int abs2(PII a,PII b){
    	ret abs2(a-b);
    }
     
    string& rtrim(string& v,int d=0){
    	while(v.sz()&&v.back()==d){
    		v.pp();
    	}
    	ret v;
    }
    VI& rtrim(VI& v,int d=0){
    	while(v.sz()&&v.back()==d){
    		v.pp();
    	}
    	ret v;
    }
     
    ///SOLUTION///
     
    //int BG=100001LL;
    //vector<signed> ps;
    //vector<bool> is_p;
    //void precalc(){
    	/*
    	ret;
    	is_p.resize(BG,1);
    	//ps.reserve(664579);
    	ps.reserve(9593);
    	is_p[0]=0;
    	is_p[1]=0;
    	for(signed i=4;i<BG;i+=2){
    		is_p[i]=0;
    	}
    	ps.pb(2);
    	for(signed i=3;i<BG;i+=2){
    		if(is_p[i]){
    			ps.pb(i);
    			for(signed j=2*i;j<BG;j+=i){
    				is_p[j]=0;
    			}
    		}
    	}
    	//ANS(ps.sz());
    	*/
    //}
     
    /*
    int get(const VI& v,int x){
    	int _=0;
    	for(int i=v.sz()-1;i+1;--i){
    		_*=x;
    		_+=v[i];
    		_=modm(_);
    	}
    	ret _;
    }
    struct interpol{
    	VI v;
    	VI r;
    	interpol(){
    		r.pb(1);
    	}
    	void addp(int x,int y){
    		int cur=get(v,x);
    		int dvg=get(r,x);
    		int k=modm(y-cur)*invm(dvg);
    		v+=r*modm(k);
    		foris(i,v){
    			v[i]=modm(v[i]);
    		}
    		while(v.sz()&&!v.back()){
    			v.pp();
    		}
    		r=r*VI{-x,1};
    		foris(i,r){
    			r[i]=modm(r[i]);
    		}
    	}
    };
    VCLD getp(){
    	string s;
    	getline(cin,s);
    	int n=1;
    	int dg=0;
    	s.pb('+');
    	VI v;
    	bool md=0;
    	bool stn=0;
    	bool std=0;
    	bool sgn=0;
    	if(s[0]=='-'){
    		n=0;
    	}
    	for(auto x:s){
    		if(x=='-'||x=='+'){
    			if(v.sz()<=dg){
    				v.resize(dg+1);
    			}
    			if(sgn){
    				v[dg]=-n;
    			}else{
    				v[dg]=n;
    			}
    			md=0;
    			dg=0;
    			stn=std=0;
    			n=1;
    			if(x=='-'){
    				sgn=1;
    			}else{
    				sgn=0;
    			}
    		}
    		if(x=='x'){
    			dg=1;
    		}
    		if(x=='^'){
    			md=1;
    		}
    		if(47<x&&x<58){
    			if((md?std:stn)==0){
    				(md?std:stn)=1;
    				(md?dg:n)=0;
    			}
    			(md?dg:n)*=10;
    			(md?dg:n)+=x-48;
    		}
    	}
    	while(v.sz()&&!v.back()){
    		v.pp();
    	}
    	VCLD cf(v.sz());
    	foris(i,v){
    		cf[i]=v[i];
    	}
    	ret cf;
    }
    void printp(const VCLD&v){
    	VI cf(v.sz());
    	foris(i,v){
    		cf[i]=round(v[i].real());
    		//cf[i]=v[i];
    	}
    	string s;
    	while(cf.sz()&&!cf.back()){
    		cf.pp();
    	}
    	if(cf.empty()){
    		cout<<0<<endl;
    		ret;
    	}
    	if(cf.back()==-1){
    		cout<<'-';
    		if(cf.sz()==1){
    			cout<<1;
    		}
    	}else{
    		if(cf.back()!=1||cf.sz()==1){
    			cout<<cf.back();
    		}
    	}
    	if(cf.sz()!=1){
    		cout<<'x';
    	}
    	if(cf.sz()>2){
    		cout<<'^'<<cf.sz()-1;
    	}
    	cf.pp();
    	while(cf.sz()){
    		if(cf.back()==0){
    			cf.pp();
    			cont;
    		}
    		cout<<' ';
    		if(cf.back()<0){
    			cf.back()*=-1;
    			cout<<'-';
    		}else{
    			cout<<'+';
    		}
    		cout<<' ';
    		if(cf.back()!=1||cf.sz()==1){
    			cout<<cf.back();
    		}
    		if(cf.sz()!=1){
    			cout<<'x';
    		}
    		if(cf.sz()>2){
    			cout<<'^'<<cf.sz()-1;
    		}
    		cf.pp();
    	}
    	cout<<endl;
    }
    */
    //#define cld complex<ld>
    #define cld int
    #define VCLD vector<cld>
    const ld PI=acos(-1.0);
    /*
    void fft(VCLD&a,bool invert=0){
    	signed n=a.sz();
    	if(n==1){
    		ret;
    	}
    	VCLD a0(n/2),a1(n/2);
    	for(signed i=0;2*i<n;i++){
    		a0[i]=a[2*i];
    		a1[i]=a[2*i+1];
    	}
    	fft(a0,invert);
    	fft(a1,invert);
    	ld ang=2*PI/n*(invert?-1:1);
    	cld w(1),wn(cos(ang),sin(ang));
    	for(signed i=0;2*i<n;i++){
    		a[i]=a0[i]+w*a1[i];
    		a[i+n/2]=a0[i]-w*a1[i];
    		if(invert){
    			a[i]/=2;
    			a[i+n/2]/=2;
    		}
    		w*=wn;
    	}
    }
    */
    constexpr signed logLimit=19;
    constexpr signed limit=1<<logLimit;
    vector<signed> rev(limit);
    void calcRev(){
    	fori(i,limit){
    		fori(k,logLimit){
    			if(i&(1<<k)){
    				rev[i]^=1<<(logLimit-k-1);
    			}
    		}
    	}
    }
    VCLD z(limit);
    void calcZ(){
    	int z1=363395222;
    	//int z1=565042129;
    	z[0]=1;
    	fori1(i,limit){
    		//z[i]=cld(cos(i*2*PI/limit),sin(i*2*PI/limit));
    		z[i]=z[i-1]*z1;
    		z[i]%=MOD;
    	}
    	assert(z[limit/2]!=1);
    	assert((z[limit-1]*z1)%MOD==1);
    }
    void precalc(){
    	calcRev();
    	calcZ();
    }
    void fft(VCLD&a,bool inv=0){
    	fori(i,limit){
    		if(i<rev[i]){
    			swap(a[i],a[rev[i]]);
    		}
    	}
    	if(inv){
    		reverse(z.begin()+1,z.end());
    	}
    	for(signed k=0,span=1,step=limit/2;k<logLimit;k++,span*=2,step/=2){
    		for(signed i=0;i<limit;i+=2*span){
    			fori(j,span){
    				signed u=i+j;
    				signed v=i+j+span;
    				cld x=a[u]+a[v]*z[j*step];
    				a[v]=a[u]+a[v]*z[j*step+limit/2];
    				a[u] = x;
    				a[u]%=MOD;
    				a[v]%=MOD;
    			}
    		}
    	}
    	if(inv){
    		reverse(z.begin()+1,z.end());
    		int q=fpowm(499122177,logLimit);
    		fori(i,limit){
    			//a[i]/=limit;
    			a[i]*=q;
    			a[i]%=MOD;
    		}
    	}
    }
    VI mul(const VI&aa,const VI&bb){
    	if(aa.sz()==0||bb.sz()==0){
    		ret {};
    	}
    	signed n=aa.sz()+bb.sz()-1;
    	signed k=1;
    	while(n){
    		++k;
    		n/=2;
    	}
    	n=1<<k;
    	n=limit;//
    	VCLD a(n);
    	VCLD b(n);
    	foris(i,aa){
    		a[i]=aa[i];
    	}
    	foris(i,bb){
    		b[i]=bb[i];
    	}
    	fft(a);
    	fft(b);
    	VCLD v(n);
    	fori(i,n){
    		v[i]=a[i]*b[i];
    		v[i]%=MOD;
    	}
    	fft(v,1);
    	rtrim(v);
    	ret v;
    	VI vv(n);
    	fori(i,n){
    		//vv[i]=round(v[i].real());
    		vv[i]=v[i];
    	}
    	ret rtrim(vv);
    }
    string mul(string a,string b){
    	reverse(a);
    	reverse(b);
    	bool s=0;
    	if(b.back()=='-'){
    		b.pp();
    		s^=1;
    	}
    	if(a.back()=='-'){
    		a.pp();
    		s^=1;
    	}
    	while(a.sz()%4){
    		a.pb(48);
    	}
    	while(b.sz()%4){
    		b.pb(48);
    	}
    	VI aa(a.sz()/4);
    	VI bb(b.sz()/4);
    	foris(i,aa){
    		aa[i]=(a[4*i]-48)+(a[4*i+1]-48)*10+(a[4*i+2]-48)*100+(a[4*i+3]-48)*1000;
    	}
    	foris(i,bb){
    		bb[i]=(b[4*i]-48)+(b[4*i+1]-48)*10+(b[4*i+2]-48)*100+(b[4*i+3]-48)*1000;
    	}
    	VI vv=mul(aa,bb);
    	foris(i,vv){
    		if(vv[i]>10000){
    			if(i==vv.sz()-1){
    				vv.pb(vv[i]/10000);
    			}else{
    				vv[i+1]+=vv[i]/10000;
    			}
    			vv[i]%=10000;
    		}
    	}
    	string ss;
    	for(auto x:vv){
    		ss.pb(x/1%10+48);
    		ss.pb(x/10%10+48);
    		ss.pb(x/100%10+48);
    		ss.pb(x/1000+48);
    	}
    	rtrim(ss,48);
    	if(ss.empty()){
    		ret "0";
    	}
    	if(s){
    		ss.pb('-');
    	}
    	reverse(ss);
    	ret ss;
    }
    void printx05(int x){
    	cout<<x/2;
    	if(x%2){
    		cout<<".5";
    	}
    }
    VI mul2(const VI&aa,const VI&bb,const VI&cc,const VI&dd){
    	if(aa.sz()==0||bb.sz()==0){
    		ret mul(cc,dd);
    	}
    	if(cc.sz()==0||dd.sz()==0){
    		ret mul(aa,bb);
    	}
    	signed n=max(aa.sz()+bb.sz(),cc.sz()+dd.sz())-1;
    	signed k=1;
    	while(n){
    		++k;
    		n/=2;
    	}
    	n=1<<k;
    	n=limit;//
    	VCLD a(n);
    	VCLD b(n);
    	VCLD c(n);
    	VCLD d(n);
    	foris(i,aa){
    		a[i]=aa[i];
    	}
    	foris(i,bb){
    		b[i]=bb[i];
    	}
    	foris(i,cc){
    		c[i]=cc[i];
    	}
    	foris(i,dd){
    		d[i]=dd[i];
    	}
    	fft(a);
    	fft(b);
    	fft(c);
    	fft(d);
    	VCLD v(n);
    	fori(i,n){
    		v[i]=a[i]*b[i]+c[i]*d[i];
    		v[i]%=MOD;
    	}
    	fft(v,1);
    	rtrim(v);
    	ret v;
    	VI vv(n);
    	fori(i,n){
    		//vv[i]=round(v[i].real());
    		vv[i]=v[i];
    	}
    	ret rtrim(vv);
    }
    PII f(PII& p){
    	ret {p.x*101-p.y,p.x+101*p.y};
    }
    int how(PII a,PII b){
    	ret sgn(a.x*b.y-a.y*b.x);
    }
    PII& operator-=(PII&a,PII b){
    	a.x-=b.x;
    	a.y-=b.y;
    	ret a;
    }
    PII& operator/=(PII&a,int b){
    	a.x/=b;
    	a.y/=b;
    	ret a;
    }
    PII operator/(PII a,int b){
    	ret a/=b;
    }
    bool sonapr(PII a,PII b){
    	if(!a.x&&!a.y){
    		ret 1;
    	}
    	if(!b.x&&!b.y){
    		ret 1;
    	}
    	a/=gcd(a);
    	b/=gcd(b);
    	ret a==b;
    }
    bool protivo(PII a,PII b){
    	ret sonapr(a,b-b-b);
    }
    bool kollin(PII a,PII b){
    	ret protivo(a,b)||sonapr(a,b);
    }
    bool inseg(PII x,PII a,PII b){
    	a-=x;
    	b-=x;
    	ret protivo(a,b);
    }
    int getmod(){
    	unsigned seed1=chrono::system_clock::now().time_since_epoch().count();
    	std::mt19937 generator(seed1);
    	std::uniform_int_distribution<int> distribution(100000000, 1000000000);
    	ret distribution(generator);
    }
    int mm;
    void solve(){
    	int n,q;
    	string s;
    	cin>>n>>q>>s;
    	VI ha(n+1);
    	fori1(i,n+1){
    		ha[i]=ha[i-1]*37+s[i-1]-'a';
    		ha[i]%=mm;
    	}
    	VI har(n+1);
    	fori1(i,n+1){
    		har[i]=har[i-1]*37+s[n-i]-'a';
    		har[i]%=mm;
    	}
    	VI d(n-1);
    	VI d2(n-1);
    	s.pb(0);
    	fori(i,n-1){
    		d[i]=(s[i]!=s[i+1]);
    		d2[i]=(s[i]!=s[i+2]);
    	}
    	VI p(n);
    	VI p2(n);
    	fori1(i,n){
    		p[i]=p[i-1]+d[i-1];
    		p2[i]=p2[i-1]+d2[i-1];
    	}
    	while(q--){
    		int l,r;
    		cin>>l>>r;
    		--l;
    		--r;
    		if(l==r||p[l]==p[r]){
    			cout<<0<<endl;
    			cont;
    		}
    		int t=r-l;
    		int _=0;
    		bool abab=(t==1)||(p2[l]==p2[r-1]);
    		if(abab){
    			int tt=t;
    			if(tt%2){
    				--tt;
    			}
    			tt/=2;
    			_+=(tt*(tt+1));
    		}else{
    			_+=t*(t+1)/2-1;
    		}
    		int phi=fpowmod(37,t+1,mm);
    		bool pald=(((ha[r+1]-ha[l]*phi)-(har[n-l]-har[n-1-r]*phi))%mm==0);
    		if(!pald){
    			_+=(r-l+1);
    		}
    		cout<<_<<endl;
    	}
    }
     
    signed main(){
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	precalc();
    	mm=228228239;
    	signed t=1;
    	cin>>t;
    	//srand(time(0));
    	//srand(239);
    	while(t--){
    		solve();
    	}
    	ret 0;
    }   