//
//  InfoView.cpp
//  iOS
//
//  Created by Ian Grossberg on 3/7/12.
//  Copyright (c) 2012 Lumos Labs. All rights reserved.
//

#include "InfoView.h"

#include "ofxGenericScrollView.h"
#include "ofxGenericTextView.h"

#include "ofxGenericPlatform.h"

#define INFO_VIEW_HEIGHT 40

ofPtr< InfoView > InfoView::create( const ofRectangle& setFrame )
{
    ofPtr< InfoView > view( new InfoView() );
    view->init( view, setFrame );
    return view;
}

void InfoView::didLoad()
{
    ofxGenericView::didLoad();
  
    setBackgroundColor( ofColor( 191, 229, 248 ) );
    
    float yLocation = 0.0f;
    
    _contents = ofxGenericScrollView::create( getFrame( ofPoint( 0, 0 ) ) );
    if ( _contents )
    {
        _contents->setAutoContentSizeToFit( true );
        addChildView( _contents );
    }
    
    _multitaskingSupported = InfoView::createTextView( yLocation, "Multitasking Supported: " + ofxGToString( ofxGenericPlatform::multitaskingSupported() ) );
    
    _deviceName = InfoView::createTextView( yLocation, "Device Name: " + ofxGenericPlatform::deviceName() );
    
    _deviceModel = InfoView::createTextView( yLocation, "Device Model: " + ofxGenericPlatform::deviceModel() );
    
    _deviceModelVersion = InfoView::createTextView( yLocation, "Device Model Version: " + ofxGenericPlatform::deviceModelVersion() );
    
    _cpuFrequency = InfoView::createTextView( yLocation, "CPU Speed: " + ofToString( ofxGenericPlatform::cpuFrequency() ) );
    
    _cpuFrequency = InfoView::createTextView( yLocation, "CPU Count: " + ofToString( ofxGenericPlatform::cpuCount() ) );
    
    _cpuFrequency = InfoView::createTextView( yLocation, "Total Memory: " + ofToString( ofxGenericPlatform::totalMemory() ) );
    
    _cpuFrequency = InfoView::createTextView( yLocation, "Mac Address: " + ofxGenericPlatform::macAddress() );
    
    _operatingSystemName = InfoView::createTextView( yLocation, "Operating System Name: " + ofxGenericPlatform::operatingSystemName() );
    
    _operatingSystemGroupName = InfoView::createTextView( yLocation, "Operating System Group Name: " + ofxGenericPlatform::operatingSystemGroupName() );
    
    _operatingSystemVersion = InfoView::createTextView( yLocation, "Operating System Version: " + ofxGenericPlatform::operatingSystemVersion() );
    
    _uniqueIdentifier = InfoView::createTextView( yLocation, "UUID: " + ofxGenericPlatform::uniqueIdentifier() );
    
    
    //    _orientation = InfoView::createTextView( yLocation, "Orientation: " + ofxGenericPlatform::getInstance()->orientation() );
    
//    _batteryLevel = InfoView::createTextView( yLocation, "Battery Level: " + ofxGenericPlatform::getInstance()->batteryLevel() );
    
    _isRetinaDisplay = InfoView::createTextView( yLocation, "Is Retina Display: " + ofxGToString( ofxGenericPlatform::isRetinaDisplay() ) );
    
    _is4InchDisplay = InfoView::createTextView( yLocation, "Is 4 Inch Display: " + ofxGToString( ofxGenericPlatform::is4InchDisplay() ) );
}

ofPtr< ofxGenericTextView > InfoView::createTextView( float& yLocation, string text )
{
    ofPtr< ofxGenericTextView > view;
    if ( _contents )
    {
        view = ofxGenericTextView::create( ofRectangle( _contents->getFrame().width / 2 - 300 / 2, yLocation, 300, INFO_VIEW_HEIGHT ) );
        if ( view )
        {
            view->setTextAlignment(ofxGenericTextHorizontalAlignmentCenter );
            view->setAutosizeFontToFitText( ofxGenericViewAutoresizingFull );
            view->setText( text );
            _contents->addChildView( view );
            yLocation += INFO_VIEW_HEIGHT;
        }
    }
    return view;
}
