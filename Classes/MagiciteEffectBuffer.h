#pragma once
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
