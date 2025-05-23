#include"Command/v_mirror.hpp"
#include"Image.hpp"
namespace prog{
    namespace command{
        v_mirror::v_mirror():Command("v_mirror"){}
        v_mirror::~v_mirror(){}//destruidor de classe
        Image* v_mirror::apply(Image *img){
            for (int x=0; x< img->width(); x++){
                for (int y=0; y< img-> height()/2; y++){//loop para fazer a simetria vertical
                    Color temp = img->at(x,y);
                    img->at(x,y) = img->at(x,img->height()-y-1);
                    img->at(x,img->height()-y-1) = temp;//swap nas cores
                }
            }
            return img;}
    }
}