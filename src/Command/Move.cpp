#include "Color.hpp"
#include "Image.hpp"
#include "Command/Move.hpp"
#include <sstream>



namespace prog {
    namespace command {
        Move::~Move(){};
        Move::Move(int x_move, int y_move): Command("move"), xm(x_move), ym(y_move) {}
        Image *Move::apply(Image *img) {
            Image* img_new= new Image (img->width(), img->height(), Color(255,255,255));
            if (xm>=0 && ym>=0) {
                // garantir que os valores dos pixeis são positivos


                for (int y=0; y<img->height()-ym;y++) {
                    for (int x=0; x<img->width()-xm;x++) {//percorre todos os pixéis da imagem
                        int new_x = x+xm;
                        int new_y = y+ym;
                        if ( new_x < img->width() && new_y<img->height()) {
                            img_new->at(new_x, new_y)= img->at(x,y);
                        }
                    }
                }

            }
            return img_new;
        }
                std::string Move::toString() const {
                    std::ostringstream ss;
                    ss << name() << " x:" << xm << " y:" << ym;
                    return ss.str();
                }

    }
}
