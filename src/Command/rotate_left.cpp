#include "../../include/Command/rotate_left.hpp"
#include "../../include/Image.hpp"
namespace prog{
    namespace command {
        rotate_left::rotate_left(): Command("rotate_left"){}
        rotate_left::~rotate_left() {}
        Image *rotate_left::apply(Image *img) {const Color fill = {255,255,255};
            Image* imcp = new Image(img->height(),img->width(),fill);
            for (int x = 0; x< img->width(); x++) {
                for (int y = 0; y<img->height();y++) {
                    imcp->at(y,img->width()-1-x) = img->at(x,y);
                }
            }
            delete img;
            return imcp;}
    }
}
