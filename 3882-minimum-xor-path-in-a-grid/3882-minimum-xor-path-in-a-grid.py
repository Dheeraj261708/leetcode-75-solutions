class Solution(object):
    def minCost(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m = len(grid)
        n = len(grid[0])
        dp = [[set() for _ in range(n)] for _ in range(m)]
        dp[0][0].add(grid[0][0])
        
        for i in range(m):
            for j in range(n):
                for val in dp[i][j]:
                    if j + 1 < n:
                        dp[i][j + 1].add(val ^ grid[i][j + 1])
                    if i + 1 < m:
                        dp[i + 1][j].add(val ^ grid[i + 1][j])
        return min(dp[m - 1][n - 1])