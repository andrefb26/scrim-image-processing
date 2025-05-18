#include "Color.hpp"
#include "Image.hpp"
#include "Command/Replace.hpp"

namespace prog {
    namespace command {
        Replace:: Replace(const Color& c1, const Color& c2): Command("replace"), col1(c1), col2(c2) {}

        Image *Replace::apply(Image *img) {

            for (int y=0; y<img->height();y++) {
                for (int x=0; x<img->width();x++) {//percorre todos os pixéis da imagem
                    Color col= img->at(x,y); //obtém a cor de cada pixel
                    if (col1.red()==col.red() && col1.green()==col.green() && col1.blue()==col.blue()) { // compara os parâmetros rgb da cor 1 e da cor do pixel
                        img->set(x,y,col2); // se as cores forem iguais, substitui a cor do pixel por cor 2
                    }
                }
            }
            return img;
        }
        std::string Replace::toString() const {
            return "replace";
        }



    }
}
