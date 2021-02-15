#!/usr/bin/python3 

import networkx as nx

fl = open("node_10000", "r")

G = nx.Graph()
lines = fl.readlines()


for line in lines:
	[a, b] = [int(x) for x in line.split(' ')]
	G.add_edge(a, b)

for i in range(5000):
	print(len(nx.shortest_path(G, i, i + 1)))
