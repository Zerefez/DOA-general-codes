#pragma once
#include <chrono>
//==========================================================
//  Project   : Stopwatch
//  Descr.    : A utility high-resolution stopwatch class
//
//  Ver   Date/author   Description
//----------------------------------------------------------
//  1.0   061027/TFJ    Initial revision
//==========================================================

#pragma once

//-------------------------------------------------
// Class  : Stopwatch
//
// Methods:
// start() - Starts the stopwatch
// stop()  - Stops it
// getDuration() - Returns duration (us by default)
//-------------------------------------------------
class Stopwatch
{
public:
	Stopwatch(void);
	void start(void);
	void stop(void);
	size_t getDuration() const;

private:
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point stopTime;

};

//---------------------------------------
// Constructor
//---------------------------------------
inline Stopwatch::Stopwatch(void)
{
}

//---------------------------------------
// start()
//---------------------------------------
inline void Stopwatch::start(void)
{
	startTime = std::chrono::high_resolution_clock::now();
}

//---------------------------------------
// stop()
//---------------------------------------
inline void Stopwatch::stop(void)
{
	stopTime = std::chrono::high_resolution_clock::now();
}



//---------------------------------------
// getDuration()
//---------------------------------------
inline size_t Stopwatch::getDuration() const
{
	return std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime).count();
}
