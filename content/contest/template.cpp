#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;//lli
typedef pair<int, int> pii;
typedef vector<int> vi;// long long
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//{return uniform_int_distribution<lli>(l,r)(rng);}
#define dbg(...) { cerr<<"[ "; ary(#__VA_ARGS__, __VA_ARGS__);}
template <typename Arg1>
void ary(const string name, Arg1&& arg1){ cerr << name << " : " << arg1 << " ] " << endl;}
template <typename Arg1, typename... Args>
void ary(const string names, Arg1&& arg1, Args&&... args){
  const string name = names.substr(0,names.find(','));cerr<<name<<" : "<<arg1<<" | ";
  ary(names.substr(1+(int)name.size()), args...);
}
template <typename Arg1,typename Arg2>
ostream& operator << (ostream& out, const map<Arg1,Arg2> &a) {
	out<<"[";for(const auto &x:a)out<<x<<",";return out<<"]";
}
int main() {
  cin.sync_with_stdio(0); cin.tie(0);cin.exceptions(cin.failbit);
}