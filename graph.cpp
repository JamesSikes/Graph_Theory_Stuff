#include "graph.hpp"
#include <sstream>
#include <iomanip>

namespace Routing
{
    //----------------------------------------------------
    void Graph::addEdge(const uint32_t src, const uint32_t dest)
    {
        this->edges_[src].insert(dest);
    }

    //----------------------------------------------------
    void Graph::removeEdge(const uint32_t src, const uint32_t dest)
    {
        edgesType::iterator srcIt = this->edges_.find(src);
        if(srcIt != this->edges_.end())
        {
            srcIt->second.erase(dest); //Remove the edge
        }
    }

    //----------------------------------------------------
    void Graph::removeVertex(const uint32_t vertex)
    {
        for(edgesType::iterator srcIt = this->edges_.begin(); srcIt != this->edges_.end(); ++srcIt)
        {
            // Remove all edges involving vertex
            srcIt->second.erase(vertex);
        }

        // Remove the vertex
        this->edges_.erase(vertex);
    }

    //----------------------------------------------------
    std::string Graph::toString() const
    {
        std::ostringstream oss;

        // Determine appropriate width to separate numbers
        std::uint32_t w = 1, temp = this->edges_.size();
        while(temp)
        {
            temp /= 10; //Remove next significant digit
            ++w; //Keep track of digits removed
        }

        // Creating an adjacency matrix
        //
        // First row is all vertices
        auto srcIt = this->edges_.begin();
        oss << std::setw(w*2) << srcIt->first; //Offset initial row so we get a conventional matrix representation
        for(++srcIt; srcIt != this->edges_.end(); ++srcIt)
        {
            oss << std::setw(w) << srcIt->first;
        }

        // Subsequent rows are each vertex and it's adjacency to other vertices (1 if adjacent; 0 if not)
        for(auto it = this->edges_.begin(); it != this->edges_.end(); ++it)
        {
            oss << "\n" << std::setw(w) << it->first;
            for(auto it2 = this->edges_.begin(); it2 != this->edges_.end(); ++it2)
            {
                if(it->second.find(it2->first) != it->second.end())
                {
                    oss << std::setw(w) << "1";
                }
                else
                {
                    oss << std::setw(w) << "0";
                }
            }
        }

        return oss.str();
    }
}