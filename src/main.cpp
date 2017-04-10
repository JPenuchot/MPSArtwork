#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include "Grid.hpp"
#include "Renderer.hpp"

int main() {
    Grid grid(160, 90, new Renderer(160, 90, &grid));

    for(int i = 0; i < 54000; i++) {
        grid.iterate();
        std::cout << "Frame #" << i << std::endl;
    }
}