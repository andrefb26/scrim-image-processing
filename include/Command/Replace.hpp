#ifndef REPLACE_HPP
#define REPLACE_HPP

#include "Command.hpp"


namespace prog {
    namespace command {

        class Replace: public Command {
        public:
            Replace(rgb_value r1, rgb_value g1, rgb_value b1, rgb_value r2, rgb_value g2, rgb_value b2);
            Image* apply(Image* img) override;
            std::string toString() const override;
            ~Replace();

        private:
            rgb_value r1;
            rgb_value g1;
            rgb_value b1;
            rgb_value r2;
            rgb_value g2;
            rgb_value b2;
        };
    }
}




#endif //REPLACE_HPP
