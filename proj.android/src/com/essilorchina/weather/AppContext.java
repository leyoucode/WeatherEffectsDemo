package com.essilorchina.weather;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InvalidClassException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Properties;
import java.util.UUID;

import android.app.Application;
import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager.NameNotFoundException;
import android.util.Log;
import android.widget.Toast;

/** 
 * @description:
 *
 * @author: Liu wei
 * 
 * @mail: i@liuwei.co
 * 
 * @date: 2014-3-12
 */
public class AppContext extends Application {
	
	protected final String LOG_TAG = this.getClass().getSimpleName();

	public static AppContext mInstance;
	
	@Override
	public void onCreate(){
		super.onCreate();
		mInstance = this;
	}
	
	public static AppContext getInstance(){
		return mInstance;
	}
	
}
