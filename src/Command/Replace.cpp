#include "Color.hpp"
#include "Image.hpp"
#include "Command/Replace.hpp"
#include <sstream>

namespace prog {
    namespace command {
        Replace:: Replace(rgb_value r1, rgb_value g1, rgb_value b1, rgb_value r2, rgb_value g2, rgb_value b2): Command("replace"), r1(r1), g1(g1), b1(b1), r2(r2), g2(g2), b2(b2) {}
        Replace::~Replace() {};

        Image *Replace::apply(Image *img) {

            for (int y=0; y<img->height();y++) {
                for (int x=0; x<img->width();x++) {//percorre todos os pixéis da imagem
                    Color col= img->at(x,y); //obtém a cor de cada pixel
                    if (r1==col.red() && g1==col.green() && b1==col.blue()) { // compara os parâmetros rgb da cor 1 e da cor do pixel
                        Color new_color= {r2,g2,b2};
                        img->set(x,y,new_color);// se as cores forem iguais, substitui a cor do pixel por cor 2

                    }
                }
            }
            return img;
        }
        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " r1:" << r1 << " g1:" << g1 << " b1:" << b1 << " r2:" << r2 << " g2:" << g2 << " b2:" << b2;
            return ss.str();
        }



    }
}
