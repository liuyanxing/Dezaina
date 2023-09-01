#pragma once

#include <memory>
#include <vector>
#include <string>
#include "include/core/SkData.h"
#include "include/core/SkRefCnt.h"

using Data = SkData;
using DataSharedPtr = sk_sp<Data>;

using std::vector;
using std::string;
using std::variant;
using std::shared_ptr;
using std::weak_ptr;
using std::unique_ptr;
using std::make_shared;
using std::make_unique;
using std::move;

