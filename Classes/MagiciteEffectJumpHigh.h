#ifndef __MAGICITE_EFFECT_JUMPHIGH__
#define __MAGICITE_EFFECT_JUMPHIGH__

#include "cocos2d.h"
#include "MagiciteEffectBuffer.h"
#include "MagiciteGameMoveAbleLiving.h"

class MagiciteEffectJumpHigh : public MagiciteEffectBuffer
{
public:
    MagiciteEffectJumpHigh();

    virtual void positive();
    //MagiciteEffectValueChange.positive
    //timer-negative

    virtual void negative();
    ///> �������Ҫ��ɶ ����timer��ȡ��Ч��

    static MagiciteEffectJumpHigh* create(MagiciteGameMoveAbleLiving* moveable);
    virtual bool init(MagiciteGameMoveAbleLiving* moveable);

private:
    MagiciteGameMoveAbleLiving*                     _moveable;
};

#endif //__MAGICITE_EFFECT_JUMPHIGH__