#include"Command.hpp"
#ifndef H_MIRROR_HPP
#define H_MIRROR_HPP
namespace prog{
    namespace command{
        class h_mirror:public Command{
        public:
            h_mirror();
            ~h_mirror();
            Image *apply(Image *img) override;
        };
    }
}
#endif //H_MIRROR_HPP