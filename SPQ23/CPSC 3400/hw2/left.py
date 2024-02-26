def insert_left(tree, input):
	class DuplicateEntry (Exeption): pass
	try:
		subtree = tree.pop(1)
		if len(subtree) > 1:
			sub_root = subtree[0]
			if input < sub_root:
				childtree = subtree.pop(1)
				if len(childtree) > 1:
					if input < childtree[0]:
						subtree.insert(1,insert_left(childtree, input))
					elif input > childtree[0]:
						subtree.insert(1,insert_right(childtree, input))
					else:
						raise DuplicateEntry
				else:
					subtree.insert(1, [input, [], []])
				tree.insert(1, subtree)
			elif input > sub_root:
				tree.insert(1, insert_right(subtree, input))
			else:
				raise DuplicateEntry
		else:
			tree.insert(1, [input, [], []])
		return tree
	except DuplicateEntry:
		print('Duplicate value detected: ' + str(input))
		return tree