#pragma once

#include <glob.h>
#include <random>

#include "StateDataStructure.hpp"

class Renderer;

class Grid {
public:
    Grid(int w, int h, Renderer* renderer);
    /**
     * Returns a pointer to the state of the cell at (i; j).
     * It is meant to be used during the generation process (after the State buffers got flipped).
     * @param i Line
     * @param j Column
     * @return Pointer to state
     */
    inline State* getStatePtr(int i, int j){    return prevBuff + ((i % h) * w) + (j % w);  }
    /**
     * Returns the value of the state of the cell (i; j).
     * It is meant to be used during the generation process (after the State buffers got flipped).
     * @param i Line
     * @param j Column
     * @return State value
     */
    inline State getState(int i, int j){    return prevBuff[((i % h) * w) + (j % w)];  }

    /**
     * Performs a whole system iteration and rendering.
     */
    void iterate();

    inline int getWidth(){ return this->w;}
    inline int getHeight(){ return this->h;}

    ~Grid();

private:
    int w, h;

    State* prevBuff;
    State* newBuff;

    Renderer* renderer;

    std::default_random_engine randomer;    //  Fucking great techno producer btw
    std::uniform_real_distribution<double> urd;

    /**
     * Returns the next value for a given cell
     * @param i
     * @param j
     */
    State iterate_cell(int i, int j);

    /**
     * Returns an initial value for the cell (i; j)
     * @param i Line
     * @param j Column
     * @return State value
     */
    State init_cell(int i, int j);
};
