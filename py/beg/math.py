1#! /usr/bin/env python

import math
for each_num in (.3, .8, 1.3, 1.8, -.3, -.8, -1.3, -1.8):
	print "int(%.1f)\t+%.1f" % (each_num, float(each_num))
	print "floor(%.1f)\t+%.1f" % (each_num, math.floor(each_num))
	print "round(%.1f)\t+%.1f" % (each_num, round(each_num))
	print '-' * 20