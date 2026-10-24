class Solution(object):
    def countDaysTogether(self, arriveAlice, leaveAlice, arriveBob, leaveBob):
        """
        :type arriveAlice: str
        :type leaveAlice: str
        :type arriveBob: str
        :type leaveBob: str
        :rtype: int
        """
        days_in_months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        def date_to_day_number(date_str):
            month, day = map(int, date_str.split('-'))
            return sum(days_in_months[:month - 1]) + day
        a_arrive = date_to_day_number(arriveAlice)
        a_leave = date_to_day_number(leaveAlice)
        b_arrive = date_to_day_number(arriveBob)
        b_leave = date_to_day_number(leaveBob)
        latest_arrival = max(a_arrive, b_arrive)
        earliest_leave = min(a_leave, b_leave)
        overlap_days = earliest_leave - latest_arrival + 1
        return max(0, overlap_days)