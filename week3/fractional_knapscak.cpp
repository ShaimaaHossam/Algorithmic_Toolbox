#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using std::vector;
using namespace std;
int get_max(vector<double> margin){
    int maxPos =0;
    for(int i=0; i<margin.size(); i++){
        if(margin[i] > margin[maxPos])
            maxPos = i;
    }
    return maxPos;
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<double> margin;

  //calculate value-to-weights
  for(int i=0; i<weights.size(); i++){
    margin.push_back((double) values[i]/weights[i]);
  }


  //get optimal solution
  int current_weight=0;
  int cap = capacity;
  while(cap >=0 ){
    int maxPos = get_max(margin);

    if(current_weight == capacity)
        break;

    if(current_weight == 0 && weights[maxPos] > capacity){
        current_weight = capacity;
        value += ((double) capacity/weights[maxPos]) * values[maxPos];
    }
    else{
        if(weights.size()==1){
            current_weight = weights[maxPos];
            value = values[maxPos];
            break;
        }
        if(current_weight + weights[maxPos] <= capacity){
            current_weight += weights[maxPos];
            value += values[maxPos];
        }
        else{
            int difference = capacity - current_weight;
            value += ((double) difference/weights[maxPos])*values[maxPos];
            current_weight = capacity;
        }
    }


    margin[maxPos] = -1;
  }



  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
