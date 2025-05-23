#ifndef CHAIN_HPP
#define CHAIN_HPP

#include <string>
#include <vector>
#include "Image.hpp"
#include "Command.hpp"




namespace prog {
    namespace command {
        class Chain: public Command{
        public:
            Image* apply(Image* img) override;
            Chain(const std::vector<std::string>& file_list);
        private:
            static std::vector<std::string> hist;
            std::vector<std::string> files;
        };
    }
}
#endif //CHAIN_HPP
