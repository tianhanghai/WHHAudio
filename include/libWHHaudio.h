#ifndef LIBWHHAUDIO_H
#define LIBWHHAUDIO_H

#ifdef libWHHaudio_EXPORTS
#define libWHHaudio_API __declspec(dllexport)
#else
#define libWHHaudio_API __declspec(dllimport)
#endif

void WHH_say_hello();

#endif