#
#
#
include $(CLEAR_VARS)

LOCAL_MODULE := libDemo08_Physics

LOCAL_LDLIBS := -llog -lz -landroid
LOCAL_SHARED_LIBRARIES := libMCore libGLRenderSystem libSLAudioSystem libMGui libMParticleFX libMPhysics

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/../../SDK.Android/include \
	$(LOCAL_PATH)/../../Samples/Framework.Android
	
LOCAL_SRC_FILES := \
	../../Samples/Framework.Android/stdafx.cpp \
	../../Samples/Framework.Android/NDK_Utils.cpp \
	../../Samples/Framework.Android/IME.cpp \
	../../Samples/Framework.Android/APKArchive.cpp \
	../../Samples/Framework.Android/App.cpp \
	../../Samples/Framework.Android/DebugInfo.cpp \
	../../Samples/Framework.Android/Framework.cpp \
	../../Samples/Demo08_Physics/Demo08_Physics.cpp

include $(BUILD_SHARED_LIBRARY)
