#ifndef __MAGICITE_EFFECT_POSITIVE__
#define __MAGICITE_EFFECT_POSITIVE__
#include "MagiciteEffect.h"

///> ����һ��������ǿ
class MagiciteEffectPositive : public MagiciteEffect
{
public:
    virtual void positive(MagiciteGameObject* obj)
    {
        //MagiciteEffectValueChange.positive
    }

    virtual void negative() 
    {
        // �������ɶ
    }

};

#endif //__MAGICITE_EFFECT_POSITIVE__