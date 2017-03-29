// -------------------------------------------------------------------------------
// 
// 		�c�w���C�u����		Android��p�֐��v���g�^�C�v�錾�p�w�b�_�t�@�C��
// 
// 				Ver 3.17f
// 
// -------------------------------------------------------------------------------

#ifndef __DXFUNCTIONANDROID
#define __DXFUNCTIONANDROID

// �C���N���[�h ------------------------------------------------------------------
#include <android/native_activity.h>

// ��`---------------------------------------------------------------------------

// �֐��v���g�^�C�v�錾-----------------------------------------------------------

#ifndef DX_NON_NAMESPACE

namespace DxLib
{

#endif // DX_NON_NAMESPACE

// �\�t�g�̃f�[�^�ۑ��p�̃f�B���N�g���p�X���擾����
extern int GetInternalDataPath( TCHAR *PathBuffer, int PathBufferBytes ) ;

// �\�t�g�̊O���f�[�^�ۑ��p�̃f�B���N�g���p�X���擾����
extern int GetExternalDataPath( TCHAR *PathBuffer, int PathBufferBytes ) ;

// �A�v���Ŏg�p���Ă��� NativeActivity ���擾����
extern const ANativeActivity *GetNativeActivity( void ) ;

// �f�B�X�v���C�̉𑜓x���擾����
extern int GetAndroidDisplayResolution( int *SizeX, int *SizeY ) ;

// OpenGL �֌W�̏����擾����
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

