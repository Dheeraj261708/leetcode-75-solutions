class Solution(object):
    def targetIndices(self, nums, target):
        smaller = 0
        equal = 0

        for num in nums:
            if num < target:
                smaller += 1
            elif num == target:
                equal += 1

        return list(range(smaller, smaller + equal))