#include "endpoint.hpp"

namespace Routing
{
    //----------------------------------------------------
    Endpoint::Endpoint(const uint32_t id, const float weight)
    : id_(id),
      weight_(weight)
	{}
}