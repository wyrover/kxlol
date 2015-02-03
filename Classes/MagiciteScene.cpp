#include "MagiciteScene.h"
int MagiciteScene::LevelNumber = 0;

USING_NS_CC;

bool MagiciteScene::init(int level)
{
    if ( !Scene::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    LevelNumber = level;

	auto dic = Dictionary::createWithContentsOfFile("text/story.plist");
	auto str = dynamic_cast<String*>(dic->objectForKey("story_1"));

	auto lblStory = LabelBMFont::create(str->getCString(), "fonts/Chinese.fnt"); //::createWithBMFont("fonts/Chinese.fnt",  str->getCString());
	lblStory->setWidth(visibleSize.width - 100);
	lblStory->setAnchorPoint(Vec2(0.5, 0.5));
	lblStory->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	this->addChild(lblStory);
	lblStory->setOpacity(0);

	Vector<FiniteTimeAction*> actions;
	actions.pushBack(FadeIn::create(0.3));
	actions.pushBack(DelayTime::create(str->length() * 0.02));
	actions.pushBack(FadeOut::create(0.2));
	actions.pushBack(CallFunc::create([&](){
        this->addChild(MagiciteGameLayer::create());
	}));
	lblStory->runAction(Sequence::create(actions));
    
    return true;    
}

MagiciteScene* MagiciteScene::create(int level)
{
    auto ptr = new MagiciteScene();
    if (ptr && ptr->init(level))
    {
        ptr->autorelease();
        return ptr;
    }
    else
    {
        CC_SAFE_DELETE(ptr);
        return nullptr;
    }
}