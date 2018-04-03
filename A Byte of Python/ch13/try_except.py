# Handling exceptions

import sys

try:
	s = input('Enter something --> ')
except EOFError:
	print('\nWhy did you do an EOF on me?')
	sys.exit()  # Exit the program
except:
	print('\nSome error/exception occurred.')

print('Done')
