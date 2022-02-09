#include <iostream>
using namespace std;
int get_fibonacci_last_digit_fast(int n) {
    int a[n+1];
    a[0] = 0;
    a[1] = 1;
    for(int i =2; i<=n; i++){
        a[i] = (a[i-1] + a[i-2])%10;
    }
    return a[n];
}

int main() {
    int n;
    cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    cout << c << '\n';

}
