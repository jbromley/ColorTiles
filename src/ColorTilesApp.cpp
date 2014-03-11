#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/params/Params.h"
#include "cinder/Camera.h"
#include "Tile.h"

using namespace ci;
using namespace ci::app;

class ColorTilesApp : public AppNative {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
private:
    const static int TILE_WIDTH;
    const static int TILE_HEIGHT;
    const static int TILE_DEPTH;
    const static int HALF_WIDTH;
    
    std::vector<Tile*> tiles_;
    CameraPersp camera_;
    Vec3f eye_;
    Vec3f center_;
    Vec3f up_;
    params::InterfaceGl params_;
    Quatf sceneRotation_;
    float cameraDistance_;
};

const int ColorTilesApp::TILE_WIDTH = 8;
const int ColorTilesApp::TILE_HEIGHT = 8;
const int ColorTilesApp::TILE_DEPTH = 1;
const int ColorTilesApp::HALF_WIDTH = 8;

void ColorTilesApp::setup()
{
    app::setWindowSize(1200, 800);
    gl::enableAlphaBlending();

    // Set up the camera.
    cameraDistance_ = 1000.0f;
    eye_ = Vec3f(0.0f, 0.0f, cameraDistance_);
    center_ = Vec3f::zero();
    up_ = Vec3f::yAxis();
    camera_.setPerspective(75.0f, getWindowAspectRatio(), 5.0f, 2000.0f);

    // Set up camera control.
    params_ = params::InterfaceGl("Color Tiles", Vec2i(225, 200));
    params_.addParam("Scene Rotation", &sceneRotation_);
    params_.addParam("Eye Distance", &cameraDistance_, "min=0.0 max=2000.0 step=50.0 keyIncr=s keyDecr=w");
    
    // Set up the initial set of tiles.
    for (int x = -HALF_WIDTH; x <= HALF_WIDTH; ++x) {
        for (int y = -HALF_WIDTH; y <= HALF_WIDTH; ++y) {
            for (int z = -HALF_WIDTH; z <= HALF_WIDTH; ++z) {
                int xpos = 3 * x * TILE_WIDTH / 2;
                int ypos = 3 * y * TILE_HEIGHT / 2;
                int zpos = 4 * z * TILE_WIDTH / 2;
                
                Tile* tile = new Tile(xpos, ypos, zpos,
                                      TILE_WIDTH, TILE_HEIGHT, TILE_DEPTH);
                tiles_.push_back(tile);
            }
        }
    }
}

void ColorTilesApp::mouseDown(MouseEvent event)
{
}

void ColorTilesApp::update()
{
    // Update the camera first.
    eye_ = Vec3f(0.0f, 0.0f, cameraDistance_);
    camera_.lookAt(eye_, center_, up_);
    gl::setMatrices(camera_);
    gl::rotate(sceneRotation_);
    
    std::for_each(tiles_.begin(), tiles_.end(), std::mem_fun(&Tile::update));
}

void ColorTilesApp::draw()
{
	gl::clear(Color(0, 0, 0));

    gl::setMatrices(camera_);
    gl::rotate(sceneRotation_);

    std::for_each(tiles_.begin(), tiles_.end(), std::mem_fun(&Tile::draw));
    params_.draw();
}

CINDER_APP_NATIVE(ColorTilesApp, RendererGl)
