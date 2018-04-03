# Using the if statement

number = 23
# raw_input() was renamed to input() in Python 3.x
guess = int(input('Enter an integer: '))

if guess == number:
	print('Congratulations, you guessed it.')
	print("(but you do not win any prizes!)")
elif guess < number:
	print('No, it is a little higher than that.')
else:
	print('No, it is a little lower than that.')

print('Done')
