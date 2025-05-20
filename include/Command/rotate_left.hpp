#include "Command.hpp"
#ifndef ROTATE_LEFT_HPP
#define ROTATE_LEFT_HPP
namespace prog{namespace command{
    class rotate_left:public Command{
    public:
        rotate_left();
        ~rotate_left();
        Image *apply(Image *img) override;

    };}}
#endif //ROTATE_LEFT_HPP