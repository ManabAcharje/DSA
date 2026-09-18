class Solution:
    def checkDivisibility(self, n: int) -> bool:
        copy = n
        ds = 0
        dp = 1
        while n>0:
            n,digit= divmod(n,10)
            ds+=digit
            dp*=digit
        return copy %(ds+dp) == 0
        
        