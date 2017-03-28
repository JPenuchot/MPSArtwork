#pragma once

enum CellType : uint8_t {
    Empty,
    Tree,
    Fire
};
struct State{
    CellType type;
    uint8_t scale;
};
