#include <iostream>

int gcd_fast(int a, int b) {
    int temp, q, r;
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
        return a;
  }
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_fast(a, b) << std::endl;
  return 0;
}
