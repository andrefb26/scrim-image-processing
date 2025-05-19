
#include "Color.hpp"
#include "Image.hpp"
#include "Command/Invert.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Invert::Invert(): Command("invert"){}
        Invert::~Invert() {};


        Image* Invert::apply(Image* img) {
            for (int y=0; y<img->height();y++) {
                for (int x=0; x<img->width();x++) {  //percorre todos os pixéis da imagem
                    Color col= img->at(x,y); //obtém a cor de cada pixel
                    Color inv(255-col.red(), 255-col.green(), 255-col.blue()); // obtém a cor invertida
                    img->set(x,y,inv); //define cor nova
                }
            }
            return img;
        }
        std::string Invert::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}
