// Copyright 2020 DriveX.Tech. All rights reserved.
// 
// Licensed under the License.

#pragma once
#ifndef _GEOMETRY_TYPES_HPP_
#define _GEOMETRY_TYPES_HPP_

#include <math.h>
#include <stdint.h>
#include <stddef.h>



namespace dxt_common
{

namespace geometry
{

template<class T, int Dim>
class VectorBase
{
public:
    inline void set_constant(T val) {
        for(auto i = 0U; i < Dim; i++) {
            data[i] = val;
        }
    }

    inline void set_zero() {
        set_constant(T(0));
    }

    inline T operator()(int index) const {
        assert(index >= 0);
#ifndef NDEBUG
        assert(index >= 0 && index < Dim)
#endif
        return data[index];
    }

    inline T& operator()(int index) {
        assert(index >= 0);
#ifndef NDEBUG
        assert(index >= 0 && index < Dim)
#endif
        return data[index];
    }

    inline T operator[](int index) const {
        assert(index >= 0);
        return data[index];
    }

    inline T& operator[](int index ) {
        assert(index >= 0);
        return data[index];
    }

    inline VectorBase& operator-() {
        for(auto i = 0U; i < Dim; i++) {
            data[i] = -data[i];
        }
        return *this;
    }

    inline VectorBase& operator+=(const VectorBase& v) {
        for(auto i = 0U; i < Dim; i++) {
            data[i] += v.data[i];
        }
        return *this;
    }

    inline VectorBase& operator-=(const VectorBase& v) {
        for(auto i = 0U; i < Dim; i++) {
            data[i] -= v.data[i];
        }
        return *this;
    }

    inline VectorBase& operator*=(T s) {
        for(auto i = 0U; i < Dim; i++) {
            data[i] *= s;
        }
        return *this;
    }

    inline VectorBase& operator/=(T s) {
        for(auto i = 0U; i < Dim; i++) {
            data[i] /= s;
        }
        return *this;
    }

    inline T dot(const VectorBase& v) const {
        T sum2 = T(0);
        for(auto i = 0U; i < Dim; i++) {
            sum2 += data[i] * v.data[i];
        }
        return sum2;
    }

    // inline friend T dot(const VectorBase& v1, const VectorBase& v2);

    T norm() const {
        return sqrt(this->dot(*this));
    }

    T length() const {
        return sqrt(this->dot(*this));
    }

protected:
    T data[Dim];
};



template<class T, int Dim>
class Vector: public VectorBase<T, Dim>
{
public:
    inline Vector() {
        set_zero();
    }

    inline Vector(const Vector& v) {
        for(auto i = 0U; i < Dim; i++) {
            data[i] = v.data[i];
        }
    }

    inline Vector& operator=(const Vector& v) {
        for(auto i = 0U; i < Dim; i++) {
            data[i] = v.data[i];
        }

        return *this;
    }

    inline static Vector zero() {
        Vector v;
        v.set_zero();
        return v;
    }


    // inline friend Vector operator-(const Vector& v);
    // inline friend Vector operator+(const Vector& v1,const Vector& v2);
    // inline friend Vector operator-(const Vector& v1,const Vector& v2);
    // inline friend Vector operator*(const Vector& v, T s);
    // inline friend Vector operator*(T s, const Vector& v);
    // inline friend Vector operator/(const Vector& v, T s);
};


template<class T>
class Vector<T, 2>: public VectorBase<T, 2>
{
public:
    inline Vector() {
        set_zero();
    }

    inline Vector(T x, T y) {
        data[0] = x;
        data[1] = y;
    }

    inline Vector(const Vector& v) {
        for(auto i = 0U; i < Dim; i++) {
            data[i] = v.data[i];
        }
    }

    inline Vector& operator=(const Vector& v) {
        for(auto i = 0U; i < Dim; i++) {
            data[i] = v.data[i];
        }

        return *this;
    }

    inline static Vector zero() {
        Vector v;
        v.set_zero();
        return v;
    }

    inline T x() const {
        return data[0];
    }
    inline T y() const {
        return data[1];
    }
    inline T& x() {
        return data[0];
    }
    inline T& y() {
        return data[1];
    }
};

template<class T>
class Vector<T, 3>: public VectorBase<T, 3>
{
public:
    inline Vector() {
        set_zero();
    }

    inline Vector(T x, T y, T z) {
        data[0] = x;
        data[1] = y;
        data[2] = z;
    }

    inline Vector(const Vector& v) {
        for(auto i = 0U; i < Dim; i++) {
            data[i] = v.data[i];
        }
    }

    inline Vector& operator=(const Vector& v) {
        for(auto i = 0U; i < Dim; i++) {
            data[i] = v.data[i];
        }

        return *this;
    }

    inline static Vector zero() {
        Vector v;
        v.set_zero();
        return v;
    }

    inline T x() const {
        return data[0];
    }
    inline T y() const {
        return data[1];
    }
    inline T z() const {
        return data[2];
    }
    inline T& x() {
        return data[0];
    }
    inline T& y() {
        return data[1];
    }
    inline T& z() {
        return data[2];
    }
};



// Alias for Point, Position

template<class T, int Dim>
using Point = Vector<T, Dim>;

template<class T, int Dim>
using Position = Vector<T, Dim>;



// Alias for common types
template<class T>
using Vector2 = Vector<T, 2>;
template<class T>
using Vector3 = Vector<T, 3>;

template<class T>
using Point2 = Point<T, 2>;
template<class T>
using Point3 = Point<T, 3>;

template<class T>
using Position2 = Position<T, 2>;
template<class T>
using Position3 = Position<T, 3>;



// Alias for small dim
typedef Vector2<float> Vector2f;
typedef Vector2<double> Vector2d;

typedef Vector3<float> Vector3f;
typedef Vector3<double> Vector3d;


typedef Point2<float> Point2f;
typedef Point2<double> Point2d;

typedef Point3<float> Point3f;
typedef Point3<double> Point3d;


typedef Position2<float> Position2f;
typedef Position2<double> Position2d;

typedef Position3<float> Position3f;
typedef Position3<double> Position3d;


}

}


#endif