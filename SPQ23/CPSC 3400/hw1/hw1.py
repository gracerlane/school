# Grace Lane
# hw1.py

from curses.ascii import isalpha
import sys
import operator

def countPairs(file):
	freq = {}                                 # dictionary of pairs and their frequency
	inFile = open(file)                       # opens file
	fileString = inFile.read()                # reads file
	i = 0                                     # index
	while i < len(fileString) -1:             # while the index is less than the length of file - 1
		first = fileString[i].lower()           # get the first charcter of the pair
		second = fileString[i+1].lower()        # get the second character of the pair
		pair = first + second                   # make them a pair
		if pair in freq and pair.isalpha():     # if the pair is in the dictionary and they're letters
			freq[pair] +=1                        # increment value at key
		elif pair.isalpha():                    # else add new key with value of 1
			freq[pair] = 1
		i += 1                                  # increment index
	return freq                               # return dictionary

def getTopFivePairs(pairs):
	alphaList = list(sorted(pairs.items()))                                       # alphabetically sorted list of tuples from the dictionary
	decsList = sorted(alphaList, key=operator.itemgetter(1),reverse=True)         # sorts in descending order
	topFive = decsList[:5]                                                        # gets the top five
	for i in range(5, len(decsList)):                                             # if there is a tie for the fifth place then append them to the top list
		if decsList[i][1] == decsList[5][1]:
			topFive.append(decsList[i])
	return topFive

def createFollowsDict(pairs, letter):
	alpha = "abcdefghijklmnopqrstuvwxyz"       # declares the alphabet
	follow = {}                                # dictionary for following letters
	for i in alpha:                            # for the letters in the alphabet
		if letter + i in pairs:                  # if there is a match 
			follow[i] = pairs[letter + i]          
		else:
			follow[i] = 0
	return follow


# driver
fileName = sys.argv[1]
pairs = countPairs(fileName)
print(len(pairs))

sum = 0
for i in pairs:
	sum += pairs[i]
print(sum)

print(getTopFivePairs(pairs))

for x in "aeiou":
	print(x)
	# createFollowsDict(pairs, x)
	following = createFollowsDict(pairs, x)
	print([value for value in following.values()])


