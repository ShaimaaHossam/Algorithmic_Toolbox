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
  int nextStop = 0;
  int refills = 0;
  while(currPosition <= dist && nextStop < stops.size()){
       if(stops[nextStop] - currPosition > fullTank){
        return -1;
       }
       if(stops[nextStop] - currPosition > tank){
         refills++;
         tank = fullTank;
       }
         int difference = stops[nextStop] - currPosition;
         tank = tank - difference;
         currPosition = stops[nextStop];
         nextStop ++;
  }

  if(dist - currPosition > fullTank)
    return -1;
  if(dist - currPosition <= tank)
    return refills;
  else
    return ++refills;


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
