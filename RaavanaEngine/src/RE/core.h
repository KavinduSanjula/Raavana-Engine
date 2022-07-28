#pragma once
#include <memory>

#define NO_TEXTURE "no-texture"

#ifdef RE_EXPORT_DLL
#define RE_API __declspec(dllexport)
#else
#define RE_API __declspec(dllimport)
#endif

namespace RE {
	template <typename T>
	using Ref = std::shared_ptr<T>;

	template <typename T>
	using Scope = std::unique_ptr<T>;
}