# Using the break statement

while True:
	# raw_input() was renamed to input() in Python 3.x
	s = input('Enter something: ')
	if s == 'quit':
		break
	# len() is a Python build-in function
	print('Length of the sting is', len(s))

print('Done')
