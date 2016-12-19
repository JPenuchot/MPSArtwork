//
// Created by jpenuchot on 11/19/16.
//

#include <cmath>
#include <ctime>
#include <iostream>
#include <random>

#include "Grid.h"
#include "Renderer.h"
#include "CellsBehaviorConstants.h"

void Grid::iterate() {
    int size = this->w * this->h;

    //  Flipping buffers
    State* tmp = this->newBuff;
    this->newBuff = prevBuff;
    this->prevBuff = tmp;

    //  Processing
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) {
            newBuff[i * h + j] = iterate_cell(i, j);
        }
    }

    //  Rendering
    if(this->renderer != nullptr)
        renderer->render(this->newBuff);
}

Grid::Grid(int w, int h, Renderer* renderer):
    w(w),
    h(h),
    renderer(renderer){
    //  Buffer allocation
    this->prevBuff = new State[w * h];
    this->newBuff = new State[w * h];

    this->urd = std::uniform_real_distribution<double>(0.0, 1.1);

    //  Filling buffers for the first time ever (<3)
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            newBuff[i * w + j] = this->init_cell(i, j);
        }
    }

    //  First render, yay
    if(this->renderer != nullptr)
        renderer->render(newBuff);
}

State Grid::iterate_cell(int i, int j) {
    State selfState = (this->getState(i, j));

    switch(selfState.type) {
        case Empty: {
            //  Randomly grow trees depending on a 10*10 neighborhood
            double pTreeSpawn = treeProbInitConst;

            for (int ii = -5; ii < 5; ii++) {
                for (int jj = -5; jj < 5; jj++) {
                    float di = ii, dj = jj;
                    float distFact = (float) std::sqrt(std::pow(di, 2) + std::pow(dj, 2)) * treeProbDistFactor;

                    if (getState(i + ii, j + jj).type == Tree) {
                        pTreeSpawn += treeProbIncr / std::pow(distFact, 2);
                    }
                    if (getState(i + ii, j + jj).type == Fire) {
                        pTreeSpawn -= treeProbFireFactor / std::pow(distFact, 2);
                    }
                }
            }

            //  If our random value falls within the the probability then make it spawn
            if (urd(randomer) < pTreeSpawn) {
                return {Tree, 1};
            }

            return {Empty, 0};
        }
        case Tree: {
            float pFireSpawn = fireProbInitConst;
            for (int ii = -5; ii <= 5; ii++) {
                for (int jj = -5; jj <= 5; jj++) {
                    if (getState(i + ii, j + jj).type == Fire) {
                        float di = ii, dj = jj;
                        float distFact = (float) std::sqrt(std::pow(di, 2) + std::pow(dj, 2)) * fireProbDistFactor;
                        pFireSpawn += fireProbIncr * std::pow(distFact, 2);
                    }
                }
            }
            if (urd(randomer) < pFireSpawn)
                return {Fire, selfState.scale};
            return {Tree, selfState.scale + 1};
        }

        case Fire: {
            //  Lose intensity over time
            if (selfState.scale == 0)
                return {Empty, 0};
            return {Fire, selfState.scale - 1};
        }
    }

    //  Just in case something messed up...
    return {Empty, 0};
}

State Grid::init_cell(int i, int j) {
    return {Empty, 0};
}
