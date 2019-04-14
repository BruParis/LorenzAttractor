#include <opencv2/viz/vizcore.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void updatePoint(Point3f& point, float time_delta, float sigma, float rho,
    float beta)
{
    float dx = time_delta * sigma * (point.y - point.x);
    float dy = time_delta * (rho * point.x - point.y - point.x * point.z);
    float dz = time_delta * (point.x * point.y - beta * point.z);

    Point3f diff(dx, dy, dz);
    point += diff;
}

int main()
{
    /// Create a window
    viz::Viz3d myWindow("Coordinate Frame");

    myWindow.setBackgroundColor(viz::Color::black(), viz::Color::not_set());

    /// Add coordinate axes
    myWindow.showWidget("Coordinate Widget", viz::WCoordinateSystem());

    std::vector<Point3f> points;
    std::vector<Point3f> colors;

    /// Rodrigues vector
    Point3f point(1.0, 3.0, 1.0);
    float sigma = 10., rho = 28., beta = 8. / 3.;
    float time = 0.0, time_delta = 0.01;

    while(!myWindow.wasStopped())
    {
        updatePoint(point, time_delta, sigma, rho, beta);
        points.push_back(point);

        time += time_delta;

        viz::WPaintedCloud cloud_widget = viz::WPaintedCloud( points );
        cloud_widget.setRenderingProperty(viz::POINT_SIZE, 1);

        myWindow.showWidget( "Depth", cloud_widget );

        myWindow.spinOnce(1, true);
    }

    return 0;
}
