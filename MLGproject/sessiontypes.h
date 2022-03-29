#ifndef SESSIONTYPES_H
#define SESSIONTYPES_H

#include <session.h>

//---------------------------------------------------------------------------------

class AlphaSession : public Session
{
public:
    AlphaSession() : Session("Alpha", 9.0, 11.0) {}
};

//---------------------------------------------------------------------------------

class BetaSession : public Session
{
public:
    BetaSession() : Session("Beta 1", 12.0, 15.0) {}
};

//---------------------------------------------------------------------------------

class DeltaSession : public Session
{
public:
    DeltaSession() : Session("Delta", 2.5, 5.0) {}
};

//---------------------------------------------------------------------------------

class ThetaSession : public Session
{
public:
    ThetaSession() : Session("Theta", 6.0, 8.0) {}
};

//---------------------------------------------------------------------------------

#endif // SESSIONTYPES_H
