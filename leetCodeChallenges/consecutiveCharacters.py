from itertools import groupby

class Solution:
    def maxPower(self, s: str) -> int:
        return max([len(list(i)) for _, i in groupby(s)])