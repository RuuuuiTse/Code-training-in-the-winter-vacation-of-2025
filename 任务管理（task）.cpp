#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 5000;

vector<int> before[MAXN];
bool done[MAXN];

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        int Ci;
        cin >> Ci;
        before[i].resize(Ci);
        for (int j = 0; j < Ci; ++j)
        {
            cin >> before[i][j];
        }
    }

    set<int> ans;
    vector<int> stack;
    stack.push_back(1);
    while (!stack.empty())
    {
        int doing = stack.back();
        stack.pop_back();
        if (!done[doing])
        {
            done[doing] = true;
            ans.insert(doing);
            for (int i = before[doing].size() - 1; i >= 0; --i)
            {
                stack.push_back(before[doing][i]);
            }
        }
    }

    cout << ans.size();

    return 0;
}