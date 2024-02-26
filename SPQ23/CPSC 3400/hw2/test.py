def insert_left(root, child_val):
	subtree = root.pop(1)
	if len(subtree) > 1:
		root.insert(1, [child_val, subtree, []])
	else:
		root.insert(1, [child_val, [], []])
	return root

def insert_right(root, child_val):
	subtree = root.pop(2)
	if len(subtree) > 1:
		root.insert(2, [child_val, [], subtree])
	else:
		root.insert(2, [child_val, [], []])
	return root

def get_root_val(root):
	return root[0]

def set_root_val(root, new_val):
	root[0] = new_val

def get_left_child(root):
	return root[1]

def get_right_child(root):
	return root[2]

# driver
root = [3, [], []]
insert_left(root, 4)
print(root)
insert_left(root, 5)
print(root)
insert_right(root, 6)
insert_right(root, 7)
left = get_left_child(root)
print(left)  # => [5, [4, [], []], []]

set_root_val(left, 9)
print(root)  # => [3, [9, [4, [], []], []], [7, [], [6, [], []]]]

insert_left(left, 11)
print(root)  # => [3, [9, [11, [4, [], []], []], []], [7, [], [6, [], []]]]

print(get_right_child(get_right_child(root)))  # => [6, [], []]


  # try:
    # insert value into tree
    # look at each node
    # if value less than node do this if greater than do that
    # tree.append(value)
  # except DuplicateEntry:
  #   print("Duplicate value detected: " + value)
    # skip to next value
  # some exception about invalid line















	

	# Grace Lane
# hw2.py
# Write a Python program (hw2.py) that uses Python lists to store a binary 
#  search tree of integers. A tree consists of a single list with either three
#  elements [value of root node, left subtree, right subtree] or zero elements 
#  [] (represents an empty tree).

import sys

def get_root_val(tree):
  return tree[0]

def insert_left(tree, child):
  print(tree)
  subtree = tree.pop(1)
  print(subtree)
  if len(subtree) > 1:
    sub_root = subtree[0]
    print(sub_root)
    if child < sub_root:
      childtree = subtree.pop(1)
      print(childtree)
      subtree.insert(1, [child, [], []])
      tree.insert(1, subtree)
    elif child > sub_root:
      insert_right(tree,child)
  else:
    tree.insert(1, [child, [], []])
    # print("after initial insert")
  print('after insert')
  print(tree)
  return tree

def insert_right(tree, child):
  print(tree)
  subtree = tree.pop(2)
  print(subtree)
  if len(subtree) > 1:
    sub_root = subtree[0]
    print(sub_root)
    if child > sub_root:
      subtree.pop(2)
      subtree.insert(2, [child, [], []])
      tree.insert(2, subtree)
    elif child < sub_root:
      subtree.pop(1)
      subtree.insert(1, [child, [], []])
      tree.insert(1, subtree)
  else:
    tree.insert(2, [child, [], []])
  print('after insert')
  print(tree)
  return tree

# Inserts the value into the tree. The resulting tree does NOT need
# to be balanced. If the value is already in the tree, do not add the entry to the tree and throw a
# DuplicateEntry exception instead. You must create the DuplicateEntry exception.
def insert(tree, value):
  if len(tree) == 0:      # if tree is empty, then insert root
    tree.insert(0, value)
    tree.insert(1, [])
    tree.insert(2, [])
    print('inital tree')
    print (tree)
  else:
    root = get_root_val(tree)
    if value < root:
      print(str(value) + " value less than " + str(root))
      tree = insert_left(tree, value)
    elif value > root:
      print(str(value) + " value greater than " + str(root))
      tree = insert_right(tree, value)
  # return tree
  
    
# Returns true if the value is in the tree and false otherwise.
def search(tree, value):
  # call inorder?
  # if not found
	return False
  # if found 
	return True

