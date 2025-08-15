#pragma once

#include <Red/AnimatedComponent.hpp>

namespace App
{
struct AnimatedComponentEx : Red::AnimatedComponent
{
    void ReinitializeRig()
    {
        auto& rootAnimObjPart = Raw::AnimatedComponent::RootAnimObjPart::Ref(this);
        auto* animObject = Raw::AnimatedComponent::AnimatedObject::Ref(this);
        auto& metaRigRef = Raw::AnimatedObject::MetaRigRef::Ref(animObject);
        
        rootAnimObjPart->isDirty = true;

        std::scoped_lock _(metaRigRef.metaRigBank->entriesLock);
        for (auto& entry : metaRigRef.metaRigBank->entries)
        {
            if (entry->hash == metaRigRef.hash)
            {
                std::scoped_lock _(entry->lock);
                entry->isMetaRigInitialized = false;
                entry->areMappingsInitialized = false;
                break;
            }
        }
    }
};
} // namespace App

RTTI_EXPAND_CLASS(Red::AnimatedComponent, App::AnimatedComponentEx, {
    RTTI_METHOD(ReinitializeRig);
});
