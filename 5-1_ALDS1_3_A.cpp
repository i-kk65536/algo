#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    stack<int> calc_result;
    string literal;
    while(cin >> literal)
    {
        if (literal == "+")
        {
            int nums[2];
            for (int i = 0; i < 2; i++)
            {
                nums[i] = calc_result.top();
                calc_result.pop();
            }
            int res = nums[1] + nums[0];
            calc_result.push(res);
        }
        else if (literal == "-")
        {
            int nums[2];
            for (int i = 0; i < 2; i++)
            {
                nums[i] = calc_result.top();
                calc_result.pop();
            }
            int res = nums[1] - nums[0];
            calc_result.push(res);
        }
        else if (literal == "*")
        {
            int nums[2];
            for (int i = 0; i < 2; i++)
            {
                nums[i] = calc_result.top();
                calc_result.pop();
            }
            int res = nums[1] * nums[0];
            calc_result.push(res);
        }
        else
        {
            calc_result.push(stoi(literal));
        }
    }
    cout << calc_result.top() << endl;
}