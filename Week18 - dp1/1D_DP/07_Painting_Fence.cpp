long long MOD = 1000000007;
long long add(long long a, long long b)
{
    return (a % MOD + b % MOD) % MOD;
}

long long multi(long long a, long long b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}
long long recSol(int n, int k)
{
    if (n == 1)
        return k;

    if (n == 2)
        return add(k, multi(k, k - 1));

    // last two same
    long long lastTwoSame = multi(recSol(n - 2, k), k - 1);
    // last two different
    long long lastTwoDiff = multi(recSol(n - 1, k), k - 1);
    long long ans = add(lastTwoDiff, lastTwoSame);

    return ans;
}
long long topDownApproch(int n, int k, vector<long long> &dp)
{
    if (n == 1)
        return k;

    if (n == 2)
        return add(k, multi(k, k - 1));

    if (dp[n] != -1)
    {
        return dp[n];
    }
    // last two same
    long long lastTwoSame = multi(recSol(n - 2, k), k - 1);
    // last two different
    long long lastTwoDiff = multi(recSol(n - 1, k), k - 1);
    dp[n] = add(lastTwoDiff, lastTwoSame);
    return dp[n];
}
long long bottomUpApproch(int n, int k, vector<long long> &dp)
{
    dp[1] = k;
    dp[2] = add(k, multi(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        // last two same
        long long lastTwoSame = multi(dp[i - 2], k - 1);
        // last two different
        long long lastTwoDiff = multi(dp[i - 1], k - 1);
        dp[i] = add(lastTwoSame, lastTwoDiff);
    }

    return dp[n];
}

long long spaceOptmize(int n, int k)
{
    long long prev2 = k;
    long long prev1 = add(k, multi(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        long long curr = multi(add(prev1, prev2), k - 1);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
long long countWays(int n, int k)
{
    // code here
    // return recSol(n,k);
    vector<long long> dp(n + 1, -1);
    // return topDownApproch(n,k,dp);
    // return bottomUpApproch(n,k,dp);
    return spaceOptmize(n, k);
}