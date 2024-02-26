def insert(tree, value):
  if len(tree) == 0:
    tree.insert(0, value)
    tree.insert(1, [])
    tree.insert(2, [])
  else:
    print ('starting tree')
    print(tree)
    root = get_root_val(tree)
    if value < root:
      tree = insert_left(tree, value)
    elif value > root:
      tree = insert_right(tree, value)  