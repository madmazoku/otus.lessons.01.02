#pragma once

#include "global.h"

struct XY {
    static double sqr(double x) { return x*x; }

    double x;
    double y;

    XY() : x(0), y(0) {}
    XY(const double &xy_) : x(xy_), y(xy_) {}
    XY(const double &x_, const double &y_) : x(x_), y(y_) {}
    XY(const struct XY &xy_) : x(xy_.x), y(xy_.y) {}
    ~XY() {}

    void rand(const struct XY &offset, const struct XY &amplitude) 
    { 
        x = (urd(gen) - 0.5) * amplitude.x * 2.0 + offset.x;
        y = (urd(gen) - 0.5) * amplitude.y + offset.y;
    }
    void rand_angle(const double &amplitude)
    {
        double a = urd(gen) * 2*M_PI;
        double l = amplitude;
        x = l * sin(a);
        y = l * cos(a);
    }

    double dist2(const struct XY &xy_) const
    {
        return sqr(x - xy_.x) + sqr(y - xy_.y);
    }

    double rad2() const
    {
        return sqr(x) + sqr(y);
    }

    double dist(const struct XY &xy_) const
    {
        return sqrt(sqr(x - xy_.x) + sqr(y - xy_.y));
    }

    double rad() const
    {
        return sqrt(sqr(x) + sqr(y));
    }

    XY mul(const double &d) const
    {
        return XY(x*d, y*d);
    }
};

