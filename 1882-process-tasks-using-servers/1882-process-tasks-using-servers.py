import heapq

class Solution(object):
    def assignTasks(self, servers, tasks):
        """
        :type servers: List[int]
        :type tasks: List[int]
        :rtype: List[int]
        """
        n = len(servers)
        m = len(tasks)
        free_servers = [(servers[i], i) for i in range(n)]
        heapq.heapify(free_servers)
        busy_servers = []
        
        ans = [0] * m
        current_time = 0
        
        for j in range(m):
            current_time = max(current_time, j)
            
       
            if not free_servers and busy_servers[0][0] > current_time:
                current_time = busy_servers[0][0]
        
            while busy_servers and busy_servers[0][0] <= current_time:
                free_time, weight, index = heapq.heappop(busy_servers)
                heapq.heappush(free_servers, (weight, index))
            weight, index = heapq.heappop(free_servers)
            ans[j] = index
            heapq.heappush(busy_servers, (current_time + tasks[j], weight, index))
            
        return ans