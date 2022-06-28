#include <math.h>

class PerlinNoise {
public:
    typedef struct
    {
        float x, y;
    } vector2;
    static float dotProduct(vector2 const& left, vector2 const& right);
    static float perlin(float x, float y);
};