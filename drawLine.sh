#!/bin/bash

g++ Main.cpp Commoncodes.cpp DDA.cpp Midpoint.cpp Randomized.cpp Symmetry.cpp Boxes.cpp userdefined.h -o LineDrawing -lglut -lGLU -lGL
./LineDrawing