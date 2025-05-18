#ifndef REPLACE_HPP
#define REPLACE_HPP

#include "Command.hpp"


namespace prog {
    namespace command {

        class Replace: public Command {
        public:
            Replace(const Color& c1, const Color& c2);
            Image* apply(Image* img) override;
            std::string toString() const override;

        private:
            Color col1;
            Color col2;
        };
    }
}




#endif //REPLACE_HPP
