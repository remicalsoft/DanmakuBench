// -------------------------------------------------------------------------------
// 
// 		ＤＸライブラリ		Android専用関数プロトタイプ宣言用ヘッダファイル
// 
// 				Ver 3.17f
// 
// -------------------------------------------------------------------------------

#ifndef __DXFUNCTIONANDROID
#define __DXFUNCTIONANDROID

// インクルード ------------------------------------------------------------------
#include <android/native_activity.h>

// 定義---------------------------------------------------------------------------

// 関数プロトタイプ宣言-----------------------------------------------------------

#ifndef DX_NON_NAMESPACE

namespace DxLib
{

#endif // DX_NON_NAMESPACE

// ソフトのデータ保存用のディレクトリパスを取得する
extern int GetInternalDataPath( TCHAR *PathBuffer, int PathBufferBytes ) ;

// ソフトの外部データ保存用のディレクトリパスを取得する
extern int GetExternalDataPath( TCHAR *PathBuffer, int PathBufferBytes ) ;

// アプリで使用している NativeActivity を取得する
extern const ANativeActivity *GetNativeActivity( void ) ;

// ディスプレイの解像度を取得する
extern int GetAndroidDisplayResolution( int *SizeX, int *SizeY ) ;

// OpenGL 関係の情報を取得する
extern int GetOpenGLInfo(
	TCHAR **Version = NULL,
	TCHAR **Renderer = NULL,
	TCHAR **Vendor = NULL,
	TCHAR ***ExtensionNames = NULL,
	TCHAR **Shader_Language_Version = NULL,
	int *Shader_Max_Vertex_Attribs = NULL,						// GL_MAX_VERTEX_ATTRIBS
	int *Shader_Max_Vertex_Uniform_Vectors = NULL,				// GL_MAX_VERTEX_UNIFORM_VECTORS
	int *Shader_Max_Varying_Vectors = NULL,						// GL_MAX_VARYING_VECTORS
	int *Shader_Max_Combined_Texture_Image_Units = NULL,		// GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS
	int *Shader_Max_Vertex_Texture_Image_Units = NULL,			// GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS
	int *Shader_Max_Texture_Image_Units = NULL,					// GL_MAX_TEXTURE_IMAGE_UNITS
	int *Shader_Max_Fragment_Uniform_Vectors = NULL				// GL_MAX_FRAGMENT_UNIFORM_VECTORS
) ;


#ifndef DX_NON_NAMESPACE

}

#endif // DX_NON_NAMESPACE

#endif // __DXFUNCTIONANDROID

