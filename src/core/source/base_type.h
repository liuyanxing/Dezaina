#pragma once

#include <memory>
#include <vector>
#include <string>
#include "include/core/SkData.h"
#include "include/core/SkRefCnt.h"

template<typename T> using vector = std::vector<T>;
using string = std::string;

using Data = SkData;
using DataSharedPtr = sk_sp<Data>;
