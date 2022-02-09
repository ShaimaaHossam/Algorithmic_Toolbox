#include <iostream>

long long lcm_fast(int a, int b) {
  long long temp, q, r, gcd, m, n;
      m = a;
      n = b;
      if(b < a){
        temp = b;
        b = a;
        a = temp;
      }

      while(b!=0){
        q = (int) a/b;
        r = a - q*b;

        a = b;
        b = r;

        if(b == 0)
            gcd = a;
      }
      long long lcm = (long long) (m*n)/gcd;
      return lcm;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
