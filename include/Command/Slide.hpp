#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "Command.hpp"


namespace prog {
    namespace command {
        class Slide: public Command {
        public:
            Slide(int x_move, int y_move);
            Image* apply(Image* img) override;
            std::string toString() const override;
            ~Slide();

        private:
            int xs;
            int ys;
        };
    }
}






#endif //SLIDE_HPP
