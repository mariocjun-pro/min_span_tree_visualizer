# Minimum Spanning Tree Algorithm Visualizer 🌴

A C++ project to visualize how two of the most common minimum spanning tree (MST) algorithms work - mainly Kruskal's and Prim's. The application allows the user to randomly generate a tree structure or to import one from a file, and then select which algorithm to use to find the MST. Helpful playback functionality is implemented so that the user can visually see step by step how the algorithms arrive at the final solution. User has the ability to step through the algorithm solving process step by step, or select a playback speed and watch it work it's magic.  

![Recording 2023-05-13 at 19 01 42](https://github.com/Blargian/min_span_tree_visualizer/assets/41984034/344fafeb-de47-4439-8cb9-1e994d5e3912)

The project was inspired by the following two youtube videos, which I thought would be fun to try implement myself in C++:

[Prim's Algorithm Animation](https://www.youtube.com/watch?v=wpV1wvHqyuY&t=62s)

[Kruskal's Algorithm Animation](https://www.youtube.com/watch?v=o8Sqm1_3BRo)

## Technologies 

- C++ 
- CMake
- Dear ImGui 
- Catch2 

## About Minimum Spanning Trees

In computer science, a graph is a collection of nodes which are connected together by edges, which have some associated weighting. In practical terms a weight might give the edge between two nodes some physical meaning such as distance in meters, time in hours or cost in dollars. A tree is a graph without cycles. i.e) constructed in such a way that there is no path of edges that can be followed which which will allow you to arrive back at the same node you left from. A spanning tree is therefore a subgraph of some graph which "spans", or connects, all the vertices of the graph. This spanning tree can also be a 'minimum' spanning tree (MST) when it is selected in such a way as to select edges which have a minimum weight when summed. It turns out that MSTs are pretty useful in many optimization problems, and in actual fact the first MST algorithm was discovered while designing an electricity network for the city of Moravia.  [^1]

Whilst the first algorithm to be discovered for solving this problem was invented by Czech mathematician Otakar Borůvka, the two most popular algorithms today are Prim's and Kruskal's which are examples of [greedy algorithms](https://en.wikipedia.org/wiki/Greedy_algorithm) that work in slightly different ways. 

### 🌳 Prim's Algorithm 

Prim's algorithm is a greedy-algorithm which constructs the MST one edge at a time by examining all outgoing edges from some starting node, and adding the edge with lowest weight to the MST. In this way the MST is built successively until all edges have been explored. 

<img src="https://github.com/Blargian/min_span_tree_visualizer/assets/41984034/e65e5708-f02e-4450-a558-f1df3bc9951e" width="50%" height="50%"/>

### 🌲 Kruskal's Algorithm

In the same way that Prim's algorithm builds the MST one edge at a time, Kruskal's algorithm also does so, however it does so by starting off with a number of disjoint sets of edges between nodes and successively joins the sets together by edges of least weight until there is only one remaining set of edges which is the MST. 

<img src="https://github.com/Blargian/min_span_tree_visualizer/assets/41984034/3d5caaeb-fd4f-471a-bb57-92416da3c67c" width="50%" height="50%"/>

### 🎄 Chazelle's Algorithm (coming soon)

Chazelle's algorithm is an almost linear time algorithm for finding an MST. 

[^1]: [O jistém problému minimálním (On a certain minimal problem)](https://www.sciencedirect.com/science/article/pii/S0012365X00002247?via%3Dihub)

## Local development guide Windows

`git clone` the repository to your local machine. 

Next, `cd lib` and add download Catch2 by running the following command:

`git clone https://github.com/catchorg/Catch2.git`

`cd ..` back up to the root directory. There you'll need to run:

`git clone https://github.com/Microsoft/vcpkg.git`

Once done, `cd` to the vcpkg folder and run: 

`./bootstrap-vcpkg.sh` 

Finally, run:

`./vcpkg integrate install`

You can now open the folder in visual studio. Open up the CMakeLists.txt file, `ctrl + save` and the project should compile. 

There are two executables which can be run. To run the main project select `min_span_tree_visualizer.exe` or to run the test suite select `tests.exe`

![Different executables](https://user-images.githubusercontent.com/41984034/224997758-9a8e42b5-bfa5-47cb-82f5-29a08713ca00.png)

