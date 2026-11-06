class Solution(object):
    def countServers(self, n, logs, x, queries):
        """
        :type n: int
        :type logs: List[List[int]]
        :type x: int
        :type queries: List[int]
        :rtype: List[int]
        """
        q_len = len(queries)
        ans = [0] * q_len
        sorted_queries = sorted([(queries[i], i) for i in range(q_len)])
        logs.sort(key=lambda log: log[1])
        
        server_count = [0] * (n + 1)
        active_servers = 0
        left = 0
        right = 0
        m = len(logs)
        
        for q_time, original_idx in sorted_queries:
            window_start = q_time - x
            window_end = q_time
            while right < m and logs[right][1] <= window_end:
                server_id = logs[right][0]
                if server_count[server_id] == 0:
                    active_servers += 1
                server_count[server_id] += 1
                right += 1
            while left < m and logs[left][1] < window_start:
                server_id = logs[left][0]
                server_count[server_id] -= 1
                if server_count[server_id] == 0:
                    active_servers -= 1
                left += 1
            ans[original_idx] = n - active_servers
            
        return ans