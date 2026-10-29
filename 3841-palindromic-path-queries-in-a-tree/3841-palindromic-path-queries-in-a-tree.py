
class Solution(object):
    def palindromePath(self, n, edges, s, queries):
        from collections import defaultdict
        adj = [[] for _ in range(n)]
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)
        parent = [0] * n
        depth = [0] * n
        tin = [0] * n
        order = []
        stack = [0]

        while stack:
            u = stack.pop()
            tin[u] = len(order)
            order.append(u)

            for v in adj[u]:
                if v != parent[u] or u == 0 and v != 0:
                    if v == parent[u] and u != 0:
                        continue
                    parent[v] = u
                    depth[v] = depth[u] + 1
                    stack.append(v)
        size = [1] * n
        for u in reversed(order):
            if u != 0:
                size[parent[u]] += size[u]

        tout = [tin[u] + size[u] - 1 for u in range(n)]
        LOG = n.bit_length()
        up = [parent[:]]

        for k in range(1, LOG):
            prev = up[-1]
            up.append([prev[prev[u]] for u in range(n)])

        def lca(u, v):
            if depth[u] < depth[v]:
                u, v = v, u

            diff = depth[u] - depth[v]
            for k in range(LOG):
                if diff & (1 << k):
                    u = up[k][u]

            if u == v:
                return u

            for k in range(LOG - 1, -1, -1):
                if up[k][u] != up[k][v]:
                    u = up[k][u]
                    v = up[k][v]

            return parent[u]
        chars = list(s)
        pref = [0] * n

        for u in order:
            bit = 1 << (ord(chars[u]) - ord('a'))
            if u == 0:
                pref[u] = bit
            else:
                pref[u] = pref[parent[u]] ^ bit
        bit_tree = [0] * (n + 2)

        def add(i, value):
            while i <= n + 1:
                bit_tree[i] ^= value
                i += i & -i

        def range_xor(left, right, value):
            add(left + 1, value)
            add(right + 2, value)

        def point_query(i):
            result = 0
            i += 1
            while i > 0:
                result ^= bit_tree[i]
                i -= i & -i
            return result

        answer = []

        for q in queries:
            parts = q.split()
            op = parts[0]

            if op == "update":
                u = int(parts[1])
                c = parts[2]

                old_bit = 1 << (ord(chars[u]) - ord('a'))
                new_bit = 1 << (ord(c) - ord('a'))

                if old_bit != new_bit:
                    delta = old_bit ^ new_bit
                    range_xor(tin[u], tout[u], delta)
                    chars[u] = c

            else:
                u = int(parts[1])
                v = int(parts[2])

                pu = pref[u] ^ point_query(tin[u])
                pv = pref[v] ^ point_query(tin[v])

                ancestor = lca(u, v)
                ancestor_bit = 1 << (
                    ord(chars[ancestor]) - ord('a')
                )
                mask = pu ^ pv ^ ancestor_bit
                answer.append((mask & (mask - 1)) == 0)

        return answer
