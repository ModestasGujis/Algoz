#!/usr/bin/python3 

import networkx as nx

fl = open("node_10000", "r")

G = nx.Graph()
lines = fl.readlines()

# for i in range(1000):
# 	G.add_node(i)

for line in lines:
	# print(line)
	[a, b] = [int(x) for x in line.split(' ')]
	G.add_edge(a, b)

# nx.shortest_path(G, 3, 500)
for i in range(5000):
	print(len(nx.shortest_path(G, i, i + 1)))

# print(nx.shortest_path(G, 1, 4))