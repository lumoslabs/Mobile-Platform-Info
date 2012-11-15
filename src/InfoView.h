//
//  LoginView.h
//  iOS
//
//  Created by Ian Grossberg on 3/7/12.
//  Copyright (c) 2012 Lumos Labs. All rights reserved.
//

#pragma once

#include "ofxGenericView.h"
#include "ofxGenericImageView.h"
#include "ofxGenericEditTextView.h"
#include "ofxGenericActivityView.h"
#include "ofxGenericButtonView.h"
#include "ofxGenericTextView.h"

class InfoView : public ofxGenericView
{
public:
    static ofPtr< InfoView > create( const ofRectangle& setFrame = ofRectangle( 0, 0, 0, 0 ) );

    virtual void didLoad();
    
protected:    
    ofPtr< ofxGenericTextView > _multitaskingSupported;
    
    ofPtr< ofxGenericTextView > _deviceName;
    ofPtr< ofxGenericTextView > _deviceModel;
    ofPtr< ofxGenericTextView > _deviceModelVersion;
    
    ofPtr< ofxGenericTextView > _operatingSystemName;
    ofPtr< ofxGenericTextView > _operatingSystemGroupName;
    ofPtr< ofxGenericTextView > _operatingSystemVersion;
    
    ofPtr< ofxGenericTextView > _uniqueIdentifier;
//    ofPtr< ofxGenericTextView > _orientation;
    ofPtr< ofxGenericTextView > _batteryLevel;
    
#if TARGET_OS_IPHONE
    ofPtr< ofxGenericTextView > _isRetinaDisplay;
    ofPtr< ofxGenericTextView > _is4InchDisplay;
#endif
    
    ofPtr< ofxGenericTextView > createTextView( float& yLocation );
};