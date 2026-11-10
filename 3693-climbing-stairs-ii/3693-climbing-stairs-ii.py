class Solution(object):
    def climbStairs(self, n, costs):
        """
        :type n: int
        :type costs: List[int]
        :rtype: int
        """
        dp = [float('inf')] * (n + 1)
        dp[0] = 0   
        for j in range(1, n + 1):
            for i in range(max(0, j - 3), j):
                jump_cost = costs[j - 1] + (j - i) ** 2
                dp[j] = min(dp[j], dp[i] + jump_cost)
                
        return dp[n]