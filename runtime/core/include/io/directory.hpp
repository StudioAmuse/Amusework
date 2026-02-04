#ifndef AMUSE_INCLUDE_DIRECTORY_HPP
#define AMUSE_INCLUDE_DIRECTORY_HPP

#include "misc/macros.hpp"

namespace amuse::io::directory
{
    /**
     * @brief 지정한 경로 내에 디렉토리가 존재하는지 확인합니다.
     *
     * @param path_ 지정할 경로
     *
     * @return bool 디렉토리가 존재하면 true, 그렇지 않으면 false
     */
    AMUSE_API constexpr bool Exists(const char* path_) noexcept;
}

#endif // !AMUSE_INCLUDE_DIRECTORY_HPP