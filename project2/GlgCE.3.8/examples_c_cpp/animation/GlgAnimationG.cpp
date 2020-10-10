
// This example demonstrates how to load a GLG drawing and update its dynamic
// attributes periodically, as well as handle objectselection with the mouse.
// The program exits when user clicks on a moving object.
//
// Periodic dynamic updates are handled in the updateFunction procedure,
// which is invoked when a specified time interval elapses. It is registered
// as a Timer procedure using GlgAddTimeOut function with a specified
// time interval.
// 
// Object selection event is handled in the Select callback.
//
// The "animation.g" drawing contains a ball named "CatchMe" and a polygon
// named "Area". The lower left and upper right control points of the area
// polygon are named "LLPoint" and "URPoint". The program queries the 
// coordinates of these control points and uses them to animate the ball
// by moving it inside the area. The ball has X and Y move transformations
// attached to it to control its position. The program sets the XValue 
// and YValue parameters of the transformations to move the ball.


#include "AnimationExample.h"

// Defines a platform-specific program entry point.
#include "GlgMain.h"


static GlgAppContext AppContext;


// A C function wrapper with a prescribed signature is needed for invocation when
// the timer period expires.
// The actual work is done by the AnimationExample's updatePosition() member function.

static void updateFunction(AnimationExample * animation, GlgLong * timer_id)
{
    animation->updatePosition();

    // Reinstall the timer to continue updating.
    GlgAddTimeOut(AppContext, animation->getTimeInterval(),
                  (GlgTimerProc)updateFunction, (GlgAnyType)animation);
}


// Main Entry point.

int GlgMain(int argc, char * argv[], GlgAppContext InitAppContext)
{
    GlgSessionC glg_session(False, InitAppContext, argc, argv);

    AppContext = glg_session.GetAppContext();

    AnimationExample animation;

    // Create a GLG object from a file.
    animation.LoadWidget("animation.g");

    // Set widget dimensions using world coordinates [-1000, 1000].
    // If not set, default dimensions will be used as set in the GLG editor.
    animation.SetResource("Point1", -600.0, -700.0, 0.0);
    animation.SetResource("Point2",  600.0,  700.0, 0.0);

    // Enable input and selection callbacks.
    animation.EnableCallback(GLG_INPUT_CB);
    animation.EnableCallback(GLG_SELECT_CB);
 
    animation.InitialDraw();
    animation.initializePosition();
    animation.readBeatEvents();

    // Add a timer to periodically update the drawing.
    GlgAddTimeOut(AppContext, animation.getTimeInterval(), (GlgTimerProc)updateFunction, 
                  (GlgAnyType)&animation);

    return (int)GlgMainLoop(AppContext);
}
