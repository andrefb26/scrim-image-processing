#include "Color.hpp"
#include "Image.hpp"
#include "Command/Move.hpp"
#include <sstream>



namespace prog {
    namespace command {
        Move::~Move(){}; //destruidor de classe
        Move::Move(int x_move, int y_move): Command("move"), xm(x_move), ym(y_move) {}
        Image *Move::apply(Image *img) {
            Image* img_new= new Image (img->width(), img->height(), Color(255,255,255)); //cria uma nova imagem com os parâmetros da original
            if (xm>=0 && ym>=0) {
                // garante que os valores de offset são válidos

                for (int y=0; y<img->height()-ym;y++) {
                    for (int x=0; x<img->width()-xm;x++) {//percorre todos os pixéis da imagem
                        //calcula as coordenadas do píxel após ser movido
                        int new_x = x+xm;
                        int new_y = y+ym;
                        if ( new_x < img->width() && new_y<img->height()) {
                            img_new->at(new_x, new_y)= img->at(x,y);//se a nova posição do píxel estiver dentro dos limites da imagem, escreve-lo na nova imagem
                        }
                    }
                }

            }
            return img_new;
        }

        //imprimir uma representação em texto do comando Fill com todos os seus parâmetros
        std::string Move::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << xm << " y:" << ym;
            return ss.str();
        }

    }
}
