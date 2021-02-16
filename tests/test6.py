#!/usr/bin/python3
import main as gr

# 0 1 16
# 0 2 13
# 1 2 10
# 1 3 12
# 2 1 4
# 2 4 14
# 3 2 9
# 3 5 20
# 4 3 7
# 4 5 4

frm = [0, 0, 1, 1, 2, 2, 3, 3, 4, 4]
to = [1, 2, 2, 3, 1, 4, 2, 5, 3, 5]
w = [16, 13, 10, 12, 4, 14, 9, 20, 7, 4]

# make undirected
# temp = frm
# frm = frm + to
# to = to + temp

undir = gr.Graph(6, frm, to, w)

if(undir.maxFlow(0,5) == 23):
    print("PASSED");
else:
    print("WRONG MAX FLOW")
