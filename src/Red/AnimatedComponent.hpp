#pragma once

#include <Red/AnimatedObject.hpp>

namespace Raw::AnimatedComponent
{
using AnimatedObject = Core::OffsetPtr<0x178, Red::anim::AnimatedObject*>;
using RootAnimObjPart = Core::OffsetPtr<0x270, Red::UniquePtr<Red::AnimatedObjectPart>>;
}
