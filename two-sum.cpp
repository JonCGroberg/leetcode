class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # create hashamap for nums
        # for loop using enumerate to grab index and elem
        # calculate complment using index - elem
        # check if complenent is in hashamp, if so reutnr i and the index from the hashmap element ( the value)

        hashmap = {}
        for i, n in enumerate(nums):
            hashmap[n] = i

        for i, n in enumerate(nums):
            complement = target - n
            if complement in hashmap and i!= hashmap[complement]:
                return [i, hashmap[complement]]
