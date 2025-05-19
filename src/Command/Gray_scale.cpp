#include "../../include/Color.hpp"
#include "../../include/Image.hpp"
#include "../../include/Command/Gray_scale.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Gray_scale::~Gray_scale(){};

        Gray_scale::Gray_scale(): Command("to_gray_scale"){}

        Image* Gray_scale::apply(Image* img) {
            for (int y=0; y<img->height();y++) {
                for (int x=0; x<img->width();x++) {  //percorre todos os pixéis da imagem
                    Color col= img->at(x,y); //obtém a cor de cada pixel
                    int v= (col.red()+col.green()+col.blue())/3;
                    Color gray_s(v,v,v);
                    img->set(x,y,gray_s);

                }
            }
            return img;
        }
        std::string Gray_scale::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}
