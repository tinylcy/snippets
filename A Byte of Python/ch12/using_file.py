# Using files

poem = '''\
Programming is fun
When the work is done
if you wanna make your work also fun:
	use Python!'''

f = open('poem.txt', 'w')  # Open for writing
f.write(poem) # Write text to file
f.close() # Close the file

f = open('poem.txt')
while True:
	line = f.readline()
	if len(line) == 0:
		break
	# We use end='' to suppress the automatic newline that the print statement adds because the line that
	# is read from the file already ends with a newline character.
	print(line, end='')
f.close()
