//
//  PlatformInfo.cpp
//
//  Created by Ian Grossberg on 1/2/12.
//  Copyright (c) 2012 Lumos Labs. All rights reserved.
//

#include "PlatformInfo.h"
#include "InfoView.h"

#include "ofxGenericException.h"

PlatformInfo::PlatformInfo()
{
}

PlatformInfo::~PlatformInfo()
{
}

void PlatformInfo::setup()
{	
    ofxGenericApp::setup();
    
    ofPtr< ofxGenericView > rootView = getRootView();
    if ( rootView )
    {
        ofPtr< InfoView > infoView = InfoView::create( _window->getFrame() );
        rootView->addChildView( infoView );
    }
}

ofPtr< PlatformInfo > PlatformInfo::_this;

ofPtr< PlatformInfo > PlatformInfo::getInstance()
{
    if ( !PlatformInfo::_this )
    {
        ( new PlatformInfo() )->setPlatformInfoInstanceToThis();
    }
    return PlatformInfo::_this;
}

void PlatformInfo::setPlatformInfoInstanceToThis()
{
    if ( !PlatformInfo::_this )
    {
        PlatformInfo::_this = ofPtr< PlatformInfo >( this );
        PlatformInfo::_this->setofxGenericAppInstanceToThis();
    } else
    {
        throw ofxGenericExceptionSubclassedSingletonInitializedTwice( "ofxGenericApp" );        
    }
}

