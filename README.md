# C++ Graph Library

A C++ object-oriented graph library built with Visual Studio 2022. It provides directed and undirected graph data structures with full CRUD operations, graph inversion, and file-based graph loading.

## Authors

- **Nassim BELLANAYA** ([@cNassim](https://github.com/cNassim))
- **EL YAZID GUERMA**

## Project Structure

```
C++Projet/
├── CGraphe.h/.cpp          # Abstract base class for graphs
├── CGraphOrient.h/.cpp     # Directed graph (oriented)
├── CGraph.h/.cpp           # Undirected graph (non-oriented), extends CGraphOrient
├── CGraphNonOrient.h/.cpp  # Alternative non-oriented graph class
├── CSommet.h/.cpp          # Vertex (node) class
├── CArc.h/.cpp             # Arc (edge) class
├── CException.h/.cpp       # Custom exception class
├── C++Projet.cpp           # Main entry point / demo
└── graph.txt               # Sample graph file
```

## Features

- **Create** directed and undirected graph objects
- **Add / Modify / Delete** vertices
- **Add / Modify / Delete** arcs/edges
- **Display** a graph in the console
- **Reverse** a single arc
- **Reverse** an entire graph (all arcs inverted)
- **Load** a graph from a text file

## Class Overview

| Class | Description |
|---|---|
| `CGraphe<T>` | Abstract base class defining the graph interface |
| `CGraphOrient<T>` | Directed graph with vertices and arcs |
| `CGraph<T>` | Undirected graph (extends `CGraphOrient`) |
| `CSommet<T>` | Vertex with lists of incoming and outgoing arcs |
| `CArc<T>` | Arc connecting two vertices (start → end) |
| `CException` | Custom exception with an error code |

## Graph File Format

Graphs can be loaded from a text file using the following format:

```
NBSommets=3
NBArcs=3
Sommets=[ 
Numero=1 
Numero=2 
Numero=3 
]
Arcs=[ 
Debut=1, Fin=2 
Debut=2, Fin=3 
Debut=3, Fin=1 
]
```

## Building the Project

### Requirements

- Visual Studio 2017 or later (solution targets VS 2022)
- C++11 or later

### Steps

1. Open `C++Projet.sln` in Visual Studio.
2. Select the desired configuration (`Debug` or `Release`) and platform (`x86` or `x64`).
3. Build the solution (**Build → Build Solution** or `Ctrl+Shift+B`).

## Running the Program

The program accepts an optional command-line argument for the graph file path.

**With a file argument:**
```
C++Projet.exe graph.txt
```

**Without arguments (interactive mode):**
```
C++Projet.exe
```
You will be prompted to enter the file path manually.

The program will load the graph, display it, then display its inverse (all arcs reversed).

## Usage Example

```cpp
#include "CGraphOrient.h"

// Load a graph from a file
CGraphOrient<int>* graph = CGraphOrient<int>::CGraphOLireFichier("graph.txt");

// Display the graph
graph->CGraphOAfficher();

// Get the inverse graph (all arcs reversed)
CGraphOrient<int>* inverse = graph->CGraphOInverse();
inverse->CGraphOAfficher();

// Clean up
delete graph;
delete inverse;
```
