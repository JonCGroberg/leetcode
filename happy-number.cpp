class Solution:
    def isHappy(self, n: int) -> bool:
        # if we run into a value we have seen then its in a loop
        # else it will hit 1 eventually as per instructions
        # stores seen values in set

        history = set()

        while True:
            if n in history:
                return False
            if n == 1:
                return True

            history.add(n)
            n = self.sumOfSquareDigits(n)

    def sumOfSquareDigits(self, n):
        total = 0
        while n > 0:
            total += (n % 10) **2
            n //= 10
        return total
