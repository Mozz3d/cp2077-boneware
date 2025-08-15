#pragma once

#include <Red/MetaRig.hpp>

namespace Red
{
struct AnimatedObjectPart
{
    uint8_t unk00[0x08 - 0x00];
    AnimatedObjectPart* child;
    AnimatedObjectPart* parent;
    bool isDirty;
    Red::anim::AnimGraph* animGraph;
    void* animInstanceBuff;
    uint8_t unk30[0x40 - 0x30];
    Handle<Red::anim::Rig> rig;
    DynArray<CName> tags;
    DynArray<CName> visualTags;
    uint8_t unk70[0x2490 - 0x70];
    QsTransform localToParent;
    QsTransform localToRoot;
    WorldTransform localToWorld;
    uint8_t unk2510[0x2548 - 0x2510];
    uint8_t unk2548[0x2560 - 0x2548];
    uint8_t unk2560[0x2578 - 0x2560];
    uint8_t unk2578[0x25a8 - 0x2578];
    Red::AnimatedComponent* ownerComponent;
    uint8_t unk25b0[0x25b8 - 0x25b0];
    DynArray<CName> unk25b8;
    bool forceReferencePose;
    uint8_t unk25c9[0x25d0 - 0x25c9];
};
RED4EXT_ASSERT_SIZE(AnimatedObjectPart, 0x25D0);
}

namespace Raw::AnimatedObject
{
using MetaRigRef = Core::OffsetPtr<0x00, Red::MetaRigReference>;
}
