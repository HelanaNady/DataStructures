# Graphs
**A graph is a [non-linear](https://byjus.com/gate/difference-between-linear-and-non-linear-data-structures/#:~:text=What%20Is%20a%20Non%2DLinear,elements%20in%20a%20single%20run.) data structure composed of interconnected nodes and edges.** 
- Nodes, often referred to as vertices, represent entities or data points within the graph. 
- Edges, on the other hand, define the relationships or connections between these nodes.
Unlike linear data structures like arrays or linked lists, graphs excel at modeling complex networks and systems where connections between elements are intricate. 

![image](https://github.com/user-attachments/assets/fb3ed88e-5060-4852-92a6-5806890d4432)

> [!TIP]
> You may find the look of it very similar to the Tree DS.
> That is because a Tree itself is a special type of Graphs with certain constraints: (a connected acyclic graph with unique paths between any two nodes)
> > Don't worry about understanding the terminology now we'll get to that later!

Graphs can be ***directed***, where edges have a specific direction from one node to another, or ***undirected***, where edges connect nodes without a defined direction.
Additionally, edges can be ***weighted***, assigning values to represent distances, costs, or other attributes. 
This flexibility makes graphs a powerful tool for representing various real-world scenarios, such as social networks, transportation systems, and computer networks. 

## Contents 
- [Terminologies and definitions](#Terminologies-and-Definitions)
- [Implementing graphs](#Implementing-Graphs)
- [Graphs as ADTs](#Graphs-as-ADTs)
- [Useful videos](#Useful-Videos)
- [Useful articles](#Useful-Articles)
- [For practice](#For-Practice)

---
## Terminologies and Definitions
|                   | definition                                                                                                                                  |
| ----------------- | ------------------------------------------------------------------------------------------------------------------------------------------- |
| Subgraph          | A subgraph consists of a subset of a graph’s vertices and a subset of its edges.                                                            |
| Adjacent Vertices | Any two vertices joined by an edge                                                                                                          |
| Path              | A path between two vertices is a sequence of edges that begins at one vertex and ends at the other one                                      |
| Cycle             | A path that ends at the same vertex it started from                                                                                         |
| Connected Graph   | A graph is connected if each pair of connected vertices has a path between them (you can reach any node from any other node)                |
| Complete Graph    | Each pair of distinct vertices has an edge between them                                                                                     |
| Multigraph        | A graph that allows multiple edges between the same pair of vertices,<br>allowing self edges(loops)                                         |
| Weighted Graph    | Graphs that assign numerical values (weights) to edges. These weights represent some property associated with the connection between nodes. |
| Directed Graph    | Graphs where each edge has a specific direction; meaning data flows in a specific order.                                                    |
| Acyclic Graph     | An acyclic graph is one where you can't follow a path from a node back to itself. (contains no cycles)                                      |
| Sparse Graph      | A graph with relatively few edges compared to the number of vertices.                                                                       |
| Dense Graph       | A graph with many edges compared to the number of vertices.                                                                                 |

>[!NOTE]
> - A *path* may pass through revisit the same vertex once while a *simple path* may not. likewise: the difference between a *cycle* and a *simple cycle* is that the latter doesn't pass through other vertices more than once
> - A *complete graph* is also *connected* but the converse isn't necessarily true

![image](https://github.com/user-attachments/assets/38d8e5dc-62d4-4650-a432-9441899cea31)

---
## Implementing Graphs
The two primary ways to represent graphs are:
1. [Adjacency matrix](#Adjacency-Matrix)
2. [Adjacency list](Adjacency-List)
