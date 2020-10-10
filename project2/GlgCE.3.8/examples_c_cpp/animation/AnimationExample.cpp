#include "AnimationExample.h"
#include <math.h>
#include <string>
#include <fstream>
#include <iomanip>


using std::string;
using std::ifstream;
using std::ofstream;
using std::endl;
using std::left;
using std::right;
using std::setw;


// The AnimationExample constructor initializes data members affecting the
// ball's motion.

AnimationExample::AnimationExample()
{
    x_value     = 0.0;
    y_value     = 0.0;
    x_center    = 0.0;
    y_center    = 0.0;
    x_amplitude = 0.0;
    y_amplitude = 0.0;
 
    time_interval = 20;

    // Allocate heap memory for the beat event table.
    beat_events = new BeatEvent[MAX_BEAT_EVENTS];

    num_beat_events  = 0;
    beat_event_index = 0;
    music_start      = 0;
}


// The AnimationExample virtual destructor frees dynamically allocated memory.

AnimationExample::~AnimationExample(void)
{
    // Deallocate the beat event table's heap memory.
    delete[] beat_events;
}


// This callback is invoked when user selects some object in the drawing
// with the mouse.
// In this program, it is used to exit animation if the user selects the
// moving object which is named "CatchMe".

void AnimationExample::Select(GlgObjectC& viewport, const char ** name_array)
{
    if (name_array != nullptr) {
        // Something was selected.
        for (int i = 0; name_array[i] != nullptr; i++) {
            if ((strcmp(name_array[i], "Faster") == 0) ||
                (strcmp(name_array[i], "Slower") == 0)) {
                // Ignore buttons selection.
                return;
            }
        }
        for (int i = 0; name_array[i] != nullptr; i++) {
            if (strcmp(name_array[i], "CatchMe") == 0) {
                // Got the moving object: blink three times and exit.
                for (int j = 0; j < 6; j++) {
                    // Change the index of the color dynamics attached to the
                    // object's FillColor attribute from 0 to 1 and back to blink.
                    // You can check it in the editor by selecting the FillColor 
                    // attribute of the object and clicking on the Edit Dynamics 
                    // button in the Attribute Dialog.
                    SetResource("CatchMe/ColorIndex", ((j % 2) ? 1.0 : 0.0));
                    Update();
                    // Delay for 0.1 sec.
                    GlgSleep(100);
                }
                // Terminate the program.
                exit(0);
            }
        }
    }
    GlgBell(viewport);   // Missed: beep'em up!
}


// This callback is invoked when the user interacts with input objects in GLG drawing.
// In this program, it is used to increase or decrease the animation speed.

void AnimationExample::Input(GlgObjectC& viewport, GlgObjectC& message)
{
    const char * format;
    const char * action;
    const char * origin;
      
    // Get the message's format, action and origin.
    message.GetResource("Format", &format);
    message.GetResource("Action", &action);
    message.GetResource("Origin", &origin);

    // Handle window closing, which may use the viewport's name.
    if ((strcmp(format, "Window") == 00) && (strcmp(action, "DeleteWindow") == 0)) {
        exit(0);
    }

    // Do not do anything unless the message comes from a button and the action
    // is Activate.
    if ((strcmp(format, "Button") == 0) && (strcmp(action, "Activate") == 0)) {
        // Act based on the selected button.
        if (strcmp(origin, "Faster") == 0) {
            // Increase animation speed.
            if (time_interval > MIN_TIME_INTERVAL) {
                time_interval = time_interval / 2;
            }
        }
        else if (strcmp(origin, "Slower") == 0) {
            // Decrease animation speed.
            if (time_interval < (MAX_TIME_INTERVAL / 2)) {
                time_interval = time_interval * 2;
            }
        }
    }
}


// Initialize data members affecting the ball's motion.

void AnimationExample::initializePosition()
{
    double radius;
    double x_min;
    double y_min;
    double x_max;
    double y_max;
    double z;

    // Query the ball's radius.
    GetResource("CatchMe/Radius", &radius);

    // Query the extent of the ball's movement area.
    GetResource("Area/LLPoint", &x_min, &y_min, &z);
    GetResource("Area/URPoint", &x_max, &y_max, &z);

    // Find the center of the ball's movement area.
    x_center = (x_max + x_min) / 2.0;
    y_center = (y_max + y_min) / 2.0;

    // The extent of the ball's movements.
    x_amplitude = ((x_max - x_min) / 2.0) - radius;
    y_amplitude = ((y_max - y_min) / 2.0) - radius;
}


