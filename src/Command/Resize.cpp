#include "Image.hpp"
#include "Command/Resize.hpp"
namespace prog{
    namespace command{
        Resize::Resize(int x,int y,int w,int h):Command("resize"),x_(x),y_(y),w_(w),h_(h){}
        Resize::~Resize(){}
        Image *Resize::apply(Image *img) {const Color fill = {255,255,255};
            Image* imcp = new Image(w_,h_,fill);
            for (int i = x_; i <img->width()  ; i++) {
                for (int l = y_; l<img->height();l++) {
                    imcp->at(i-x_,l-y_)=img->at(i,l);

                }
            }
            delete img;return imcp;}

    }
}