# Using the while statement

number = 23
running = True

while running:
	# raw_input() was renamed to input() in Python 3.x
	guess = int(input('Enter an integer: '))

	if guess == number:
		print('Congratulations, you guessed it.')
		running = False
	elif guess < number:
		print('No, it is a little higher than that.')
	else:
		print('No, it is a little lower than that.')
else:
	print('The while loop is over.')

print('Done.')
