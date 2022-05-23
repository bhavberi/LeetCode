class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        neg= False
        if( x < 0):
            neg = True
            x = -x
        
        num1 = 0
        while( x != 0):
              digit = x % 10
              num1 = (num1 * 10) + digit
              if(num1 >= 2147483647 or num1 <= -2147483647):
                     return 0
              x = x // 10
        if neg:
           return -num1
        return num1
