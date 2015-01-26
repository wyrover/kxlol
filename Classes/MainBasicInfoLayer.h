#ifndef __MAIN_BASIC_INFO_LAYER_H__
#define __MAIN_BASIC_INFO_LAYER_H__

#include "cocos2d.h"
#include <Component\slot.h>

class MainBasicInfoLayer : public cocos2d::Layer
{
private:
	kxlol::component::slot slot;

	float _totalTime;		//ͳ��ʱ��ͣ���������ֵ
public:
    virtual bool init();
	virtual void onEnter();
	virtual void update(float delta);
	virtual void onExit();

    CREATE_FUNC(MainBasicInfoLayer);
};

#endif // __MAIN_BASIC_INFO_LAYER_H__
