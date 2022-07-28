#pragma once
#include <memory>


#ifdef RE_EXPORT_DLL
#define RE_API __declspec(dllexport)
#else
#define RE_API __declspec(dllimport)
#endif

template <typename T>
using Ref = std::shared_ptr<T>;

template <typename T>
using Scope = std::unique_ptr<T>;