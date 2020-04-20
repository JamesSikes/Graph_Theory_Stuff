#ifndef ROUTING_GRAPH_HPP
#define ROUTING_GRAPH_HPP

#include "endpoint.hpp"
#include <stdint.h>
#include <set>
#include <map>
#include <string>

namespace Routing
{
    //====================================================
    class Graph
    {
        public:
            // Collection of all vertices in the graph
            typedef std::set<uint32_t> VerticesType;

            // Collection of all directional edges in the graph
            typedef std::map<uint32_t, std::set<Endpoint> > EdgesType;

            //----------------------------------------------------
            // Adds a directional src/dest edge to the graph. Adds vertex entries for src and
            // dest if they don't already exist
            void addEdge(const uint32_t src, const uint32_t dest);

            //----------------------------------------------------
            // Removes the directional src/dest edge from the graph
            void removeEdge(const uint32_t src, const uint32_t dest);

            //----------------------------------------------------
            // Removes the vertex and all its edges from the graph
            void removeVertex(const uint32_t vertex);

            //----------------------------------------------------
            // Returns the string representation of the graph
            std::string toString() const;

            //----------------------------------------------------
            // Returns read-only reference to this graph's vertices
            const VerticesType& getVertices() const
            {
                return this->vertices_;
            }

            //----------------------------------------------------
            // Returns read-only reference to this graph's edges
            const EdgesType& getEdges() const
            {
                return this->edges_;
            }

        private:
            VerticesType vertices_;
            EdgesType edges_;
    };
}

#endif