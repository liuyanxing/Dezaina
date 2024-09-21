#pragma once

namespace dea::base {

class NonCopyable {
public:
    NonCopyable(NonCopyable&&) = default;
    NonCopyable& operator=(NonCopyable&&) = default;
protected:
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;

    NonCopyable& operator=(const NonCopyable&) = delete;


    virtual ~NonCopyable() = default;
};

}