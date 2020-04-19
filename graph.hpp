#ifndef ROUTING_TYPES_GRAPH_HPP
#define ROUTING_TYPES_GRAPH_HPP

#include "edge.hpp"
#include <map>
#include <set>
#include <string>

namespace Routing
{
    //====================================================
    class Graph
    {
        public:
            typedef std::map<uint32_t, std::set<uint32_t> > edgesType;

            //----------------------------------------------------
            // Adds a directional src/dest edge to the graph. A vertex entry for src is added if it // does not already exist
            void addEdge(const uint32_t src, const uint32_t dest);

            //----------------------------------------------------
            // Removes the src/dest edge from the graph
            void removeEdge(const uint32_t src, const uint32_t dest);

            //----------------------------------------------------
            // Removes the vertex and all its edges from the graph
            void removeVertex(const uint32_t vertex);

            //----------------------------------------------------
            // Returns the string representation of the graph
            std::string toString() const;

            //----------------------------------------------------
            // Returns read-only reference to this graph's edges
            const edgesType& getEdges() const
            {
                return this->edges_;
            }

        private:
            edgesType edges_;
    };
}

#endif