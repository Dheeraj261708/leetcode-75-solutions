class Solution(object):
    def minSwaps(self, nums):
        def digitSum(n):
            s = 0
            while n:
                s += n % 10
                n //= 10
            return s

        arr = sorted(nums, key=lambda x: (digitSum(x), x))
        pos = {v: i for i, v in enumerate(arr)}

        visited = [False] * len(nums)
        ans = 0

        for i in range(len(nums)):
            if visited[i] or pos[nums[i]] == i:
                continue

            j = i
            cycle = 0

            while not visited[j]:
                visited[j] = True
                j = pos[nums[j]]
                cycle += 1

            ans += cycle - 1

        return ans