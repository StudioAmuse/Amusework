#ifndef AMUSE_INCLUDE_TYPES_HPP
#define AMUSE_INCLUDE_TYPES_HPP

#include <cstdint>
#include <cstddef>

namespace amuse::core
{
    using Int8  = std::int8_t;
    using Int16 = std::int16_t;
    using Int32 = std::int32_t;
    using Int64 = std::int64_t;

    using UInt8  = std::uint8_t;
    using UInt16 = std::uint16_t;
    using UInt32 = std::uint32_t;
    using UInt64 = std::uint64_t;

    using Byte = std::byte;

    using UPtr = std::uintptr_t;
    using Ptr  = std::intptr_t;
    using Size = std::size_t;

    using Float32 = float;
    using Float64 = double;
}

static_assert(sizeof(amuse::core::Int32) == 4, "Int32 must be 4 bytes.");
static_assert(sizeof(amuse::core::Int64) == 8, "Int64 must be 8 bytes.");
static_assert(sizeof(amuse::core::Float32) == 4, "Float32 must be 4 bytes.");
static_assert(sizeof(amuse::core::Float64) == 8, "Float64 must be 8 bytes.");

#endif // !AMUSE_INCLUDE_TYPES_HPP