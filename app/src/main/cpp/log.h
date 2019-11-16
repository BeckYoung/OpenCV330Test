/*
 * log.h
 *
 *  Created on: 2016年11月6日
 *      Author: XHP
 */
#ifndef LOG_TAG
#define LOG_TAG "MyLog"
#include<android/log.h>




#endif /* LOG_TAG */
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
