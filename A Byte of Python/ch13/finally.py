# Using finally

import time

try:
	f = open('poem.txt')
	while True:
		line = f.readline()
		if len(line) == 0:
			break
		time.sleep(2)
		print(line, end='')
finally:
	f.close()
	print('\nCleaning up...closed the file')
