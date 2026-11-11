class Solution(object):
    def minimumCost(self, cost1, cost2, costBoth, need1, need2):
        """
        :type cost1: int
        :type cost2: int
        :type costBoth: int
        :type need1: int
        :type need2: int
        :rtype: int
        """
        common_need = min(need1, need2)
        total_cost = common_need * min(costBoth, cost1 + cost2)
        rem1 = need1 - common_need
        rem2 = need2 - common_need
        if rem1 > 0:
            total_cost += rem1 * min(costBoth, cost1)
        if rem2 > 0:
            total_cost += rem2 * min(costBoth, cost2)
            
        return total_cost