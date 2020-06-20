/// Name: Prime Numbers and Prime Factorization
/// Description: Sieve, Get Prime Factorization with Sieve
/// Detail: Sieve takes O(logn), Find all divisors takes O(n)
/// Guarantee: void sieve(
const ull MAXN = 10000000;
ull spf[MAXN];
void sieve(const ull &n=MAXN) {
  for(ull i = 1; i<n; i+=2) spf[i] = i;
  for(ull i = 2; i<n; i+=2) spf[i] = 2;
  for(ull i = 3; i*i < n; i++)
    if(spf[i] == i)
      for(ull j=i*i; j<n; j+=i)
        if(spf[j]==j)
          spf[j] = i;
}
vector<ull> getFactors(ull x) {
  vector<ull> ret;
  while(x!=1) {
    ret.emplace_back(spf[x]);
    x /= spf[x];
  }
  return ret;
}
vector<ull> getPrimes(const ull n=MAXN) {
  vector<ull> ret = {2};
  for(ull i = 3; i<n; i+=2)
    if(spf[i] == i)
      ret.emplace_back(i);
  return ret;
}