// Read the contents of the beat times file and transfer the information to an array.
// Each beat consists of a floating point beat time (in seconds) and an integer value
// (in milliseconds) between 1 and 1000 controlling the time between screen updates.
// Hence a smaller millisecond value causes the ball to move faster.
// The first line of the beat times file is a positive or negative time shift value
// that is added to all subsequent beat times.
// Possible errors include exceeding the array's fixed size and being unable to find
// or open the beat times file.
// Since a console is not available, error messages are instead written to a log file.
// No error checking is performed on the beat times and update time interval.
// The recorded beat events table is also written to the log file.

void AnimationExample::readBeatEvents()
{
    const string beat_file_name = "beat_times.txt";
    const string log_file_name  = "beat_log.txt";

    ifstream beat_file(beat_file_name);
    ofstream log_file(log_file_name);

    if (beat_file.is_open()) {
        // TODO: Declare variables with appropriate types for the time shift,
        float time_shift;
        // beat time and time interval.
        float beat_timev;
        int time_intervalv;
        // TODO: Read the time shift and the first beat time and time interval.
        beat_file >> time_shift;
        beat_file >> beat_timev;
        beat_file >> time_intervalv;
        while (!beat_file.eof()) {
            if (num_beat_events < MAX_BEAT_EVENTS) {
                // TODO: Add the time shift to the beat time.
                beat_timev += time_shift;
                // TODO: Convert the beat time from decimal seconds to integer milliseconds.
                beat_events[num_beat_events].beat_time = (int)(beat_timev*1000) ;// rounded integer millisecond value
                beat_events[num_beat_events].update_time_interval = time_intervalv;// time interval value
                // TODO: Increment num_beat_events.
                num_beat_events++;
            }
            else {
                // TODO: Write a meaningful error message that the beat event table is full.
                log_file << "ERROR: The beat event table is full";
                break;
            }
            // TODO: Read the next beat time and time interval.
            beat_file >> beat_timev;
            beat_file >> time_intervalv;
        }
    }
    else {
        // TODO: Write a meaningful error message that the beat_file_name could not be opened.
        log_file << "ERROR: The beat_file_name could not be opened.";

    }

    // Display the beat events table in the log file.

    if (num_beat_events > 0) {
        log_file << endl << "Beat events table: [index | time shifted beat time (ms) | "
                 << "screen update time interval (ms)]" << endl << endl;
        for (int i = 0; i < num_beat_events; i++) {
            log_file << right << setw(12) << i << "    "
                     << right << setw(12) << beat_events[i].beat_time
                     << right << setw(12) << beat_events[i].update_time_interval << endl;
        }
    }
    else {
        log_file << "Beat events table is empty" << endl;
    }

    // Record the time when the ball starts moving.

    music_start = clock();
}


// Animates the ball by moving it inside the area defined in the drawing.

void AnimationExample::updatePosition()
{
    // If the next beat time has been reached, adjust the screen redraw time interval.

    if (beat_event_index < num_beat_events) {
        long time_since_start = clock() - music_start;
        if (time_since_start >= beat_events[beat_event_index].beat_time) {
            time_interval = beat_events[beat_event_index].update_time_interval;
            beat_event_index++;
        }
    }

    // Calculate new ball coordinates.

    x_value = x_value + X_INCR;

    if (x_value > PI2) {
        x_value = x_value - PI2;
    }

    y_value = y_value + Y_INCR;

    if (y_value > PI2) {
        y_value = y_value - PI2;
    }

    double x_position = x_center + (x_amplitude * sin(x_value));
    double y_position = y_center + (y_amplitude * cos(y_value));

    // Set coordinates of the ball in the drawing.
    SetResource("CatchMe/XValue", x_position);
    SetResource("CatchMe/YValue", y_position);

    Update();    // Makes changes visible.
    Sync();      // Improves interactive response.
}


// Return the current update time interval which controls the ball's speed.

long AnimationExample::getTimeInterval()
{
    return time_interval;
}
