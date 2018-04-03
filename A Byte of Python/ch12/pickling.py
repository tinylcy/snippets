# Pickling and unpickling

import pickle as p

shoplistfile = 'shoplist.data'
shoplist = ['apple', 'mango', 'carrot']

# Be careful: the output file and input file need to be opened in binary mode.
# More details: https://stackoverflow.com/questions/13906623/using-pickle-dump-typeerror-must-be-str-not-bytes

# Write to the file
f = open(shoplistfile, 'wb')
p.dump(shoplist, f)  # Dump the object to a file
f.close()

# Read back from the storage
f = open(shoplistfile, 'rb')
storedlist = p.load(f)
print(storedlist)
