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
            std::set<std::uint32_t> adjacentVertices;

            for(uint32_t j = 0; j < maxEdgesPerVertex; ++j)
            {
                // Create random edges between vertices up to requested max
                uint32_t otherVertex = 0;
                do
                {
                    otherVertex = rand() % numVertices;
                } while (otherVertex == i || adjacentVertices.find(otherVertex) != adjacentVertices.end());
                
                this->graph_.addEdge(i, otherVertex);
                adjacentVertices.insert(otherVertex);
            }
        }
    }

    //----------------------------------------------------
    void GraphGenerator::seedRandom() const
    {
        using namespace std::chrono;
        milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        srand(ms.count());
    }
}