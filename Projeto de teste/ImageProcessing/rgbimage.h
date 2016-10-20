#ifndef RGBIMAGE_H
#define RGBIMAGE_H

#include "ImageProcessing/imageprocessing.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

namespace ImageProcessing {
    template <class Type>
    class RGBImage
    {
        public:
            RGBImage(){}
            RGBImage(const LinAlg::Matrix<Type> &r, const LinAlg::Matrix<Type> &g, const LinAlg::Matrix<Type> &b);
            ~RGBImage();

            LinAlg::Matrix<Type> getRed()   const {return this->red;}
            LinAlg::Matrix<Type> getGreen() const {return this->green;}
            LinAlg::Matrix<Type> getBlue()  const {return this->blue;}
            LinAlg::Matrix<Type> getRGB()   const {return this->rgb;}


            unsigned getWidth() const {return this->width;}
            unsigned getHeight()const {return this->height;}

        private:
            LinAlg::Matrix<Type> red,green,blue,rgb;
            unsigned height, width, a;
    };

    template <class Type>
    ImageProcessing::RGBImage<Type> QImage2RGBImage(const QImage &img); //ok
    template <class Type>
    LinAlg::Matrix<Type> HistogramRGB(const ImageProcessing::RGBImage<Type> &rgbimg); //ok
    template <class Type>
    LinAlg::Matrix<int> GetPixel(const LinAlg::Matrix<Type> &r,
                                const LinAlg::Matrix<Type> &g,
                                const LinAlg::Matrix<Type> &b); //not ok
}
#include "ImageProcessing/rgbimage.hpp"
#endif // RGBIMAGE_H