#pragma once

#include "Actor.hpp"
#include "Psx.hpp"
#include "Kmd.hpp"

struct Prim_unknown;

struct Actor_Debug
{
    Actor mBase;
    Prim_unknown_0x54* mPrimData;
    POLY_F4 mPolyF4;
};

Actor_Debug* AddDebugActor();
