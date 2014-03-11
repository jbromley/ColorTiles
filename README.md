Color Tiles
===========

Description
-----------

This project creates a cubic lattice of tiles that can take on various
colors. The colors then are subjected to flocking forces such that
tiles near each other in the lattice affect where in the color space
each tile is travelling.

Tasks
-----

* Create a container class for the tiles that can return tiles in the
  neighborhood of a given tile.
* Have tiles position themselves.
* Implement separation, alignment, and cohesion in the HSV color
  space.
* Accept a frame from a camera, average the colors over each tile and
  then run the color flocking from that point.
* Implement pan, rotate, and zoom using normal mouse controls.

