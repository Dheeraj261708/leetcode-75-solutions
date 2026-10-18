class Solution(object):
    def numOfWays(self, nums):
        MOD = 10**9 + 7
        n = len(nums)

        # Precompute combinations
        comb = [[0] * n for _ in range(n)]

        for i in range(n):
            comb[i][0] = 1
            for j in range(1, i + 1):
                if j == i:
                    comb[i][j] = 1
                else:
                    comb[i][j] = (
                        comb[i - 1][j - 1] + comb[i - 1][j]
                    ) % MOD

        def solve(arr):
            if len(arr) <= 2:
                return 1

            root = arr[0]
            left = [x for x in arr[1:] if x < root]
            right = [x for x in arr[1:] if x > root]

            left_ways = solve(left)
            right_ways = solve(right)

            ways = comb[len(arr) - 1][len(left)]
            ways = ways * left_ways % MOD
            ways = ways * right_ways % MOD

            return ways

        return (solve(nums) - 1) % MOD