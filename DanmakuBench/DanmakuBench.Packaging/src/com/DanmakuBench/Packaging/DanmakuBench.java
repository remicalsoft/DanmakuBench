package com.DanmakuBench.Packaging;

import android.app.NativeActivity;
import android.os.Bundle;
import android.widget.EditText;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.view.View;
import java.lang.Runnable;
import android.widget.Toast;
import android.content.ClipData;
import android.content.ClipDescription;
import android.content.ClipboardManager;
import android.os.Build;
import android.content.Intent;
import android.net.Uri;
import android.os.PowerManager;
import android.os.PowerManager.WakeLock;
import android.content.Context;

public class DanmakuBench extends NativeActivity
{
	/*
	NativeActivity AppActivity ;
	AlertDialog.Builder AlBuilder ;
	WakeLock _lock;

	@Override
	protected void onResume(){
		super.onResume();
		PowerManager pm = (PowerManager)getSystemService(Context.POWER_SERVICE); 
		_lock = pm.newWakeLock(PowerManager.SCREEN_DIM_WAKE_LOCK, "My tag"); 
		_lock.acquire();
	}

	@Override
	protected void onPause(){
		super.onPause();
		_lock.release();
	}
	*/

	public void showScoreDialog()
	{
		/*
		// NativeActivity の参照をメンバー変数に保存しておく
		AppActivity = this ;

		// UIスレッドで実行する処理を登録する
		runOnUiThread( new Runnable ()
		{
			// UIスレッドで呼ばれる関数
			@Override public void run()
			{
	
				// ダイアログを作成
				AlBuilder = new AlertDialog.Builder( AppActivity ) ;

				// ダイアログのタイトルを設定
				AlBuilder.setMessage( "あなたのスコアは「」です。\nクリップボードにコピーしました。\nスコアをベンチマーク投稿所に投稿しますか？\n" ) ;

				// ダイアログに OK ボタンを追加
				AlBuilder.setPositiveButton( "OK", new DialogInterface.OnClickListener()
				{
					// OK ボタンが押されたときに呼ばれる関数
					public void onClick( DialogInterface dialog, int whichButton )
					{
						copyToClipboard(100);
						startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("http://dixq.net/forum/viewtopic.php?f=42&t=18976"));
						Toast.makeText(DanmakuBench.this,"読み込みに少々時間がかかります",Toast.LENGTH_LONG).show();
						Toast.makeText(DanmakuBench.this,"しばらくお待ちください",Toast.LENGTH_LONG).show();
					}
				});

				// ダイアログを表示
				AlBuilder.show() ;
			}
		}) ;
		*/
	}
	/*

	private String getCopyText(int score){
		return
				"端末名："+Build.MODEL+"\n"+
				"スコア："+score;
	}

	private void copyToClipboard(int score){
		//クリップボードに格納するItemを作成
		ClipData.Item item = new ClipData.Item(getCopyText(score));
 		//MIMETYPEの作成
		String[] mimeType = new String[1];
		mimeType[0] = ClipDescription.MIMETYPE_TEXT_URILIST;
 		//クリップボードに格納するClipDataオブジェクトの作成
		ClipData cd = new ClipData(new ClipDescription("text_data", mimeType), item);
 		//クリップボードにデータを格納
		ClipboardManager cm = (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);
		cm.setPrimaryClip(cd);
	}

	*/
}