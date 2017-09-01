#ifndef FRAMES_H
#define FRAMES_H
#include "linkList.h"
int allocateFrame(List *frame);
int freeFrame(List *frame, int frameNumber);
#endif
