#ifndef __MAGICITE_EFFECT_VALUE_CHANGE__
#define __MAGICITE_EFFECT_VALUE_CHANGE__

#include "MagiciteEffect.h"

class MagiciteEffectValueChange : public MagiciteEffect
{
public:
    virtual void positive(MagiciteGameObject* obj)
    {
        ///> �������������������
    }

    virtual void negative() 
    {
        ///> ��ô����Ǽ���������
    }

};

#endif //__MAGICITE_EFFECT_VALUE_CHANGE__