class Solution(object):
    def sortPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        k = -1
        for i, val in enumerate(nums):
            if val != i:
                if k == -1:
                    k = val
                else:
                    k &= val
        return k if k != -1 else 0
        