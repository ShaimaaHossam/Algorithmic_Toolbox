#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;
using std::max;
using namespace std;
long long MaxPairwiseProduct(const vector<long long>& numbers)
{
    int n = numbers.size();
    int max1= -1;
    int max2 = -1;
    for(int i=0; i<n; i++){
        if(max1==-1 || numbers[i] > numbers[max1])
            max1 = i;
    }
    for(int j=0; j<n; j++){
        if((numbers[j] > numbers[max2] || max2==-1)&& (j != max1))
            max2 = j;

    }
    long long product = (long long)(numbers[max1]*numbers[max2]);
    return product;
}
int main()
{
    int n;
    cin >> n;
    vector<long long> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }
    long long result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}
