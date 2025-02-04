#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int coins[] = {25, 10, 5, 1};
    int count = 0;

    for (int i = 0; i < 4; ++i) {
        count += n / coins[i];
        n %= coins[i];
    }

    cout << count << endl;
    return 0;
}