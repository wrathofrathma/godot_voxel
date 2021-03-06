#ifndef RANGE_UTILITY_H
#define RANGE_UTILITY_H

#include "../../math/interval.h"

class Curve;
class OpenSimplexNoise;
class Image;
class FastNoiseLite;
class FastNoiseLiteGradient;

Interval get_osn_range_2d(OpenSimplexNoise *noise, Interval x, Interval y);
Interval get_osn_range_3d(OpenSimplexNoise *noise, Interval x, Interval y, Interval z);

Interval get_curve_range(Curve &curve, bool &is_monotonic_increasing);

Interval get_heightmap_range(Image &im);
Interval get_heightmap_range(Image &im, Rect2i rect);

struct Interval2 {
	Interval x;
	Interval y;
};

struct Interval3 {
	Interval x;
	Interval y;
	Interval z;
};

Interval get_fnl_range_2d(const FastNoiseLite *noise, Interval x, Interval y);
Interval get_fnl_range_3d(const FastNoiseLite *noise, Interval x, Interval y, Interval z);
Interval2 get_fnl_gradient_range_2d(const FastNoiseLiteGradient *noise, Interval x, Interval y);
Interval3 get_fnl_gradient_range_3d(const FastNoiseLiteGradient *noise, Interval x, Interval y, Interval z);

#ifdef DEBUG_ENABLED
namespace NoiseTests {

void test_noises();

} // namespace NoiseTests
#endif

#endif // RANGE_UTILITY_H
