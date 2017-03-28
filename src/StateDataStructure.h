//
// Created by jpenuchot on 11/19/16.
//

#ifndef MPSARTWORK_DATASTRUCTURES_H
#define MPSARTWORK_DATASTRUCTURES_H

enum CellType : uint8_t {
    Empty,
    Tree,
    Fire
};
struct State{
    CellType type;
    uint8_t scale;
};

#endif //MPSARTWORK_DATASTRUCTURES_H
