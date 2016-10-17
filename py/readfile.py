#! /usr/bin/env python

'readfile.py : to read and show text file'

# get filename
fname = raw_input('enter filename:')

# try to open file and read
try:
	fileobj = open(fname,'r')
except IOError, e:
	print "[ERROR] open file:",e
else:
	# show file text
	for eachline in fileobj:
		print eachline,
	fileobj.close()