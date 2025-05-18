#include "Image.hpp"

namespace prog {
    Image::Image(int w, int h, const Color &fill) {
        this-> w = w;
        this-> h = h;
        this-> pixels.assign (w*h,fill); // (number of pixels, type(cor))
    }

    Image::~Image() {
    }

    int Image::width() const {
        return w;
    }

    int Image::height() const {
        return h;
    }

    Color &Image::at(int x, int y) {
		return pixels[w*(y) + x]; // (w = line) * (h_specific = y - 1 + 1) + (rest = x)
    }

    const Color &Image::at(int x, int y) const {
        return pixels[w*(y) + x];
    }

    void Image::set(int x, int y, const Color& c) {
        pixels[y * width()+x] =c;   // definir a cor de um pixel específico

    }
}
