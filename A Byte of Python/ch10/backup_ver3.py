# Backup script - the third version

import os
import time

# The files and directories to be backed up are specified in a list.
# If you are using Windows, use `source = [r'D:\Work']`.
sources = ['./data']

# `./` means the current directory.
# Remember to change this to what you will be using.
target_dir = './'

# The files are backed up into a zip file.
# The current day is the name of the subdirectory in the main directory.
today = target_dir + time.strftime('%Y%m%d')
# The current time is the name of the zip archive.
now = time.strftime('%H%M%S')

# Take a comment from the user to create the name of the zip file.
comment = input('Enter a comment --> ')
if len(comment) == 0:
	target = today + os.sep + now + '.zip'
else:
	target = today + os.sep + now + '_' + comment.replace(' ', '_') + '.zip'

# Create  the subdirectory if it isn't already there.
if not os.path.exists(today):
	os.mkdir(today)
	print('Successfully created directory', today)

# We use the zip command (in Unix/Linux) to put the files in a zip archive
zip_command = "zip -qr '%s' '%s'" % (target, ' '.join(sources))

# Run the backup
if os.system(zip_command) == 0:
	print('Successful backup to', target)
else:
	print('Backup FAILED')
