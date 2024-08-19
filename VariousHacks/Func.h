#pragma once

#define FUNC(address, return_t, callconv, name, ...) return_t (callconv* name)(__VA_ARGS__) = reinterpret_cast<decltype(name)>(address)
#define INLINE_FUNC(address, return_t, callconv, name, ...) inline return_t (callconv* name)(__VA_ARGS__) = reinterpret_cast<decltype(name)>(address)
#define ASSERT_SIZE(T, N) static_assert(sizeof(T) == N, "sizeof("#T") != "#N)