#ifndef SESSION_H
#define SESSION_H

#include <log.h>

//Abstract Class, see 'sessiontypes.h' for implementations

class Session
{
public:
    string getName();
    float getBottomFrequency();
    float getTopFrequency();

protected:
    Session(string n, float s, float e);

private:
    string name;
    float freqRangeStart;
    float freqRangeEnd;
};

#endif // SESSION_H
