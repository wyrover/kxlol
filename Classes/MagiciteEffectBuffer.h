#pragma once
#include "MagiciteEffect.h"

///> ����һ��buffer���ı�ĳЩ���Ժ󣬶�ʱ�����Ļ���
class MagiciteEffectBuffer : public MagiciteEffect
{
public:
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
