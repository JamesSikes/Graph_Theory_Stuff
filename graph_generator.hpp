#ifndef ROUTING_GRAPH_GENERATOR_HPP
#define ROUTING_GRAPH_GENERATOR_HPP

#include "graph.hpp"
#include <stdint.h>

namespace Routing
{
    //====================================================
    class GraphGenerator
    {
        public:
            //----------------------------------------------------
            // Generates a graph that has vertices equal to @numVertices with each vertex having
            // edges less than or equal to @maxEdgesPerVertex
            void generateGraph(const uint32_t numVertices, const uint32_t maxEdgesPerVertex);

            //----------------------------------------------------
            // Returns read-only reference to graph
            const Graph& getGraph() const
            {
                return this->graph_;
            }

        private:
            //----------------------------------------------------
            // Seeds random number generator so that edges between vertices are random
            void seedRandom() const;

            Graph graph_;
    };
}

#endif