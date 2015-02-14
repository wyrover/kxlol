#ifndef __MAGICITE_GAME_EFFECT_SPEED_UP__
#define __MAGICITE_GAME_EFFECT_SPEED_UP__

#include "cocos2d.h"
#include "MagiciteGameMoveAbleLiving.h"
#include "MagiciteEffectBuffer.h"

class MagiciteEffectSpeenUp : public MagiciteEffectBuffer
{
public:
    MagiciteEffectSpeenUp(MagiciteGameMoveAbleLiving* moveable);

    virtual void positive();
        //MagiciteEffectValueChange.positive
        //timer-negative

    virtual void negative();
        ///> �������Ҫ��ɶ ����timer��ȡ��Ч��
private:
    MagiciteGameMoveAbleLiving*                     _moveable;
};

#endif //__MAGICITE_GAME_EFFECT_SPEED_UP__