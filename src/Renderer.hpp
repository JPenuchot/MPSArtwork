#pragma once

#include <glob.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "StateDataStructure.hpp"

class Grid;

class Renderer {
public:
    Renderer(size_t w, size_t h, Grid*);
    ~Renderer();
    void render(State* stateBuff);
private:
    Grid* grid;
    cv::VideoWriter vr;
    size_t w, h;
    cv::Mat img;
};
