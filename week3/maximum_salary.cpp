#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using namespace std;
string v_to_string(vector<string> a){
    std::stringstream str;
  for (size_t i = 0; i < a.size(); i++) {
    str << a[i];
  }
  string input;
  str >> input;
  return input;
}
string largest_number(vector<string> a) {
  //write your code here
  string input = v_to_string(a);
  vector<int> numbers;

  //convert each char to int and push to vector numbers
  for(int i =0; i<input.size(); i++){
    int a = input[i] - 48;
    numbers.push_back(a);
  }

  //Sort numbers in a descending order
  sort(numbers.begin(), numbers.end(), greater<int>());

  std::stringstream nums;
  for(int i=0; i<numbers.size(); i++){
    nums << numbers[i];
  }
  string output;
  nums >> output;

  return output;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
