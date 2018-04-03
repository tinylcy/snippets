# Using dictionaries

# 'ab' is short for 'a'ddress'b'ook
ab = {
	'Swaroop': 'swaroopch@byteofpython.info',
	'Larry': 'larry@wall.org',
	'Matsumoto': 'matz@ruby-lang.org',
	'Spammer': 'spammer@hotmail.com'
}

print("Swaroop's address is %s" % ab['Swaroop'])

# Adding a key/value pair
ab['Guido'] = 'guido@python.org'

# Deleting a key/value pair
del ab['Spammer']

print('\nThere are %d contacts in the address-book\n' % len(ab))

# items method returns a list of tuples where each tuple contains a pair of items - the key followed by the value.
# print(ab.items())

for name, address in ab.items():
	print('Contact %s at %s' % (name, address))

if 'Guido' in ab:
	print("\nGuido's address is %s" % ab['Guido'])
