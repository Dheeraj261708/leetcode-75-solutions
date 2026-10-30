import heapq

class Solution(object):
    def shortestPath(self, n, edges, labels, k):
        """
        :type n: int
        :type edges: List[List[int]]
        :type labels: str
        :type k: int
        :rtype: int
        """
        adj = [[] for _ in range(n)]
        for u, v, w in edges:
            adj[u].append((v, w))
        dist = [[float('inf')] * (k + 1) for _ in range(n)]
        pq = []
        initial_cnt = 1
        dist[0][initial_cnt] = 0
        heapq.heappush(pq, (0, 0, initial_cnt))
        
        while pq:
            d, u, cnt = heapq.heappop(pq)
            
            if d > dist[u][cnt]:
                continue
            if u == n - 1:
                return d   
            for v, w in adj[u]:
                if labels[u] == labels[v]:
                    next_cnt = cnt + 1
                else:
                    next_cnt = 1
                    
                if next_cnt <= k:
                    if d + w < dist[v][next_cnt]:
                        dist[v][next_cnt] = d + w
                        heapq.heappush(pq, (d + w, v, next_cnt))
        ans = min(dist[n - 1])
        return ans if ans != float('inf') else -1