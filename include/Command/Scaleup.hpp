#ifndef SCALEUP_HPP
#define SCALEUP_HPP

#include "Command.hpp"


namespace prog {
    namespace command {

        class Scaleup: public Command {

        public:
            Scaleup(int x_up, int y_up);
            ~Scaleup();
            Image* apply(Image* img) override;

            std::string toString() const override;

        private:
            int xu;
            int yu;

        };

    }
}

#endif //SCALEUP_HPP
