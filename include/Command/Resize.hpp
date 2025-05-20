#include"Command.hpp"
#ifndef RESIZE_HPP
#define RESIZE_HPP
namespace prog{
    namespace command{
        class Resize:public Command{
        public:
            Resize(int x, int y, int w, int h);
            ~Resize();
            Image *apply(Image *img) override;
        private:
            int x_;
            int y_;
            int w_;
            int h_;

        };}}
#endif //RESIZE_HPP