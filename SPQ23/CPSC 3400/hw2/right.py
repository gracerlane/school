def insert_right(tree, input):
	class DuplicateEntry (Exeption): pass
	try:
		subtree = tree.pop(2)
		if len(subtree) > 1:
			sub_root = subtree[0]
			if input > sub_root:
				childtree = subtree.pop(2)
				if len(childtree) > 1:
					if input > childtree[0]:
						subtree.insert(2,insert_right(childtree, input))
					elif input < childtree[0]:
						subtree.insert(2,insert_left(childtree, input))
					else:
						raise DuplicateEntry
				else:
					subtree.insert(2, [input, [], []])
				tree.insert(2, subtree)
			elif input < sub_root:
				tree.insert(2, insert_left(subtree, input))
			else:
				raise DuplicateEntry
		else:
			tree.insert(2, [input, [], []])
		return tree
	except DuplicateEntry:
		print('Duplicate value detected: ' + str(input))
		return tree