//
// Created by jpenuchot on 11/19/16.
//

#ifndef MPSARTWORK_RENDERER_H
#define MPSARTWORK_RENDERER_H

#include <glob.h>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "StateDataStructure.h"

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


#endif //MPSARTWORK_RENDERER_H
