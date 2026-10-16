class Solution(object):
    def sumCounts(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(nums)

        size = 4 * n
        total = [0] * size
        square = [0] * size
        lazy = [0] * size

        def apply(node, l, r, val):
            length = r - l + 1
            total[node] = (total[node] + val * length) % MOD
            square[node] = (
                square[node]
                + 2 * val * total[node]
                - val * val * length
            ) % MOD
            lazy[node] += val

        def push(node, l, r):
            if lazy[node] == 0 or l == r:
                return

            mid = (l + r) // 2
            val = lazy[node]

            apply(node * 2, l, mid, val)
            apply(node * 2 + 1, mid + 1, r, val)

            lazy[node] = 0

        def update(node, l, r, ql, qr):
            if ql <= l and r <= qr:
                val = 1
                length = r - l + 1
                old_sum = total[node]

                square[node] = (
                    square[node] + 2 * val * old_sum
                    + val * val * length
                ) % MOD
                total[node] = (old_sum + val * length) % MOD
                lazy[node] += val
                return

            push(node, l, r)
            mid = (l + r) // 2

            if ql <= mid:
                update(node * 2, l, mid, ql, qr)

            if qr > mid:
                update(node * 2 + 1, mid + 1, r, ql, qr)

            total[node] = (
                total[node * 2] + total[node * 2 + 1]
            ) % MOD

            square[node] = (
                square[node * 2] + square[node * 2 + 1]
            ) % MOD

        last = {}
        ans = 0

        for i, x in enumerate(nums):
            prev = last.get(x, -1)

            update(1, 0, n - 1, prev + 1, i)

            ans = (ans + square[1]) % MOD
            last[x] = i

        return ans