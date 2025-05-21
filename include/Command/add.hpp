#ifndef ADD_HPP
#define ADD_HPP

#include "Command.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include <string>

namespace prog {
    namespace command {
        class add : public Command {
        public:
            add(const std::string& filename, rgb_value r, rgb_value g, rgb_value b, int x, int y);

            ~add();

            Image* apply(Image* img) override;

            std::string toString() const override;

        private:
            std::string filename;
            rgb_value r,g,b;
            int x, y;
        };
    }
}
#endif //ADD_HPP