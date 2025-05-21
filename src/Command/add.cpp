#include "Command/add.hpp"
#include "Color.hpp"
#include "Image.hpp"
#include <sstream>
#include "Command/Open.hpp"
#include "PNG.hpp"

namespace prog {
    namespace command {
        add::add(const std::string& filename, rgb_value r, rgb_value g, rgb_value b, int x, int y) : Command("add"), filename(filename), r(r), g(g), b(b), x(x), y(y) {} //filename não é modificado

        add::~add() {}

        Image* add::apply(Image *img) {
            Image* ref_image = loadFromPNG(filename);

            for (int j = 0; j < ref_image->height(); j++) {
                for (int i = 0; i < ref_image->width(); i++) {
                    const Color& cor = ref_image->at(i,j);
                    if (cor.red() == r && cor.green() == g && cor.blue() == b) continue;

                    if (x + i >= 0  && x + i < img->width() && y+ j >= 0 && y + j < img->height()) {
                        img->at(x+i,y+j) = cor;
                    }
                }
            }
            return img;
        }

        std::string add::toString() const {
            std::ostringstream ss;
            ss << name() << "filename:" << filename << " r:" << r << " g:" << g << " b:" << b << "x:" << x << "y:" << y;
            return ss.str();
        }
    }
}