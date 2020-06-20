/// Name: Divisors
/// Description: A class that helps to get divisors
/// Detail: Get divisors of a Number however you want
/// Guarantee: class Divisors {

/*
Loop through all divisors
while(!divs.end) {
  auto div = divs.next();
}

Check if the output divisors is from the second portion
ull last = -1;
while(true) {
  auto div = divs.next();
  if(div*div > i || last == div || divs.end) break;
  last = div;
}
*/
class Divisors {
  public:
  ull value, __i, __j;
  vector<ull> divs;
  bool __donetillsqrt, end;
  Divisors(const ull &value) : value(value), __i(1), __j(0), __donetillsqrt(false), end(false) { }

  void reset(const ull &val=0) {
    if(val) value = val;
    divs.clear();
    __i=1; __j=0;
    __donetillsqrt = false; end = false;
  }

  ull next() {
    if (!__donetillsqrt) {
      for(; __i*__i<=value;__i++)
        if(value%__i == 0) {
          divs.emplace_back(__i);
          __i++;
          return __i-1;
        }
      __donetillsqrt = true;
      __j = divs.size()-1;
      return next();
    }
    else {
      if (__j < 1) end = true;
      __j--;
      divs.emplace_back(value / divs[__j+1]);
      return *(divs.end()-1);
    }
  }

  ull operator[](const ull &ind) {
    while(!end && ind+1 > divs.size()) next();
    return divs[ind];
  }

  vector<ull> getAllDivisors() {
    while(!end) next();
    return divs;
  }
};