#include "Command/Fill.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace  command {
        Fill::Fill(int x, int y, int w, int h, rgb_value r, rgb_value g, rgb_value b) : Command("fill"), x(x), y(y), w(w), h(h), r(r), g(g), b(b) {}

        Fill::~Fill() {}

        Image* Fill::apply(Image* img) {
            Color c= {r,g,b};
            for (int j = y; j < y + h; j++) {
                for (int i = x; i < x + w; i++) {

                    img->at(i,j)=c;
                }
            }
            return img;
        }

        std::string Fill::toString() const {
            std::ostringstream ss;
            ss << name() << "x:" << x << "y:" << y << " w:" << w << " h:" << h << " r:" << r << " g:" << g << " b:" << b;
            return ss.str();
        }

    }
}
