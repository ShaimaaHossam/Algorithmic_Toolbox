#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;
using namespace std;
int compute_min_refills(int dist, int tank, vector<int> & stops)
{
  int fullTank = tank;
  int currPosition = 0;
  int currStop = 0;
  int refills = 0;
  while(currPosition <= dist && currStop < stops.size()){
       if(stops[currStop] - currPosition > fullTank){
        return -1;
       }
       if(stops[currStop] - currPosition > tank){
         refills++;
         tank = fullTank;
       }
         int difference = stops[currStop] - currPosition;
         tank = tank - difference;
         currPosition = stops[currStop];
         currStop ++;
  }

  if(dist - currPosition > fullTank)
    return -1;
  if(dist - currPosition <= tank)
    return refills;
  else{
    refills ++;
    return refills;
  }

}

int main()
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
