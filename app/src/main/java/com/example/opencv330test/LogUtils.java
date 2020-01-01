package com.example.opencv330test;

import android.util.Log;

public final class LogUtils {
    public static void i(String tag, Object... objects) {
        String msg = getMessage(objects);
        Log.i(tag, msg);
    }

    public static void d(String tag, Object... objects) {
        String msg = getMessage(objects);
        Log.d(tag, msg);
    }

    public static void v(String tag, Object... objects) {
        String msg = getMessage(objects);
        Log.v(tag, msg);
    }

    public static void e(String tag, Object... objects) {
        String msg = getMessage(objects);
        Log.e(tag, msg);
    }

    private static String getMessage(Object... objects) {
        StringBuilder stringBuilder = new StringBuilder();
        for (Object obj : objects) {
            stringBuilder.append(obj);
        }
        return stringBuilder.toString();
    }
}
