#include"Command/h_mirror.hpp"
#include"Image.hpp"



namespace prog{
    namespace command{
        h_mirror::h_mirror():Command("h_mirror"){}
        h_mirror::~h_mirror(){} //destruidor de classe
        Image* h_mirror::apply(Image *img){
            for (int x=0; x< img->width()/2; x++){
                for (int y=0; y< img-> height(); y++){//loop para fazer a simetria horizontal
                    Color temp = img->at(x,y);
                    img->at(x,y) = img->at(img->width()-x-1,y);
                    img->at(img->width()-x-1,y) = temp;//swap nas cores
                }
            }
            return img;}
    }
}

