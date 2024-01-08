static bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    if (a.first == b.first)
    {
        return a.second.first < b.second.first;
    }

    return a.first < b.first;
}
int findIndex(vector<pair<int, pair<int, int>>> &mp, int s, int target)
{
    int e = mp.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = mp.size();
    while (s <= e)
    {
        if (mp[mid].first >= target)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }

        mid = s + (e - s) / 2;
    }
    return ans;
}
int recSol(vector<pair<int, pair<int, int>>> &mp, int index)
{
    if (index == mp.size())
    {
        return 0;
    }

    // include
    int i = findIndex(mp, index + 1, mp[index].second.first);
    int include = mp[index].second.second + recSol(mp, i);

    int exclude = recSol(mp, index + 1);
    return max(include, exclude);
}
int memoSol(vector<pair<int, pair<int, int>>> &mp, int index, vector<int> &dp)
{
    if (index == mp.size())
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }

    // include
    int i = findIndex(mp, index + 1, mp[index].second.first);
    int include = mp[index].second.second + memoSol(mp, i, dp);

    int exclude = memoSol(mp, index + 1, dp);
    return dp[index] = max(include, exclude);
}

int tabular(vector<pair<int, pair<int, int>>> &mp)
{
    int n = mp.size();
    vector<int> dp(n + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        // include
        int i = findIndex(mp, index + 1, mp[index].second.first);
        int include = mp[index].second.second + memoSol(mp, i, dp);

        int exclude = memoSol(mp, index + 1, dp);
        dp[index] = max(include, exclude);
    }

    return dp[0];
}
int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    vector<pair<int, pair<int, int>>> mp;
    int n = startTime.size();
    for (int i = 0; i < n; i++)
    {
        mp.push_back({startTime[i], {endTime[i], profit[i]}});
    }

    sort(mp.begin(), mp.end(), cmp);

    // return recSol(mp,0);
    // vector<int> dp(n,-1);
    // return memoSol(mp,0,dp);

    return tabular(mp);
}