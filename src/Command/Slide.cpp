#include "../../include/Color.hpp"
#include "../../include/Image.hpp"
#include "../../include/Command/SLide.hpp"
#include <sstream>


namespace prog {
    namespace command {
        Slide::~Slide(){};
        Slide::Slide(int x_slide, int y_slide): Command("slide"), xs(x_slide), ys(y_slide) {}
        Image *Slide::apply(Image *img) {
            Image* img_new= new Image (img->width(), img->height(), Color(255,255,255));
            if (xs>=0 && ys>=0) {
                // garante que os valores de offset são válidos

                for (int y=0; y<img->height();y++) {
                    for (int x=0; x<img->width();x++) {//percorre todos os pixéis da imagem
                        //calcula as coordenadas do píxel após ser movido
                        int new_x = (x+xs)%img->width();
                        int new_y = (y+ys)%img->height();

                        img_new->at(new_x, new_y)= img->at(x,y); //altera a cor do pixel na nova imagem

                    }
                }

            }
            return img_new;
        }

        //imprimir uma representação em texto do comando Slide com todos os seus parâmetros
        std::string Slide::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << xs << " y:" << ys;
            return ss.str();
        }

    }
}