#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using namespace std;
int get_max(vector<int> arr){
    int index_of_max = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] > arr[index_of_max])
            index_of_max = i;
    }
    return index_of_max;
}
long long max_dot_product(vector<int> a, vector<int> b, size_t n) {
  // write your code here
  long long sop = 0;
  for(size_t i =0; i<n ; i++){
    int index_1 = get_max(a);
    int index_2 = get_max(b);
    long long val = ((long long)a[index_1])*b[index_2];
    sop+=val;
    a.erase(a.begin()+index_1);
    b.erase(b.begin()+index_2);
  }

  return sop;

}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b, n) << std::endl;
}
