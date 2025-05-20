#include "Image.hpp"
#include "Command/Scaleup.hpp"
namespace prog{
    namespace command{
        Scaleup::Scaleup(int x_up,int y_up):Command("scaleup"),xu(x_up),yu(y_up){}
        Scaleup::~Scaleup(){}
        Image *Scaleup::apply(Image *img) {
            Image* new_img= img;
            new_img->width()= xu+img->width();

        }

    }
}