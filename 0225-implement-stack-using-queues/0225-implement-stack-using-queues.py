class MyStack(object):

    def __init__(self):
        self.Q1=[]
        self.Q2=[]

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.Q2.append(x)
        while self.Q1:
            self.Q2.append(self.Q1.pop(0))
        self.Q1,self.Q2=self.Q2,self.Q1

    def pop(self):
        """
        :rtype: int
        """
        return self.Q1.pop(0)

    def top(self):
        """
        :rtype: int
        """
        return self.Q1[0]

    def empty(self):
        """
        :rtype: bool
        """
        return len(self.Q1)==0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()