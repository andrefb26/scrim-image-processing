#ifndef FILL_HPP
#define FILL_HPP
#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Fill : public Command {
        public:
            Fill(int x, int y, int w, int h, rgb_value r, rgb_value g, rgb_value b);

            ~Fill();

            Image* apply(Image* img) override;

            std::string toString() const override;

        private:
            int x;
            int y;
            int w;
            int h;
            rgb_value r;
            rgb_value g;
            rgb_value b;
        };
    }
}
#endif //FILL_HPP
