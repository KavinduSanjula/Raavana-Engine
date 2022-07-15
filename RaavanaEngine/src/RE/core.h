#pragma once


#ifdef RE_EXPORT_DLL
#define RE_API __declspec(dllexport)
#else
#define RE_API __declspec(dllimport)
#endif