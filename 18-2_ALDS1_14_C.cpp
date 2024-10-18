#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main() {
    int H, W;
    cin >> H >> W;
    vector<string> target(H);
    for (int i = 0; i < H; ++i)
    {
        cin >> target[i];
    }
    int R, C;
    cin >> R >> C;
    vector<string> query(R);
    for (int i = 0; i < R; ++i)
    {
        cin >> query[i];
    }

    for (int i = 0; i <= H - R; ++i)
    {
        for (int j = 0; j <= W - C; ++j)
        {
            bool match = true;
            for (int k = 0; k < R; ++k)
            {
                if (target[i + k].compare(j, C, query[k]) != 0)
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << i << " " << j << endl;
            }
        }
    }
}