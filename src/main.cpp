//
//  main.cpp
//
//  Created by Ian Grossberg on 1/2/12.
//  Copyright (c) 2012 Lumos Labs. All rights reserved.
//

#include "ofMain.h"

#include "PlatformInfo.h"
#include "ofxAppGenericWindow.h"
#include "LumosityUtility.h"

int main()
{
#if TARGET_OS_IPHONE
    NSAutoreleasePool* pool = [ [ NSAutoreleasePool alloc ] init];
#endif

//#ifdef DEBUG
    ofSetLogLevel( OF_LOG_VERBOSE );
//#else
//    ofSetLogLevel( OF_LOG_ERROR );
//#endif
    
    ofLLogVerbose( "Starting app..." );

    ofPtr< PlatformInfo > app( PlatformInfo::getInstance() );
    ofPtr< ofAppBaseWindow > window( new ofxAppGenericWindow( true ) );
    
    // TODO: don't use ofSetupOpenGL
    ofSetupOpenGL( window, 1024, 768, OF_FULLSCREEN );
	ofRunApp( app );
    
#if TARGET_OS_IPHONE
    [ pool release ];    
#endif
}

#ifdef TARGET_ANDROID
#include <jni.h>
extern "C"
{
	void Java_cc_openframeworks_ofxGeneric_Activity_Main( JNIEnv* env, jobject thiz )
	{
		ofLLog( OF_LOG_VERBOSE, "In Main(): %d", env );
		main();
	}
}
#endif
