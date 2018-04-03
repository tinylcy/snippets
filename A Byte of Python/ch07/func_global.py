# Using the global statement
# However, global statement is not encouraged and should be avoided since
# it becomes unclear to the reader of the program as to where that variable's definition is.

def func():
	global x
	print('x is', x)
	x = 2
	print('Changed global x to', x)


x = 50
func()
print('Value of x is', x)
