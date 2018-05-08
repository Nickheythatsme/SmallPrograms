import os
import networkx as nx

def main():
    lines = []
    with open('./affinites.txt','r') as fin:
        lines = fin.read().replace(' ','').split('\n')
        for i in range(len(lines)):
            lines[i] = lines[i].split('+')
    print(lines[0])
    print(lines[1])

    graph = nx.Graph()
    for line in lines:
        for i in range(1, len(line)):
            graph.add_edge(line[0], line[i])

    for n in graph.nodes:
        print(n)
        print(graph[n])
        input()

try:
    main()
except Exception as err:
    print(err)
input()
