# Using inheritance

# The __init__ method of the base class is explicitly called using the self
# variables so that we can initialize the base class part of the object.
# This is very important to remember - Python does not automatically call
# the constructor of the base class, you have to explicitly call it yourself.

# We can call methods of the base class by prefixing the class name to the method
# call and then pass in the self variable along with any arguments.

class SchoolMember:
	'''Represents any school member.'''

	def __init__(self, name, age):
		self.name = name
		self.age = age
		print('(Initialized SchoolMember: %s)' % self.name)

	def tell(self):
		'''Tell my details.'''
		print('Name: "%s Age: "%s' % (self.name, self.age))


class Teacher(SchoolMember):
	'''Represents a teacher.'''

	def __init__(self, name, age, salary):
		SchoolMember.__init__(self, name, age)
		self.salary = salary
		print('(Initialized Teacher: %s)' % self.name)

	def tell(self):
		SchoolMember.tell(self)
		print('Salary: "%d"' % self.salary)


class Student(SchoolMember):
	'''Represents a student.'''

	def __init__(self, name, age, marks):
		SchoolMember.__init__(self, name, age)
		self.marks = marks
		print('(Initialized Student: %s)' % self.name)

	def tell(self):
		SchoolMember.tell(self)
		print('Marks: "%d"' % self.marks)


t = Teacher('Mrs. Shrividya', 40, 30000)
s = Student('Swaroop', 22, 75)

members = [t, s]
for member in members:
	member.tell()
