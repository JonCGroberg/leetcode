class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # generate freqmap for each string
        frequencyMaps = []
        results=[]

        for string in strs:
            frequencyMaps.append((string, self.generateFreqMap(string)))
     
        while len(frequencyMaps) > 0:
            initialPair = frequencyMaps.pop(0)  # pop from the beginning
            matchingMaps = [initialPair[0]]
            i = 0
            while i < len(frequencyMaps):
                freqMapPair = frequencyMaps[i]
                if freqMapPair[1] == initialPair[1]:
                    matchingMaps.append(freqMapPair[0])
                    frequencyMaps.pop(i)  # remove the matched pair
                else:
                    i += 1
            results.append(matchingMaps)

        return results

    def generateFreqMap(self, string: str) -> dict:
        frequencyMap = {}
        for char in string:
            if char in frequencyMap:
                frequencyMap[char] += 1
            else:
                frequencyMap[char] = 1
        return frequencyMap
