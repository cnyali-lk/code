/*
Author: CNYALI_LK
LANG: C++
PROG: TopXorerEasy.cpp
Mail: cnyalilk@vip.qq.com
*/

#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
template<class Ta,class Tb>int chkmin(Ta &a,Tb b){return a>b?a=b,1:0;}
template<class Ta,class Tb>int chkmax(Ta &a,Tb b){return a<b?a=b,1:0;}

class TopXorerEasy {
    public:
    int maximalRating(int A, int B, int C) {
		if(A>B)A^=B^=A^=B;
		if(B>C)B^=C^=B^=C;
		if(A>B)A^=B^=A^=B;
		int t=1;
		while(t<=C)t<<=1;
		--t;
		int y=0;
		y|=t&C;
		t^=C;
		if(t<=B)return y|=t;
		for(int i=30;~i;--i)if((t&(1<<i))&&((1<<i)<=B)){
			y|=1<<i;	
			t^=1<<i;
			B-=1<<i;
		}
		if(t<=A)return y|=t;
		for(int i=30;~i;--i)if((t&(1<<i))&&((1<<i)<=A)){
			y|=1<<i;	
			t^=1<<i;
			A-=1<<i;
		}
		return y;
    }
};

// CUT begin
ifstream data("TopXorerEasy.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int A, int B, int C, int __expected) {
    time_t startClock = clock();
    TopXorerEasy *instance = new TopXorerEasy();
    int __result = instance->maximalRating(A, B, C);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        int A;
        from_stream(A);
        int B;
        from_stream(B);
        int C;
        from_stream(C);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(A, B, C, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1519877133;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "TopXorerEasy (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
