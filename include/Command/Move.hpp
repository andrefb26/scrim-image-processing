#ifndef MOVE_HPP
#define MOVE_HPP

#include "Command.hpp"

namespace prog {
    namespace command {
        class Move: public Command {
        public:
            Move(int x_move, int y_move);
            Image* apply(Image* img) override;
            std::string toString() const override;
            ~Move();

        private:
            int xm;
            int ym;
        };
    }
}

#endif //MOVE_HPP
