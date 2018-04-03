name = 'tinylcy'

if name.startswith('tiny'):
	print('Yes, the string starts with "tiny"')

if 'y' in name:
	print('Yes, it contains the string "y"')

if name.find('ny') != -1:
	print('Yes, it contains the string "ny"')

delimiter = '_*_'
mylist = ['Brazil', 'Russia', 'India', 'China']
print(delimiter.join(mylist))
