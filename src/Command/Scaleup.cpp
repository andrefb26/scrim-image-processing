#include "Image.hpp"
#include "Color.hpp"
#include "Command/Scaleup.hpp"
#include <sstream>

namespace prog{
    namespace command{
        Scaleup::Scaleup(int x_up,int y_up):Command("scaleup"),xu(x_up),yu(y_up){}
        Scaleup::~Scaleup(){}
        Image *Scaleup::apply(Image *img) {
            Image* new_img=new Image (img->width()*xu,img->height()*yu, Color(255,255,255));

            for (int x = 0; x <img->width()  ; x++) {
                for (int y = 0; y<img->height();y++) {
                    Color c= img->at(x,y);

                    for (int x1 = 0; x1 <xu; x1++) {
                        for (int y1 = 0; y1<yu;y1++) {
                            int pos_x=x*xu + x1;
                            int pos_y=y*yu + y1;
                            new_img->set(pos_x,pos_y, c);


                        }
                    }
                }
            }

            return new_img;

        }
        std::string Scaleup::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << xu << " y:" << yu;
            return ss.str();
        }

    }
}



