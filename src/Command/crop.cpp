#include"Image.hpp"
#include"Command/crop.hpp"
namespace prog{
    namespace command{
        crop::crop(int x, int y, int w, int h):Command("crop"),x_(x),y_(y),w_(w),h_(h){}
        crop::~crop(){} //destruidor de classe
        Image *crop::apply(Image *img) {
            const Color fill;
            Image* imcp = new Image(w_,h_,fill); //nova imagem, com tamanho desejado
            for (int i = 0; i<w_;i++) {
                for (int l = 0; l<h_;l++) {//loop sobre os pixeis desejados
                    imcp->at(i,l) = img->at(i+x_,l+y_); //Copiamos para a nova imagem todos os pixeis desejados
                }
            }delete img;
            return imcp;}


    }}