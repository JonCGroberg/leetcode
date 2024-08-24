class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
       # create freq list for s and t (hashmap num:count)
       # if they are the same then they are valid
        if len(s) != len(t):
            return False

        S = self.generateFrequencyMap(s) 
        T = self.generateFrequencyMap(t) 

        return S == T

    def generateFrequencyMap(self, string:str):
        freqMap = {}
        
        for char in string:
            if char in freqMap:
                freqMap[char] +=1
            else:
                freqMap[char] = 1
        
        return freqMap