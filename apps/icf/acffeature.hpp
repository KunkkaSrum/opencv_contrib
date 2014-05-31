/*

By downloading, copying, installing or using the software you agree to this
license. If you do not agree to this license, do not download, install,
copy or use the software.


                          License Agreement
               For Open Source Computer Vision Library
                       (3-clause BSD License)

Copyright (C) 2013, OpenCV Foundation, all rights reserved.
Third party copyrights are property of their respective owners.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  * Neither the names of the copyright holders nor the names of the contributors
    may be used to endorse or promote products derived from this software
    without specific prior written permission.

This software is provided by the copyright holders and contributors "as is" and
any express or implied warranties, including, but not limited to, the implied
warranties of merchantability and fitness for a particular purpose are
disclaimed. In no event shall copyright holders or contributors be liable for
any direct, indirect, incidental, special, exemplary, or consequential damages
(including, but not limited to, procurement of substitute goods or services;
loss of use, data, or profits; or business interruption) however caused
and on any theory of liability, whether in contract, strict liability,
or tort (including negligence or otherwise) arising in any way out of
the use of this software, even if advised of the possibility of such damage.

*/

#ifndef __OPENCV_ADAS_ACFFEATURE_HPP__
#define __OPENCV_ADAS_ACFFEATURE_HPP__

namespace cv
{
namespace adas
{

/* Compute channel pyramid for acf features

    image — image, for which pyramid should be computed

    params — pyramid computing parameters

Returns vector of computed channels
*/
std::vector<Mat>
computeChannels(const Mat& image);

class ACFFeatureEvaluator
{
public:
    /* Construct evaluator, set features to evaluate */
    ACFFeatureEvaluator(const std::vector<Point>& features);

    /* Set channels for feature evaluation */
    void setChannels(const std::vector<Mat>& channels);

    /* Set window position */
    void setPosition(Size position);

    /* Evaluate feature with given index for current channels
        and window position */
    int evaluate(size_t feature_ind) const;

    /* Evaluate all features for current channels and window position

    Returns matrix-column of features
    */
    Mat evaluateAll() const;

private:
    /* Features to evaluate */
    std::vector<Point> features_;
    /* Channels for feature evaluation */
    std::vector<Mat> channels;
    /* Channels window position */
    Size position_;
};

/* Generate acf features

    window_size — size of window in which features should be evaluated

    count — number of features to generate.
    Max number of features is min(count, # possible distinct features)

    seed — random number generator initializer

Returns vector of distinct acf features
*/
std::vector<Point>
generateFeatures(Size window_size, size_t count = UINT_MAX, int seed = 0);

} /* namespace adas */
} /* namespace cv */

#endif /* __OPENCV_ADAS_ACFFEATURE_HPP__ */
