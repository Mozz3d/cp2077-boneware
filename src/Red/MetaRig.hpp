#pragma once

namespace Red
{
struct MetaRigBank
{
    struct MetaRigBankEntry
    {
        using AllocatorType = RED4ext::Memory::AnimMetaRigsAllocator;

        int32_t hash;
        uint32_t refCount;
        UniquePtr<RED4ext::anim::MetaRig> metaRig;
        bool areMappingsInitialized;
        bool isMetaRigInitialized;
        SharedSpinLock lock;
    };

    DynArray<UniquePtr<MetaRigBankEntry>> entries;
    SharedSpinLock entriesLock;
    std::atomic<uint32_t> clearCounter;
};

struct MetaRigReference
{
    int32_t hash;
    RED4ext::anim::MetaRig* metaRig;
    MetaRigBank* metaRigBank;
};
}

namespace Raw::MetaRigReference
{
constexpr auto Release = Core::RawFunc<
    /* addr = */ Red::AddressLib::MetaRigReference_Release,
    /* type = */ void (*)(Red::MetaRigReference* aMetaRigRef)>();
}
