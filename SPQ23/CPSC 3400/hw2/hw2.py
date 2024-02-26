# Grace Lane
# hw2.py

import sys

class DuplicateEntry(Exception):  # creating the exception when there are multiples of a value
	pass

# Inserts the value into the tree. The resulting tree does NOT need
# to be balanced. If the value is already in the tree, do not add the entry to the tree and throw a
# DuplicateEntry exception instead. You must create the DuplicateEntry exception.
def insert(tree, value):
	try:
		if len(tree) == 0:            # if tree is empty, then assign the value as the root
			tree.insert(0, value)
			tree.insert(1, [])
			tree.insert(2, [])
		elif value == tree[0]:        # if value is equal to the node then raise DuplicateEntry exception
			raise DuplicateEntry
		elif value < tree[0]:             # if value is less than root then go to left subtree
			return insert(tree[1], value)
		else:                             # if value is greater than root then go to right subtree
			return insert(tree[2], value)
	except DuplicateEntry:
		print('Duplicate value detected: ' + str(value))     # prints the duplicate value


# Returns true if the value is in the tree and false otherwise.
def search(tree, value):
	if len(tree) == 0:
		return False
	elif value == tree[0]:      # if value is found return True
		return True
	elif value < tree[0]:             # if value is less than root then go to left subtree
		return search(tree[1], value)
	else:                             # if value is greater than root then go to right subtree
		return search(tree[2], value)


# Does an inorder traversal of the nodes. This is to be implemented using a
# generator function. It yields the next node in the traversal.
#  - If you use a recursive function (recommended), you need to use yield from when
#    calling inorder recursively. You can also implement a non-recursive version of the
#    function
def inorder(tree):
	if len(tree) == 0:     # if tree is empty then return
		return
	yield from inorder(tree[1])      # yield to the left
	yield (tree[0])                  # yiel root 
	yield from inorder(tree[2])      # yield to the right


# Creates a dictionary where there is an entry for each node in the tree. The
# dictionary key is the node value and the dictionary value is the height of that node. The
# height is 0 for the root and the number of edges the node is away from the root for all other
# nodes.
def heights(tree):
	nodes = {}             # dictionary to hold nodes and their heights
	if len(tree) == 0:     # if tree is empty then return dictionary
		return nodes
	height = 0
	heightsHelp(tree, nodes, height)     # calls recursive function
	return nodes                         # returns nodes

# Helper recursive function for heights function
def heightsHelp (tree, nodes, height):
	if len(tree) == 0:                     # if tree is empty then return empty dictionary
		return {}
	nodes[tree[0]] = height        # add in root with height of 0
	left = heightsHelp(tree[1], nodes, height + 1)     # go to the left
	right = heightsHelp(tree[2], nodes, height + 1)    # go to the right
	nodes.update(left)   # update with the left
	nodes.update(right)  # update with the right

	return nodes       # return nodes



# Driver
fileName = sys.argv[1]                 # gets name of file from command
inFile = open(fileName)
treeList = []                          # creates list to store tree
count = 0                              # for showing where invalid lines are
for line in inFile:
	try:
		line = line.rstrip()               # reads from file into line
		val = int(line)                    # sets val to int value of line
		insert(treeList, val)              # calls insert to insert into tree
		count += 1
	except ValueError:                   # if there is an invalid line then it prints out the line number from the file where the error happened
		count += 1
		print('Invalid line at line number: ' + str(count))

print('Step 3:')
print(treeList)      # prints the tree

print('Step 4:')
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
for val in nums:
  if search(treeList, val) == True:
    print(str(val) + " YES")    # prints True or False if 1-9 is in the tree
  if search(treeList, val) == False:
    print(str(val) + " NO")

print('Step 5:')
for value in inorder(treeList):        # prints the values after an inorder traversal
	print(value)

print('Step 6:')
inorderList = [x for x in inorder(treeList)]       # creates a list of the values after an inorder traversal adn prints
print(inorderList)

print('Step 7:')
heightDict = heights(treeList)           # creates heightDict which is a dictionary of the nodes and their heights then prints it
print(heightDict)

print('Step 8:')
print(max(heightDict.values()))       # prints the max value in heightDict (aka the height of the tree)

inFile.close()
