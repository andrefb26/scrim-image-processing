#ifndef CHAIN_HPP
#define CHAIN_HPP

#include "Command.hpp"
#include "Image.hpp"
#include <string>
#include <vector>

namespace prog {
    namespace command {
        class Chain: public Command{
        public:
            Image* apply(Image* img) override;
            Chain(const )
        }
    }
}
#endif //CHAIN_HPP
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////