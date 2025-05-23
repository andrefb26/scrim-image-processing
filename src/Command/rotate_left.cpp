#include "../../include/Command/rotate_left.hpp"
#include "../../include/Image.hpp"
namespace prog{
    namespace command {
        rotate_left::rotate_left(): Command("rotate_left"){}
        rotate_left::~rotate_left() {} //destruidor de classe
        Image *rotate_left::apply(Image *img) {const Color fill = {255,255,255};
            Image* imcp = new Image(img->height(),img->width(),fill); //Inicializar uma imagem nova
            for (int x = 0; x< img->width(); x++) {
                for (int y = 0; y<img->height();y++) { //percorrer os pixeis da imagem
                    imcp->at(y,img->width()-1-x) = img->at(x,y); // aplicar a função que traduz a mudança de posição dos pixeis
                }
            }
            delete img;
            return imcp;}
    }
}
