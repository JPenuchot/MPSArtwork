#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "Grid.h"
#include "Renderer.h"

int main() {
    Grid grid(100, 100, new Renderer(100, 100, &grid));

    for(int i = 0; i < 10000; i++) {
        grid.iterate();
        std::cout << "Frame #" << i << std::endl;
        cv::waitKey(0);
    }
}