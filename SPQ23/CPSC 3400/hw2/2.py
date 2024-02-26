import sys

class DuplicateEntry(Exception):  # for creating the exception when there are multiples of a value
	pass

# Inserts the value into the tree. The resulting tree does NOT need
# to be balanced. If the value is already in the tree, do not add the entry to the tree and throw a
# DuplicateEntry exception instead. You must create the DuplicateEntry exception.
def insert(tree, value):
	try:
		if len(tree) == 0:
			tree.insert(0, value)
			tree.insert(1, [])
			tree.insert(2, [])
		elif value == tree[0]:
			raise DuplicateEntry
		elif value < tree[0]:
			return insert(tree[1], value)
		else:
			return insert(tree[2], value)
	except DuplicateEntry:
		print('Duplicate value detected: ' + str(value))


# Returns true if the value is in the tree and false otherwise.
def search(tree, value):
	if len(tree) == 0:
		return False
	elif value == tree[0]:
		return True
	elif value < tree[0]:
		return search(tree[1], value)
	else:
		return search(tree[2], value)


# Does an inorder traversal of the nodes. This is to be implemented using a
# generator function. It yields the next node in the traversal.
#  - If you use a recursive function (recommended), you need to use yield from when
#    calling inorder recursively. You can also implement a non-recursive version of the
#    function
def inorder(tree):
	if len(tree) == 0:
		return
	yield from inorder(tree[1])
	yield (tree[0])
	yield from inorder(tree[2])


# Creates a dictionary where there is an entry for each node in the tree. The
# dictionary key is the node value and the dictionary value is the height of that node. The
# height is 0 for the root and the number of edges the node is away from the root for all other
# nodes.
def heights(tree):
	nodes = {}
	if len(tree) == 0:
		return nodes
	height = 0
	print(heightsHelp(tree, nodes, height))

# Helper recursive function for heights function
def heightsHelp (tree, nodes, height):
	if len(tree) == 0:
		return {}
	nodes[tree[0]] = height
	left = heightsHelp(tree[1], nodes, height + 1)
	right = heightsHelp(tree[2], nodes, height + 1)
	nodes.update(left)
	nodes.update(right)

	return nodes



# Driver
fileName = sys.argv[1]
inFile = open(fileName)
treeList = []
count = 0
for line in inFile:
	try:
		line = line.rstrip()
		val = int(line)
		insert(treeList, val)
		count += 1
	except ValueError:
		count += 1
		print('Invalid line at line number: ' + str(count))

print('Step 3:')
print(treeList)

# heights(treeList)

print('Step 4:')
nums = [1, 2, 3, 4, 5, 6, 7, 8, 9]
for val in nums:
	print(str(val) + " " + str(search(treeList, val)))

print('Step 5:')
for value in inorder(treeList):
	print(value)

print('Step 6:')
inorderList = [x for x in inorder(treeList)]
print(inorderList)


print('Step 7:')
heights(treeList)

inFile.close()
