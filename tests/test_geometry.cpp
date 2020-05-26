
#include <iostream>
#include "types/geometry/geometry_types.hpp"

using namespace std;
using namespace dxt_common::geometry;
using dxt_common::geometry::operator-;



bool test_geometry_types_definition()
{
    Vector2f v2f;
    Vector3f v3f;
    Vector2d v2d;
    Vector3d v3d;

    cout << "v2f.norm: " << v2f.norm() << endl;
    cout << "v3f.norm: " << v3f.norm() << endl;
    cout << "v2d.norm: " << v2d.norm() << endl;
    cout << "v3d.norm: " << v3d.norm() << endl;


    Point2f pt2f;
    Point3f pt3f;
    Point2d pt2d;
    Point3d pt3d;

    cout << "pt2f.norm: " << pt2f.norm() << endl;
    cout << "pt3f.norm: " << pt3f.norm() << endl;
    cout << "pt2d.norm: " << pt2d.norm() << endl;
    cout << "pt3d.norm: " << pt3d.norm() << endl;


    Position2f p2f;
    Position3f p3f;
    Position2d p2d;
    Position3d p3d;

    cout << "p2f.norm: " << p2f.norm() << endl;
    cout << "p3f.norm: " << p3f.norm() << endl;
    cout << "p2d.norm: " << p2d.norm() << endl;
    cout << "p3d.norm: " << p3d.norm() << endl;

    return true;
}


bool test_geometry_operations()
{
    Position3d p1(-8.0, 0.0, 0.0), p2(8.0, 0.0, 0.0);

    cout << "dist p1 <-> p2: " << (p1 - p2).length() <<endl;

    return true;
}


int main()
{

    test_geometry_types_definition();

    test_geometry_operations();

    return 0;
}