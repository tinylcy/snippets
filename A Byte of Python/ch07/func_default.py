# Using default argument values

def say(message, times=1):
	print(message * times)


say('Hello')
say('Hello', 5)
say(times=2, message='Hello')
