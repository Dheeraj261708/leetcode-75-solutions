class Solution(object):
    def uniquePaths(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        MOD = 10**9 + 7
        m = len(grid)
        n = len(grid[0])
        def get_next(r, c, dr, dc):
            curr_r, curr_r_dir = r + dr, dc
            pass
        go = [[None, None] for _ in range(m * n)] 
        def simulate(r, c, is_right):
            curr_r, curr_c = r, c
            while True:
                if is_right:
                    curr_c += 1
                else:
                    curr_r += 1
                if not (0 <= curr_r < m and 0 <= curr_c < n):
                    return None
                if grid[curr_r][curr_c] == 0:
                    return (curr_r, curr_c)
                else:

                    is_right = not is_right

        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1
        
        for i in range(m):
            for j in range(n):
                if dp[i][j] == 0:
                    try_right = None
                    try_down = None
                else:
                    nxt_right = simulate(i, j, True)
                    if nxt_right:
                        nr, nc = nxt_right
                        dp[nr][nc] = (dp[nr][nc] + dp[i][j]) % MOD
                    nxt_down = simulate(i, j, False)
                    if nxt_down:
                        nr, nc = nxt_down
                        dp[nr][nc] = (dp[nr][nc] + dp[i][j]) % MOD
                        
        return dp[m - 1][n - 1]