#ifndef ROUTING_TYPES_EDGE_HPP
#define ROUTING_TYPES_EDGE_HPP

#include <stdint.h>
#include <utility>

namespace Routing
{
    //====================================================
    // Represents a directional edge between two vertices
    typedef std::pair<uint32_t, uint32_t> uint32PairType;
    class Edge : protected uint32PairType
    {
        public:
            //----------------------------------------------------
            // Alternate constructor; initializes src and dest data members to user-provided values
            Edge(const uint32_t src, const uint32_t dest);

            //----------------------------------------------------
            // Sets src data member
            void setSrc(const uint32_t src)
            {
                this->first = src;
            }

            //----------------------------------------------------
            // Returns copy of src
            uint32_t getSrc() const
            {
                return this->first;
            }

            //----------------------------------------------------
            // Sets dest data member
            void setDest(const uint32_t dest)
            {
                this->second = dest;
            }

            //----------------------------------------------------
            // Returns copy of dest
            uint32_t getDest() const
            {
                return this->second;
            }

            //----------------------------------------------------
            inline bool operator<(const Edge& rhs) const
            {
                return this->first < rhs.first && this->second < rhs.second;
            }
    };
}

#endif