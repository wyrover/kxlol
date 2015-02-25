#ifndef __MAGICITE_EFFECT_SPRINT__
#define __MAGICITE_EFFECT_SPRINT__

#include "cocos2d.h"
#include "MagiciteEffectBuffer.h"
#include "MagiciteGameMoveAbleLiving.h"

class MagiciteEffectSprint :public MagiciteEffectBuffer
{
public:
    MagiciteEffectSprint();

    static const int sprint_speed_seed = 3;

    static const int time = 3;

    virtual void positive();

    virtual void negative();

    static MagiciteEffectSprint* create(MagiciteGameMoveAbleLiving* moveable);
    virtual bool init(MagiciteGameMoveAbleLiving* moveable);
private:
    MagiciteGameMoveAbleLiving*                         _moveable;
    float                                               _sprint_speed;
    float                                               _base_sprint_speed;
};

#endif //__MAGICITE_EFFECT_SPRINT__