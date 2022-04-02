#include "session.h"

//Abstract Class, see 'sessiontypes.h' for implementations

Session::Session(string n, float s, float e) {
    name = n;
    freqRangeStart = s;
    freqRangeEnd = e;
}

string Session::getName() {
    return name;
}

float Session::getBottomFrequency() {
    return freqRangeStart;
}

float Session::getTopFrequency() {
    return freqRangeEnd;
}

string Session::getFrequencyRange() {
    return (to_string(freqRangeStart) + " Hz - " + to_string(freqRangeEnd) + " Hz");
}
