#include <iostream>
using namespace std;
int get_change(int m) {
    int i, j, k;
    i = (int) m/10;
    j = (int)((m%10)/5);
    k = m - i*10 - j * 5;
  return i+j+k;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
