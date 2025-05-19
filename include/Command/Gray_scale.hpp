
#ifndef GRAY_SCALE_HPP
#define GRAY_SCALE_HPP

#include "Command.hpp"


namespace prog {
    namespace command {
        class Gray_scale : public Command {
        public:
            ~Gray_scale();
            Gray_scale();

            Image *apply(Image *img) override;

            std::string toString() const override;

        };
    }
}











#endif //GRAY_SCALE_HPP
