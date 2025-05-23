#include "Image.hpp"
#include "Command/Resize.hpp"
namespace prog{
    namespace command{
        Resize::Resize(int x,int y,int w,int h):Command("resize"),x_(x),y_(y),w_(w),h_(h){}
        Resize::~Resize(){} //destruidor de classe
        Image *Resize::apply(Image *img) {const Color fill = {255,255,255};
            Image* imcp = new Image(w_,h_,fill); //Nova imagem com tamanho desejado
            for (int i = x_; i <img->width()  ; i++) {
                for (int l = y_; l<img->height();l++) {//loop sobre os pixeis para copiar
                    imcp->at(i-x_,l-y_)=img->at(i,l); //copiar todos os pixeis desejados para a imagem

                }
            }//Os pixeis restantes serão brancos
            delete img;return imcp;}

    }
}