package com.myway;

import android.content.res.AssetManager;

public class Framework {
	
	static {
		System.loadLibrary("MCore");
		System.loadLibrary("MGui");
		System.loadLibrary("MParticleFX");
		System.loadLibrary("MPhysics");
		System.loadLibrary("GLRenderSystem");
		System.loadLibrary("SLAudioSystem");
		
		System.loadLibrary("Demo01_Empty");
	}
	
	public static native void OnInit(AssetManager pAssetManager, String cachePath, int w, int h);
	public static native void OnShutdown();
	public static native void OnRun();
	public static native void OnResume();
	public static native void OnPause();
	public static native void OnResize(int w, int h);
	
	public static native void OnActionDown(int id, float x, float y);
	public static native void OnActionUp(int id, float x, float y);
	public static native void OnActionMove(int id, float x, float y);
	public static native void OnActionCancel(int id, float x, float y);
	
	public static native void OnInsertText(String text);
	public static native void OnDeleteBackword();
}
