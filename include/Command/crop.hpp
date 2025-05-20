#ifndef CROP_HPP
#define CROP_HPP

#include "Command.hpp"

namespace prog{
    namespace command{
        class crop:public Command{
        public:
            crop(int x, int y, int w, int h);
            ~crop();
            Image *apply(Image *img) override;
        private:
            int x_;
            int y_;
            int w_;
            int h_;
        };
    }
}
#endif //CROP_HPP


