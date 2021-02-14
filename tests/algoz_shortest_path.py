#!/usr/bin/python3 

import main as gr

fl = open("node_10000", "r")

G = gr.Graph(10000)

# for i in range(1000):
# 	G.addVertex()

lines = fl.readlines()
for line in lines:
	[a, b] = [int(x) for x in line.split(' ')]
	G.addEdge(a, b)
	G.addEdge(b, a)

for i in range(5000):
	print(len(G.shortestPath(i, i + 1)))
