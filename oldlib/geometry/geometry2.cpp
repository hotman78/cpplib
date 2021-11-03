// #include <boost/geometry.hpp>
// #include <boost/geometry/geometries/linestring.hpp>
// #include <boost/geometry/geometries/polygon.hpp>
// #include <boost/geometry/geometries/point_xy.hpp>
// #include <boost/assign/list_of.hpp>
// namespace bg = boost::geometry;
// namespace trans = bg::strategy::transform;
// typedef bg::model::d2::point_xy<double> point;
// typedef boost::geometry::model::segment<point> line;
// typedef bg::model::multi_point<point> mpoint;
// // namespace bg = boost::geometry;
// // namespace trans = bg::strategy::transform;
// // typedef bg::model::d2::point_xy<double> point;
// // typedef boost::geometry::model::segment<point> segment;
// // typedef boost::geometry::model::linestring<point> line;
// // typedef bg::model::polygon<point> polygon;
// // typedef bg::model::multi_point<point> mpoint;
// bool intersects(point a,point b,point c,point d){
//     return bg::intersects(line(a,b),line(c,d));
// }