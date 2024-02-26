import sys

def get_root_val(tree):
  return tree[0]

class DuplicateEntry(Exception): pass

def insert_left(tree, input):
	try:
		subtree = tree.pop(1)
		if len(subtree) > 1:
			sub_root = subtree[0]
			# print('subroot')
			# print(sub_root)
			# print('input')
			# print(input)
			if input < sub_root:
				childtree = subtree.pop(1)
				if len(childtree) > 1:
					# print('len > 1')
					# print('child root')
					# print(childtree[0])
					if input < childtree[0]:
						subtree.insert(1,insert_left(childtree, input))
					elif input > childtree[0]:
						subtree.insert(1,insert_right(childtree, input))
					else:
						tree.insert(1, subtree)
						raise DuplicateEntry
				else:
					subtree.insert(1, [input, [], []])
				tree.insert(1, subtree)
			elif input > sub_root:
				tree.insert(1, insert_right(subtree, input))
			else:
				tree.insert(1, subtree)
				raise DuplicateEntry
		else:
			tree.insert(1, [input, [], []])
		return tree
	except DuplicateEntry:
		print('Duplicate value detected: ' + str(input))
		return tree
	
def insert_right(tree, input):
	class DuplicateEntry(Exception): pass
	try:
		subtree = tree.pop(2)
		if len(subtree) > 1:
			sub_root = subtree[0]
			# print('subroot')
			# print(sub_root)
			# print('input')
			# print(input)
			if input > sub_root:
				childtree = subtree.pop(2)
				if len(childtree) > 1:
					# print('len > 1')
					# print('child root')
					# print(childtree[0])
					if input > childtree[0]:
						subtree.insert(2,insert_right(childtree, input))
					elif input < childtree[0]:
						subtree.insert(2,insert_left(childtree, input))
					else:
						tree.insert(2, subtree)
						raise DuplicateEntry
				else:
					subtree.insert(2, [input, [], []])
				tree.insert(2, subtree)
			elif input < sub_root:
				tree.insert(2, insert_left(subtree, input))
			else:
				tree.insert(2, subtree)
				raise DuplicateEntry
		else:
			tree.insert(2, [input, [], []])
		return tree
	except DuplicateEntry:
		print('Duplicate value detected: ' + str(input))
		return tree
	
def insert(tree, value):
  if len(tree) == 0:
    tree.insert(0, value)
    tree.insert(1, [])
    tree.insert(2, [])
  else:
    # print ('starting tree')
    # print(tree)
    root = get_root_val(tree)
    if value < root:
      tree = insert_left(tree, value)
    elif value > root:
      tree = insert_right(tree, value)  

# Driver
fileName = sys.argv[1]
inFile = open(fileName)
treeList = []
for line in inFile:
  line = line.rstrip()
  val = int(line)
  insert(treeList, val)

print(treeList)




inFile.close()


