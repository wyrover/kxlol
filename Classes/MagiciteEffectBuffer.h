#ifndef __MAGICITE_EFFECT_BUFER__
#define __MAGICITE_EFFECT_BUFER__

#include "MagiciteEffect.h"
#include "MagiciteGameTagManager.h"

///> ����һ��buffer���ı�ĳЩ���Ժ󣬶�ʱ�����Ļ���
class MagiciteEffectBuffer : public MagiciteEffect
{
public:

    enum Buff_Type : int
    {
        Speed_Up = MagiciteGameTagManager::Speed_Up_Tag,
        Jump_High = MagiciteGameTagManager::Jump_High_Tag,
        Sprint_Tag = MagiciteGameTagManager::Sprint_Tag,
    };

    virtual void positive() 
    {
        //MagiciteEffectValueChange.positive
        //timer-negative
    }

    virtual void negative() 
    {
        ///> �������Ҫ��ɶ ����timer��ȡ��Ч��
    }

};

#endif //__MAGICITE_EFFECT_BUFER__