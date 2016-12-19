//
// Created by jpenuchot on 11/19/16.
//

#include <iostream>

#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

#include "Renderer.h"
#include "Grid.h"

using namespace cv;

void Renderer::render(State *stateBuff) {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            State st = grid->getState(i, j);
            uchar *col = (img.data + ((i * w + j) * img.elemSize()));
            switch (st.type) {
                case Empty: {
                    col[2] = 0;
                    col[1] = 0;
                    col[0] = 0;
                    break;
                }
                case Tree: {
                    col[2] = 0xff;
                    col[1] = 0x99;
                    col[0] = 0xcc;
                    break;
                }
                case Fire: {
                    col[2] = 0xff;
                    col[1] = 0xff;
                    col[0] = 0xff;
                    break;
                }
                default: {
                    col[2] = 0;
                    col[1] = 0;
                    col[0] = 0;
                    break;
                }
            }
        }
    }

    cv::imshow("Rendu", this->img);
    //vr.write(this->img);
}

Renderer::Renderer(size_t w, size_t h, Grid* grid):
w(w),
h(h),
grid(grid){
    this->img = cv::Mat(h, w, CV_8UC3);
    namedWindow("Rendu", CV_WINDOW_NORMAL | CV_WINDOW_KEEPRATIO | CV_GUI_EXPANDED);
    //this->vr = VideoWriter("render.avi", CV_FOURCC('X', '2', '6', '4'), 60., CvSize(h, w));
}

Renderer::~Renderer() {

}
