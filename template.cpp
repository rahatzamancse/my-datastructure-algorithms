#include <bits/stdc++.h>

// DEBUG
void __print(int x) {std::cerr << x;}
void __print(long x) {std::cerr << x;}
void __print(long long x) {std::cerr << x;}
void __print(unsigned x) {std::cerr << x;}
void __print(unsigned long x) {std::cerr << x;}
void __print(unsigned long long x) {std::cerr << x;}
void __print(float x) {std::cerr << x;}
void __print(double x) {std::cerr << x;}
void __print(long double x) {std::cerr << x;}
void __print(char x) {std::cerr << '\'' << x << '\'';}
void __print(const char *x) {std::cerr << '\"' << x << '\"';}
void __print(const std::string &x) {std::cerr << '\"' << x << '\"';}
void __print(bool x) {std::cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const std::pair<T, V> &x) {std::cerr << '{'; __print(x.first); std::cerr << ','; __print(x.second); std::cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; std::cerr << "Size:" << x.size() << ' ' << '{'; for (auto &i: x) std::cerr << (f++ ? "," : ""), __print(i); std::cerr << "}";}
template <typename T>
void __print(const std::queue<T> &x) { if(x.empty()) std::cerr << "Empty"; else { std::cerr << "Front:"; __print(x.front()); } }
template <typename T>
void __print(const std::stack<T> &x) { if(x.empty()) std::cerr << "Empty"; else { std::cerr << "Top:"; __print(x.top()); } }
template <typename T>
void __print(const std::set<T> &x) { int f = 0; std::cerr << "Size:" << x.size() << ' ' << '{'; for (auto i = x.begin(); i != x.end(); ++i) std::cerr << (f++ ? "," : ""), __print(*i); std::cerr << "}"; }
void _print() {std::cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) std::cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define DEBUG(x...) std::cerr << "[" << #x << "] = ["; _print(x)
#else
#define DEBUG(x...)
#endif

// Iterations
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define ALL(x) x.begin(), x.end()
#define ALL_R(x) x.rbegin(), x.rend()

// Containers
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define PRESENT_ALGO(c,x) (find(all(c),x) != (c).end())

// Functions
#define EVEN(x) ((x)%2 == 0)
#define ODD(x) ((x) & 1)
#define FEQ(a,b) (fabs((a)-(b)) < (1.0E-8))
#define COUNT_1(n) __builtin_popcountll(n)
#define ABSOLUTE(a) (((a)<0)?(-1*(a)):(a))
#define MAX(x,y) (((x)>(y))?(x):(y))
#define MIN(x,y) (((x)<(y))?(x):(y))
#define MID(s,e) (((s)+((e)-(s))/2))
#define TEST_CASES(t) int t;std::cin >> t; while(t--)
#define uint_to_string(i, s) std::bitset<(s)>((i)).to_string()
#define string_to_uint(str, s) std::bitset<(s)>((str)).to_uint()

// Constants
const auto INF = 1<<29;
const auto MOD =  1000000007;
const auto PI =  3.141592653589793238;

// Types
using ull = unsigned long long int;
using ll = long long int;

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  constexpr char endl = '\n';
  cout.precision(10);
  cout << fixed;


  return 0;
}
