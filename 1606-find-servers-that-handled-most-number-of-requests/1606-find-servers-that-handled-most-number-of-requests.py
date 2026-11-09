import heapq
import bisect

class Solution(object):
    def busiestServers(self, k, arrival, load):
        """
        :type k: int
        :type arrival: List[int]
        :type load: List[int]
        :rtype: List[int]
        """
        busy_servers = []
        requests_count = [0] * k
        import sortedcontainers 
        available = sortedcontainers.SortedList(range(k))
        
        for i, (arr, ld) in enumerate(zip(arrival, load)):
            while busy_servers and busy_servers[0][0] <= arr:
                _, free_server = heapq.heappop(busy_servers)
                available.add(free_server)
            if not available:
                continue
            target = i % k
            idx = available.bisect_left(target)
            if idx == len(available):
                idx = 0
            
            server_id = available[idx]
            available.remove(server_id)
            requests_count[server_id] += 1
            heapq.heappush(busy_servers, (arr + ld, server_id))
            
        max_requests = max(requests_count)
        return [i for i, count in enumerate(requests_count) if count == max_requests]