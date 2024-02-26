# Grace Lane
# hw3.py

import sys

# adding to the marked or swept list accordingly
def markedSwept(ptrDict, size, marked, swept):
	for element in ptrDict:                                    # for each element/key in the dictionary
		if len(ptrDict[element]) == 0:                             # if list in value is empty then sweep the element/key
			swept.append(element)
		for val in ptrDict[element]:                               # for values that point to the element/key
			if isinstance(val, str):                                   # if the value is a string (aka named pointer)
				if element not in marked:                                  # if the element/key is not in marked then add it
					marked.append(element)
			else:                                                      # if value is an int (aka heap block)
				pointedTo = pointed(ptrDict, val, size)       # check if the value that points to the element/key is pointed to by passing the value and the length of the list at the value
				if pointedTo == True:                                      # if pointedTo is true
					if element not in marked and element not in swept:         # if the element/key is not in marked and not in swept, add to swept
						marked.append(element)
				else:                                                      # if the value is not pointed to
					if element not in swept and element not in marked:         # if the element/key is not not in marked and not in swept, add to swept
						swept.append(element)

# recursive function to determine if the value is pointed to
def pointed(ptrDict, value, listSize):
	for i in ptrDict[value]:              # for each value that points to the element/key
		if isinstance(i, str):                # if the pointer is a string return true
			return True	
		else:
			if listSize > 0:
				return pointed(ptrDict, i, listSize - 1)

fileName = sys.argv[1]                 # gets name of file from command
inFile = open(fileName)                # opens file
numBlocks = inFile.readline()             # reads first line and assigns blocks to it
numBlocks = int(numBlocks.rstrip())               # strips trailing
# print(numBlocks)
nums = []

for line in inFile:
	line = line.rstrip().split(',')      # reads from file into line
	nums.append(line)

# print(nums)

# creates dictionary where the key is a number from 0 to total number of heap blocks and the value is a 
# list of all the pointers that point to the key
ptrs = {i:[] for i in range(0, numBlocks)}
for pair in nums:
	input = pair[0]
	key = pair[1]
	if input.isalpha():
		ptrs[int(key)].append(input)
	else:
		ptrs[int(key)].append(int(input))

# adds the values to either marked or swept list
marked = []
swept = []
markedSwept(ptrs, numBlocks, marked, swept)

# print the marked nodes
print('Marked Nodes: ', end=' '),
print(*marked)

# print the swept nodes
print('Swept Nodes: ', end=' '),
print(*swept)

inFile.close()