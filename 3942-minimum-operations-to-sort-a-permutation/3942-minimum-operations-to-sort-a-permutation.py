
class Solution(object):
    def minOperations(self, nums):
        n = len(nums)
        j = nums[0]
        if all(nums[i] == (j + i) % n for i in range(n)):
            rotations = (n - j) % n
            return min(rotations, j + 2) if j != 0 else 0
        j = (n - 1 - nums[0]) % n
        if all(nums[i] == (nums[0] - i) % n for i in range(n)):
            return min(j + 1, n - j + 1)

        return -1
