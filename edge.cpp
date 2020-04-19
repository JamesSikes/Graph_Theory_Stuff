#include "edge.hpp"

namespace Routing
{
    //----------------------------------------------------
    Edge::Edge(const uint32_t src, const uint32_t dest)
    : uint32PairType(src, dest)
	{}
}