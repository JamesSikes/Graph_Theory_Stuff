#ifndef ROUTING_ENDPOINT_HPP
#define ROUTING_ENDPOINT_HPP

#include <stdint.h>

namespace Routing
{
    //====================================================
    // Represents the endpoint of a directional edge (i.e. the destination)
    class Endpoint
    {
        public:
            //----------------------------------------------------
            // Alternate constructor
            Endpoint(const uint32_t id, const float weight = 1.0);

            //----------------------------------------------------
            // Sets the endpoint id
            void setId(const uint32_t id)
            {
                this->id_ = id;
            }

            //----------------------------------------------------
            // Returns the endpoint id
            uint32_t getId() const
            {
                return this->id_;
            }

            //----------------------------------------------------
            // Sets the endpoint weight
            void setWeight(const uint32_t weight)
            {
                this->weight_ = weight;
            }

            //----------------------------------------------------
            // Returns the endpoint weight
            float getWeight() const
            {
                return this->weight_;
            }

            //----------------------------------------------------
            // Compares two endpoints by id
            inline bool operator<(const Endpoint& rhs) const
            {
                return this->id_ < rhs.id_;
            }

        private:
            uint32_t id_;
            float weight_;
    };
}

#endif