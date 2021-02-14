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

undir = gr.Graph(6, frm, to)

topoSort = undir.topoSort();

print(topoSort);

# make undirected
temp = frm
frm = frm + to;
to = to + temp;

dir = gr.Graph(6, frm, to)

topoSort = dir.topoSort();

if len(topoSort) != 0:
	print('found sort in graph with cycle')
else:
	print('PASSED')
