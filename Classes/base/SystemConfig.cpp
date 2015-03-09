#include "SystemConfig.h"

const char* const kxlol::SystemConfig::GetSystemFont()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    return "Microsoft YaHei";
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    return "Droid Sans Fallback";
#endif

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    return "Heiti SC";
#endif

    //������Ŀ��ϵͳ�������ϵļ���ϵͳ���밴�����ϸ�ʽ�������������Ŀ��ϵͳ�Ͷ�Ӧ��Ĭ����������

    //------------------------------------------------------------------------------------------
}
