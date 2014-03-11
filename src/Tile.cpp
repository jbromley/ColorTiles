//
//  Tile.cpp
//  ColorTiles
//
//  Created by Jay Bromley on 3/5/14.
//
//

#include "Tile.h"

Tile::Tile(int x, int y, int z, int width, int height, int depth)
    : pos_(x, y, z),
      size_(width, height, depth),
      color_((float) rand() / RAND_MAX, (float) rand() / RAND_MAX, (float) rand() / RAND_MAX),
      alpha_(0.25f), duty_(0.1f), lit_(false)
{
}

void
Tile::update()
{
    if (static_cast<float>(rand()) / RAND_MAX < duty_) {
        lit_ = !lit_;
    }
}

void
Tile::draw()
{
    gl::pushMatrices();
    gl::translate(pos_);
    
    ColorA strokeColor(CM_HSV, color_.x, color_.y, color_.z, alpha_);
    gl::color(strokeColor);
    gl::drawStrokedCube(pos_, size_);
    
    float s = lit_ ? 0.8f : 0.5f;
    ColorA fillColor(CM_HSV, s * color_.x, s * color_.y, s * color_.z, alpha_);
    gl::color(fillColor);
    gl::drawCube(pos_, size_);
    
    gl::popMatrices();
}
