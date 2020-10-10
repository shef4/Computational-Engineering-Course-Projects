#include "GlgClass.h"


// Beat time events consist of the elapsed time since the start of program
// execution and the time interval between screen redraws.
// Both times are in units of milliseconds.

struct BeatEvent {
    long beat_time;
    long update_time_interval;
};


// Repackage the original C functions and global variables as additional
// member functions and data members in the AnimationExample class.

class AnimationExample : public GlgObjectC
{
public:     // Member functions providing the class's API.

    AnimationExample();             // Constructor
    virtual ~AnimationExample();    // Destructor

    // Override to supply custom Input and Selection methods.
    void Input( GlgObjectC& callback_viewport, GlgObjectC& message);
    void Select(GlgObjectC& callback_viewport, const char ** name_array);

    // Additional member functions used to control the ball's motion.
    void initializePosition();
    void readBeatEvents();
    void updatePosition();
    long getTimeInterval();

private:    // Data members should always have private scope.

    // Mathematical constants.
    const double PI  = 3.14159265358979323846264338327950;
    const double PI2 = 2.0 * PI;
    
    // Fixed animation parameters.
    const double DELTA  = PI2 / 500.0;
    const double X_INCR = DELTA * 8.0;
    const double Y_INCR = DELTA * 7.0;

    double x_value;         // Ranges between 0 and 2*Pi.
    double y_value;
    double x_center;        // Center of the ball's movement area.
    double y_center;
    double x_amplitude;     // Extent of the ball's movement.
    double y_amplitude;

    long time_interval;     // Time interval for periodic dynamic updates, in millisec.

    const long MIN_TIME_INTERVAL = 1;
    const long MAX_TIME_INTERVAL = 1000;

    // A dynamically allocated table of beat events read from a file.
    BeatEvent * beat_events;

    const int MAX_BEAT_EVENTS = 1000000;    // The allocated table's fixed size.

    int num_beat_events;                    // Incremented while writing to the table.
    int beat_event_index;                   // Incremented while reading from the table.

    long music_start;                       // clock() value when the ball starts moving.
};
