class Codec:
    def encode(self, strings: List[str]) -> str:
        """Encodes a list of strings to a single string."""
        countPlusStrings = []
        for string in strings:
            countPlusStrings.append("".join([str(len(string)), string]))
        encoded = "".join(countPlusStrings)
        print(encoded)
        return encoded

    def decode(self, string: str) -> List[str]:
        """Decodes a single string to a list of strings."""
        stringsArr = []
        wordArr = []
        expectedWordLength = int(string[0])
        currentWordLength = 0

        for i in range(1, len(string)):
            if currentWordLength < expectedWordLength:
                wordArr.append(string[i])
                currentWordLength += 1
            else:
                word = "".join(wordArr)
                stringsArr.append(word)
                expectedWordLength = int(string[i])
                currentWordLength = 0
                wordArr=[]
                continue

        stringsArr.append("".join(wordArr)) 
        return stringsArr


# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(strs))
