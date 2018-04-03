# Objects and references

print('Simple Assignment')
shoplist = ['apple', 'mango', 'carrot', 'banana']
mylist = shoplist  # mylist is just another name pointing to the same object.

del shoplist[0]

# Notice that both shoplist and mylist print the same list without
# the 'apple' confirming that the point to the same object.
print('shoplist is', shoplist)
print('mylist is', mylist)

print('Copy by making a full slice')
mylist = shoplist[:]
del mylist[0]

print('shoplist is', shoplist)
print('mylist is', mylist)

# What you need to remember is that if you want to make a copy of a list of such kinds of sequences
# or complex objects (not simple objects such as integers), then you have to use the slicing operation
# to make a copy. If you just assign the variable name to another name, both of them will refer to the
# same object and this could lead to all sorts of trouble if you are not careful.
