#include <iostream>
#include "graph_generator.hpp"

int main()
{
    std::cout << "Routing main !" << std::endl;

    Routing::GraphGenerator graphGen;
    graphGen.generateGraph(8, 2);
    
    std::cout << "Adjacency Matrix:\n" << graphGen.getGraph().toString() << std::endl;

    return 0;
}