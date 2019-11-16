package com.example.opencv330test;

import android.util.Log;

/**opencv jni
 * Created by xWX481052 on 2017/9/29.
 */

public class NDKUtils {
    private static final String TAG = "NDKUtils";
    public static native int[] gray(int[] buff,int w,int h );
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public static native String stringFromJNI();
    static {
        try {
            System.loadLibrary("native-lib");
        } catch (UnsatisfiedLinkError e) {
            Log.e(TAG, "native-lib UnsatisfiedLinkError");
        }
    }
}
