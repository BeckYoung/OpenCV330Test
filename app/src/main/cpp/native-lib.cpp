#include "native-lib.hpp"
#include <string>
#include "first.h"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

JNIEXPORT jstring JNICALL
Java_com_example_opencv330test_NDKUtils_stringFromJNI(
        JNIEnv *env,
        jclass jc) {
    string hello = "Hello from C++";
    print();
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jintArray JNICALL
Java_com_example_opencv330test_NDKUtils_gray(JNIEnv *env, jclass type, jintArray buff_, jint w,
                                           jint h) {
    jint *buff = env->GetIntArrayElements(buff_, NULL);

    // TODO
    if (buff == NULL) {
        return 0;
    }

    Mat imgData(h, w, CV_8UC4, (unsigned char *) buff);

    uchar *ptr = imgData.ptr(0);
    for (int i = 0; i < w * h; i++) {
        //计算公式：Y(亮度) = 0.299*R + 0.587*G + 0.114*B
        //对于一个int四字节，其彩色值存储方式为：BGRA
        int grayScale = (int) (ptr[4 * i + 2] * 0.299 + ptr[4 * i + 1] * 0.587 +
                               ptr[4 * i + 0] * 0.114);
        ptr[4 * i + 1] = grayScale;
        ptr[4 * i + 2] = grayScale;
        ptr[4 * i + 0] = grayScale;
    }

    int size = w * h;
    jintArray result = env->NewIntArray(size);
    env->SetIntArrayRegion(result, 0, size, buff);
    env->ReleaseIntArrayElements(buff_, buff, 0);
    return result;
}