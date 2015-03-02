#ifndef __MAGICITE_EFFECT_SPEED_UP__
#define __MAGICITE_EFFECT_SPEED_UP__

#include "cocos2d.h"
#include "MagiciteEffectBuffer.h"

class MagiciteGameObject;

class MagiciteEffectSpeedUp : public MagiciteEffectBuffer
{
public:
    MagiciteEffectSpeedUp();

    virtual void positive(MagiciteGameObject* obj);
        //MagiciteEffectValueChange.positive
        //timer-negative

    virtual void negative();
        ///> �������Ҫ��ɶ ����timer��ȡ��Ч��

    static MagiciteEffectSpeedUp* create();
    virtual bool init();


private:
    float                                           _old_speed;
};

#endif //__MAGICITE_EFFECT_SPEED_UP__