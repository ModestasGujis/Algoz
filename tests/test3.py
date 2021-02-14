#!/usr/bin/python3
import main as ds

d = ds.DSU(10)

d.unionSet(1, 5)
d.unionSet(1, 3)
d.unionSet(1, 2)

if not d.isSameSet(2, 5):
	print('not the same set')
else:
	print('PASSED')

if d.getSize(3) != 4:
	print('wrong size')
else:
	print('PASSED')

if d.getSize() != 10:
	print('wrong overall size')
else:
	print('PASSED')