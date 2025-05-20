#include"Image.hpp"
#include"Command/crop.hpp"
namespace prog{
    namespace command{
        crop::crop(int x, int y, int w, int h):Command("crop"),x_(x),y_(y),w_(w),h_(h){}
        crop::~crop(){}
        Image *crop::apply(Image *img) {
            const Color fill;
            Image* imcp = new Image(w_,h_,fill);
            for (int i = 0; i<w_;i++) {
                for (int l = 0; l<h_;l++) {
                    imcp->at(i,l) = img->at(i+x_,l+y_);
                }
            }delete img;
            return imcp;}


    }}