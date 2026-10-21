class Solution(object):
    def minOperations(self, s):
        if s == ''.join(sorted(s)):
            return 0

        n = len(s)

        if n == 2:
            return -1

        if s[0] == min(s) or s[-1] == max(s):
            return 1

        if s[0] == max(s) and s[-1] == min(s):
            if s.count(s[0]) == 1 and s.count(s[-1]) == 1:
                return 3

        return 2