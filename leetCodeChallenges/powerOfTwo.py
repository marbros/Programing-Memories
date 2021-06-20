class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        index = [i for i in range(32)]
        powerOfTwo = list(map(pow, [2]*31 , index)).count(n)
        
        return bool(powerOfTwo)