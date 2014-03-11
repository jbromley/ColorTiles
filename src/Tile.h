//
//  Tile.h
//  ColorTiles
//
//  Created by Jay Bromley on 3/5/14.
//
//

#ifndef __ColorTiles__Tile__
#define __ColorTiles__Tile__

#include <iostream>
#include "cinder/gl/gl.h"

using namespace ci;

class Tile {
public:
    Tile(int x, int y, int z, int width, int height, int depth);
    void update();
    void draw();
    
private:
    int width_;
    int height_;
    int depth_;
    Vec3f pos_;
    Vec3f size_;
    Vec3f color_;
    float alpha_;
    float duty_;
    bool lit_;
};

#endif /* defined(__ColorTiles__Tile__) */
