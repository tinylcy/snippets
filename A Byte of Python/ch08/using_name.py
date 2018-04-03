# Using a module's __name__

# Every Python module has it's __name__ defined and if this is '__main__', it implies
# that the module is being run standalone by the user and we can do corresponding appropriate actions.
if __name__ == '__main__':
	print('This program is being run by itself')
else:
	print('I am being imported from another module')
