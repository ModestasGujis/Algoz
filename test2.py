#!/usr/bin/python3
import main as gr

# 0 2
# 0 4
# 0 5
# 1 4
# 1 5
# 2 3
# 2 4
# 4 5

frm = [0, 0, 0, 1, 1, 2, 2, 4]
to = [2, 4, 5, 4, 5, 3, 4, 5]

# make directed
temp = frm
frm = frm + to;
to = to + temp;


# w = [1, 10, 100, 1000, 10000, 100000]

# gwei = gr.Graph(7, frm, to, w)
g = gr.Graph(6, frm, to)

if g.shortestPath(3, 5) != [3, 2, 4, 5]:
	print('wrong path')
else:
	print('PASSED')



