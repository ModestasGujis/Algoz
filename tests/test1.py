#!/usr/bin/python3
import main as gr

frm = [0, 1, 2, 3, 4, 5]
to = [1, 2, 3, 4, 5, 6]
w = [1, 10, 100, 1000, 10000, 100000]

gwei = gr.Graph(7, frm, to, w)
g = gr.Graph(7, frm, to)

if gwei.getVertexCnt() != 7:
	print('WRONG VERTEX COUNT')
else:
	print('PASSED')

if gwei.shortestDistance(0, 6) != 111111:
	print('WRONG WEIGHTED DISTANCE')
else:
	print('PASSED')

if g.getVertexCnt() != 7:
	print('WRONG VERTEX COUNT')
else:
	print('PASSED')

if g.shortestDistance(0, 6) != 6:
	print('WRONG DISTANCE')
else:
	print('PASSED')


