#ifndef AMUSE_INCLUDE_MACROS_HPP
#define AMUSE_INCLUDE_MACROS_HPP

#if !defined(AMUSE_PLATFORM_WINDOWS) && !defined(AMUSE_PLATFORM_LINUX) && !defined(AMUSE_PLATFORM_MAC)
    #if defined(_WIN32)
        #define AMUSE_PLATFORM_WINDOWS 1
    #elif defined(__APPLE__)
        #define AMUSE_PLATFORM_MAC 1
    #elif defined(__linux__)
        #define AMUSE_PLATFORM_LINUX 1
    #endif
#endif

#if !defined(AMUSE_COMPILER_MSVC) && !defined(AMUSE_COMPILER_GCC) && !defined(AMUSE_COMPILER_CLANG)
    #if defined(_MSC_VER)
        #define AMUSE_COMPILER_MSVC 1
    #elif defined(__clang__)
        #define AMUSE_COMPILER_CLANG 1
    #elif defined(__GNUC__)
        #define AMUSE_COMPILER_GCC 1
    #endif
#endif

#if defined(AMUSE_PLATFORM_WINDOWS)
    #if defined(AMUSE_BUILD_SHARED)
        #define AMUSE_API __declspec(dllexport)
    #elif defined(AMUSE_USE_SHARED)
        #define AMUSE_API __declspec(dllimport)
    #else
        #define AMUSE_API
    #endif
#else
    #if defined(AMUSE_COMPILER_GCC) || defined(AMUSE_COMPILER_CLANG)
        #if defined(AMUSE_BUILD_SHARED)
            #define AMUSE_API __attribute__((visibility("default")))
        #else
            #define AMUSE_API
        #endif
    #else
        #define AMUSE_API
    #endif
#endif

#if defined(AMUSE_COMPILER_MSVC)
    #define AMUSE_FORCE_INLINE __forceinline
    #define AMUSE_NO_INLINE __declspec(noinline)
#elif defined(AMUSE_COMPILER_GCC) || defined(AMUSE_COMPILER_CLANG)
    #define AMUSE_FORCE_INLINE inline __attribute__((always_inline))
    #define AMUSE_NO_INLINE __attribute__((noinline))
#else
    #define AMUSE_FORCE_INLINE inline
    #define AMUSE_NO_INLINE
#endif

#if defined(AMUSE_COMPILER_MSVC)
    #define AMUSE_DEBUG_BREAK() __debugbreak()
#elif defined(AMUSE_COMPILER_CLANG)
    #define AMUSE_DEBUG_BREAK() __builtin_debugtrap()
#elif defined(AMUSE_COMPILER_GCC)
    #define AMUSE_DEBUG_BREAK() __builtin_trap()
#else
    #include <assert.h>
    #define AMUSE_DEBUG_BREAK() assert(false)
#endif

#if defined(AMUSE_COMPILER_GCC) || defined(AMUSE_COMPILER_CLANG)
    #define AMUSE_LIKELY(x) __builtin_expect(!!(x), 1)
    #define AMUSE_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
    #define AMUSE_LIKELY(x) (x)
    #define AMUSE_UNLIKELY(x) (x)
#endif

#if defined(__cplusplus) && __cplusplus >= 201703L
    #define AMUSE_NODISCARD [[nodiscard]]
#elif defined(AMUSE_COMPILER_MSVC)
    #define AMUSE_NODISCARD _Check_return_
#elif defined(AMUSE_COMPILER_GCC) || defined(AMUSE_COMPILER_CLANG)
    #define AMUSE_NODISCARD __attribute__((warn_unused_result))
#else
    #define AMUSE_NODISCARD
#endif

#if defined(__cplusplus) && __cplusplus >= 201402L
    #define AMUSE_DEPRECATED(msg) [[deprecated(msg)]]
#elif defined(AMUSE_COMPILER_MSVC)
    #define AMUSE_DEPRECATED(msg) __declspec(deprecated(msg))
#elif defined(AMUSE_COMPILER_GCC) || defined(AMUSE_COMPILER_CLANG)
    #define AMUSE_DEPRECATED(msg) __attribute__((deprecated(msg)))
#else
    #define AMUSE_DEPRECATED(msg)
#endif

#if defined(__cplusplus) && __cplusplus >= 201103L
    #define AMUSE_ALIGN(N) alignas(N)
#elif defined(AMUSE_COMPILER_MSVC)
    #define AMUSE_ALIGN(N) __declspec(align(N))
#elif defined(AMUSE_COMPILER_GCC) || defined(AMUSE_COMPILER_CLANG)
    #define AMUSE_ALIGN(N) __attribute__((aligned(N)))
#else
    #define AMUSE_ALIGN(N)
#endif

#if defined(AMUSE_COMPILER_MSVC)
    #define AMUSE_NOVTABLE __declspec(novtable)
#else
    #define AMUSE_NOVTABLE
#endif

#if defined(AMUSE_COMPILER_MSVC)
    #define AMUSE_RESTRICT __restrict
    #define AMUSE_RESTRICT_RETURN __declspec(restrict)
#elif defined(AMUSE_COMPILER_GCC) || defined(AMUSE_COMPILER_CLANG)
    #define AMUSE_RESTRICT __restrict__
    #define AMUSE_RESTRICT_RETURN __attribute__((malloc))
#else
    #define AMUSE_RESTRICT
    #define AMUSE_RESTRICT_RETURN
#endif

#define AMUSE_UNUSED(x) (void)(x)

#define AMUSE_FALLTHROUGH() [[fallthrough]]

#endif // !AMUSE_INCLUDE_MACROS_HPP