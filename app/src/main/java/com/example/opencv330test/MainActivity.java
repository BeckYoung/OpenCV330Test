package com.example.opencv330test;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.widget.ImageView;
import android.widget.TextView;

import org.opencv.android.OpenCVLoader;
import org.opencv.android.Utils;
import org.opencv.core.Mat;
import org.opencv.imgproc.Imgproc;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView tv_string = findViewById(R.id.tv_string);
        tv_string.setText(NDKUtils.stringFromJNI());
        final ImageView iv_img = findViewById(R.id.iv_img);
        new AsyncTask<Void, Void, Bitmap>() {

            @Override
            protected Bitmap doInBackground(Void... voids) {
                Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.mipmap.timg);
                int w = bitmap.getWidth(), h = bitmap.getHeight();
                int[] pix = new int[w * h];
                bitmap.getPixels(pix, 0, w, 0, 0, w, h);
                int[] resultPixes = NDKUtils.gray(pix, w, h);
                Bitmap result = Bitmap.createBitmap(w, h, Bitmap.Config.RGB_565);
                result.setPixels(resultPixes, 0, w, 0, 0, w, h);
                return result;
            }

            @Override
            protected void onPostExecute(Bitmap bitmap) {
                super.onPostExecute(bitmap);
                iv_img.setImageBitmap(bitmap);
            }
        }.execute();
        ImageView iv_img3 = findViewById(R.id.iv_img3);
        if (OpenCVLoader.initDebug()) {
            Bitmap bitmap = BitmapFactory.decodeResource(getResources(), R.mipmap.timg);
            Mat src = new Mat();
            Mat dst = new Mat();
            Utils.bitmapToMat(bitmap, src);
            Imgproc.cvtColor(src, dst, Imgproc.COLOR_BGR2GRAY);
            Utils.matToBitmap(dst, bitmap);
            iv_img3.setImageBitmap(bitmap);
            src.release();
            dst.release();
        } else {
            Log.w(TAG, "could not load OpenCV Libraries");
        }
    }
}
