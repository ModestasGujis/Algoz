#!/usr/bin/python3
import main as gr

# 0 2 5
# 0 3 7
# 0 5 6
# 1 3 2
# 1 5 1
# 2 4 4
# 2 3 7
# 3 5 5 

frm = [0, 0, 0, 1, 1, 2, 2, 3]
to = [2, 3, 5, 3, 5, 4, 3, 5]
w = [5, 7, 6, 2, 1, 4, 7, 5]

# make undirected
temp = frm
frm = frm + to;
to = to + temp;

undir = gr.Graph(6, frm, to, w)

print(undir.MST())