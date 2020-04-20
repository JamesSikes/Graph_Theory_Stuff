#include "graph.hpp"
#include <sstream>
#include <iomanip>

namespace Routing
{
    //----------------------------------------------------
    void Graph::addEdge(const uint32_t src, const uint32_t dest)
    {
        this->vertices_.insert(src);
        this->vertices_.insert(dest);
        this->edges_[src].insert(Endpoint(dest));
    }

    //----------------------------------------------------
    void Graph::removeEdge(const uint32_t src, const uint32_t dest)
    {
        this->edges_[src].erase(Endpoint(dest));
    }

    //----------------------------------------------------
    void Graph::removeVertex(const uint32_t vertex)
    {
        this->vertices_.erase(vertex);
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
        // First row: all vertices
        auto it = this->vertices_.begin();
        // Leave initial row blank so we get a conventional matrix representation
        oss << std::setw(w*2) << *it;
        for(++it; it != this->vertices_.end(); ++it)
        {
            oss << std::setw(w) << *it;
        }

        // Subsequent rows: each vertex and its adjacency to other vertices (1 if adjacent; 0 if not)
        for(auto it = this->vertices_.begin(); it != this->vertices_.end(); ++it)
        {
            oss << "\n" << std::setw(w) << *it;
            for(auto it2 = this->vertices_.begin(); it2 != this->vertices_.end(); ++it2)
            {
                // Find source vertex in edge map
                auto srcIt = this->edges_.find(*it);
                if(srcIt != this->edges_.end())
                {
                    // Found it. Look for an edge to the adjacent vertex
                    if(srcIt->second.find(*it2) != srcIt->second.end())
                    {
                        oss << std::setw(w) << "1";
                    }
                    else
                    {
                        oss << std::setw(w) << "0";
                    }
                }
            }
        }

        return oss.str();
    }
}