# Using the __init__ method

class Person:
	def __init__(self, name):
		self.name = name

	def sayHi(self):
		print('Hello, my name is', self.name)


p = Person('tinylcy')
p.sayHi()
