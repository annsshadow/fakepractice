#! /usr/bin/env python

'create text file'

import os
ls = os.linesep

# get the filename
while True:
	if os.path.exists(fname):
		print "[ERROR]: '%s' already exists" % fname
	else:
		break

# get file content:text line
all = []
print "\nenter lines ('.' by itself to quit).\n"

# loop until user finish input
while True:
	entry = raw_input('>')
	if entry == '.':
		break
	else:
		all.append(entry)

# write lines to file with proper line-ending
fileobj = open(fname,'w')
fileobj.writelines(['%s%s' % (x, ls) for x in all])
fileobj.close
print '[FINISHED]'