#include "graph_generator.hpp"
#include <set>
#include <stdlib.h>
#include <chrono>

namespace Routing
{
    //----------------------------------------------------
    void GraphGenerator::generateGraph(const uint32_t numVertices, const uint32_t maxEdgesPerVertex)
    {
        this->seedRandom();
        
        // Loop through all vertices
        for(uint32_t i = 0; i < numVertices; ++i)
        {
            // Tracks adjacent (connected) vertices so that we don't duplicate edges
            std::set<std::uint32_t> adjacentVertices;

            // Randomly create the max number of edges for this vertex
            for(uint32_t j = 0; j < maxEdgesPerVertex; ++j)
            {
                uint32_t otherVertex = 0;
                do
                {
                    otherVertex = rand() % numVertices;
                } while (otherVertex == i || adjacentVertices.find(otherVertex) != adjacentVertices.end());
                
                // Create a unique edge
                this->graph_.addEdge(i, otherVertex);
                adjacentVertices.insert(otherVertex);
            }
        }
    }

    //----------------------------------------------------
    void GraphGenerator::seedRandom() const
    {
        const std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch());
        srand(ms.count());
    }
}