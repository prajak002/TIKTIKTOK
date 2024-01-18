#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v1, v2;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        v2.push_back(a);
    }
    unordered_map<int, int> m1, m2;
    for (auto i : v1)
        m1[i]++;
    for (auto i : v2)
        m2[i]++;
    vector<int> diff;
    for (auto i : m1)
    {
        if (m2.find(i.first) != m2.end())
        {
            if ((i.second + m2[i.first]) & 1)
            {
                cout << -1 << endl;
                return 0;
            }
            int t = (abs(i.second - m2[i.first])) / 2;
            while (t--)
            {
                diff.push_back(i.first);
            }
        }
        else
        {
            if ((i.second) & 1)
            {
                cout << -1 << endl;
                return 0;
            }
            int t = (i.second) / 2;
            while (t--)
            {
                diff.push_back(i.first);
            }
        }
    }
    for (auto i : m2)
    {
        if (m1.find(i.first) == m1.end())
        {
            if ((i.second) & 1)
            {
                cout << -1 << endl;
                return 0;
            }
            int t = (i.second) / 2;
            while (t--)
            {
                diff.push_back(i.first);
            }
        }
    }
    sort(diff.begin(), diff.end());
    for (auto i : diff)
    {
        cout << i << " ";
    }
    cout << endl;
    int diffsize = diff.size() / 2;
    int ans = 0;
    for (int i = 0; i < diffsize; i++)
    {
        ans += diff[i];
    }
    cout << ans;
    return 0;
