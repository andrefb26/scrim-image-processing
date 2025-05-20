#include "Command/rotate_right.hpp"
#include "Image.hpp"
namespace prog{namespace command {
    rotate_right::rotate_right():Command("rotate_right"){}
    rotate_right::~rotate_right() {}
    Image *rotate_right::apply(Image *img) {
        const Color fill = {255,255,255};
        Image* imcp = new Image(img->height(),img->width(),fill);
        for (int x = 0; x< img->width(); x++) {
            for (int y = 0; y<img->height();y++) {
                imcp->at(img->height()-1-y,x) = img->at(x,y);
            }
        }delete img;
        return imcp;}
}
}

