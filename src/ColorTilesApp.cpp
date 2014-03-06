#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class ColorTilesApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
};

void ColorTilesApp::setup()
{
}

void ColorTilesApp::mouseDown( MouseEvent event )
{
}

void ColorTilesApp::update()
{
}

void ColorTilesApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_NATIVE( ColorTilesApp, RendererGl )
