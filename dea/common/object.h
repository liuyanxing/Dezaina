#pragma once

namespace dea::base {

class NonCopyable {
protected:
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;

    NonCopyable& operator=(const NonCopyable&) = delete;

    NonCopyable(NonCopyable&&) = default;
    NonCopyable& operator=(NonCopyable&&) = default;

    virtual ~NonCopyable() = default;
};

}