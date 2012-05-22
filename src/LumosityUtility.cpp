/*
 * LumosityUtility.cpp
 *
 *  Created on: Feb 8, 2012
 *      Author: ian
 */

#include "LumosityUtility.h"

void ofLLog( ofLogLevel level, const string & message )
{
	ofLog( "Lumosity", level, message );
}

void ofLLogError( const string & message )
{
	ofLogError( "Lumosity", message );
}

void ofLLogFatalError( const string & message )
{
	ofLogFatalError( "Lumosity", message );
}

void ofLLogNotice( const string & message )
{
	ofLogNotice( "Lumosity", message );
}

void ofLLogVerbose( const string & message )
{
	ofLogVerbose( "Lumosity", message );
}

void ofLLogWarning( const string & message )
{
	ofLogWarning( "Lumosity", message );
}

void ofLLog( ofLogLevel level, const char* format, ... )
{
	va_list args;
	va_start( args, format );
	ofLog( "Lumosity", level, format, args );
	va_end( args );
}
