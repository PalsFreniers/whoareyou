#pragma once

#include "utils.h"

//Game signals
#define FULLSCREEN        (1 << 0)
#define VISIBLE           (1 << 1)
#define PAUSED            (1 << 2)
#define CLOSABLE          (1 << 3)
#define RESIZABLE         (1 << 4)
#define CLOSED            (1 << 5)

//Gameobjects signals
#define TEXTURE           (1 << 0)
//efine VISIBLE           (1 << 1)
#define ANIMATION         (1 << 2)
#define UPDATE_EVENT      (1 << 3)
#define COLLIDE_EVENT     (1 << 4)
#define DRAW_EVENT        (1 << 5)
#define MOVE_EVENT        (1 << 6)

//Labels signals
#define BACKGROUND        (1 << 7)
#define TEXT_CHANGE_EVENT (1 << 8)

//buttons signals
#define ACTIVE            (1 << 9)
#define ON_CLICK_EVENT    (1 << 10)