# Does an inorder traversal of the nodes. This is to be implemented using a
# generator function. It yields the next node in the traversal.
#  - If you use a recursive function (recommended), you need to use yield from when
#    calling inorder recursively. You can also implement a non-recursive version of the
#    function
def inorder(tree):
    yield tree
  # left-root-right

# Creates a dictionary where there is an entry for each node in the tree. The
# dictionary key is the node value and the dictionary value is the height of that node. The
# height is 0 for the root and the number of edges the node is away from the root for all other
# nodes.
def heights(tree):
	nodes = {}

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







# Grace Lane
# hw2.py
# Write a Python program (hw2.py) that uses Python lists to store a binary 
#  search tree of integers. A tree consists of a single list with either three
#  elements [value of root node, left subtree, right subtree] or zero elements 
#  [] (represents an empty tree).

import sys

def get_root_val(tree):
  return tree[0]

def insert_left(tree, input):
  print('before insert')
  print(tree)
  subtree = tree.pop(1)
  print('subtree 1')
  print(subtree)
  if len(subtree) > 1:
    sub_root = subtree[0]
    print('subroot')
    print(sub_root)
    print('input')
    print(input)
    if input < sub_root:
      childtree = subtree.pop(1)
      if len(childtree) > 1:
        print('len > 1')
        print('child root')
        print(childtree[0])
        if input < childtree[0]:
          subtree.insert(1,insert_left(childtree, input))
        else:
          subtree.insert(1,insert_right(childtree, input))
        print('subtree after insert')
        print(subtree)
      else:
        subtree.insert(1, [input, [], []])
      tree.insert(1, subtree)
    elif input > sub_root:
      print('input > subroot')
      tree.insert(1, insert_right(subtree, input))
  else:
    tree.insert(1, [input, [], []])
    # print("after initial insert")
  print('after insert')
  print(tree)
  return tree

def insert_right(tree, input):
  print('before insert')
  print(tree)
  subtree = tree.pop(2)
  print('subtree 2')
  print(subtree)
  if len(subtree) > 1:
    sub_root = subtree[0]
    print('subroot')
    print(sub_root)
    print('input')
    print(input)
    if input > sub_root:
      subtree.pop(2)
      subtree.insert(2, [input, [], []])
      tree.insert(2, subtree)
    elif input < sub_root:
      print('input < subroot')
      tree.insert(1, insert_right(subtree, input))
  else:
    tree.insert(2, [input, [], []])
  print('after insert')
  print(tree)
  return tree

# Inserts the value into the tree. The resulting tree does NOT need
# to be balanced. If the value is already in the tree, do not add the entry to the tree and throw a
# DuplicateEntry exception instead. You must create the DuplicateEntry exception.
def insert(tree, value):
  if len(tree) == 0:      # if tree is empty, then insert root
    tree.insert(0, value)
    tree.insert(1, [])
    tree.insert(2, [])
    print('inital tree')
    print (tree)
  else:
    print ('starting tree')
    print(tree)
    root = get_root_val(tree)
    if value < root:
      print(str(value) + " value less than " + str(root))
      tree = insert_left(tree, value)
    elif value > root:
      print(str(value) + " value greater than " + str(root))
      tree = insert_right(tree, value)
  # return tree
  
    
# Returns true if the value is in the tree and false otherwise.
def search(tree, value):
  # call inorder?
  # if not found
	return False
  # if found 
	return True

# Does an inorder traversal of the nodes. This is to be implemented using a
# generator function. It yields the next node in the traversal.
#  - If you use a recursive function (recommended), you need to use yield from when
#    calling inorder recursively. You can also implement a non-recursive version of the
#    function
def inorder(tree):
    yield tree
  # left-root-right

# Creates a dictionary where there is an entry for each node in the tree. The
# dictionary key is the node value and the dictionary value is the height of that node. The
# height is 0 for the root and the number of edges the node is away from the root for all other
# nodes.
def heights(tree):
	nodes = {}

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


