class Solution(object):
    def sortableIntegers(self, nums):
        n = len(nums)
        ans = 0

        for k in range(1, n + 1):
            if n % k != 0:
                continue

            prev = float('-inf')
            valid = True

            for start in range(0, n, k):
                block = nums[start:start + k]

                # Find a rotation that makes this block sorted.
                drops = 0
                drop_idx = -1

                for i in range(k):
                    if block[i] > block[(i + 1) % k]:
                        drops += 1
                        drop_idx = i

                if drops > 1:
                    valid = False
                    break

                if drops == 1:
                    block = block[drop_idx + 1:] + block[:drop_idx + 1]

                if block[0] < prev:
                    valid = False
                    break

                prev = block[-1]

            if valid:
                ans += k

        return ans