//
// Created by beck on 2017/11/1.
//
//#ifdef __cplusplus
//
//extern "C" {
//#endif
//
//#ifdef __cplusplus
//}
//#endif
#ifndef OPENCVTEST3_NATIVE_LIB_HPP
#define OPENCVTEST3_NATIVE_LIB_HPP
#include <jni.h>
/*
 * C++语言在编译的时候为了解决函数的多态问题，会将函数名和参数联合起来生成一个中间的函数名称，
 * 而C语言则不会，因此会造成链接时找不到对应函数的情况，此时C函数就需要用extern "C"进行链接指定，
 * 这告诉编译器，请保持我的名称，不要给我生成用于链接的中间函数名；exter "C"{jni代码}
 */
extern "C" {
JNIEXPORT jstring JNICALL
Java_com_example_opencv330test_NDKUtils_stringFromJNI(
        JNIEnv *env,
        jclass jc);

JNIEXPORT jintArray JNICALL
Java_com_example_opencv330test_NDKUtils_gray(JNIEnv *env, jclass type, jintArray buff_, jint w,
                                        jint h);
}
#endif //OPENCVTEST3_NATIVE_LIB_HPP
