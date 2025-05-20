#ifndef ROTATE_RIGHT_HPP
#define ROTATE_RIGHT_HPP
#include "../Command.hpp"
namespace prog{namespace command{
    class rotate_right:public Command{
    public:
        rotate_right();
        ~rotate_right();
        Image *apply(Image *img) override;

    };}}
#endif //ROTATE_RIGHT_HPP