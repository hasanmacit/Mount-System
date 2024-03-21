// aratılır:

#include "sectree_manager.h"

// altına eklenir:

#include "MountSystem.h"

// aratılır:

if (!ch->IsPC() && !ch->IsPet())

// değiştirilir:

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
				if (!ch->IsPC() && !ch->IsPet() && !ch->IsMount())
#else
				if (!ch->IsPC() && !ch->IsPet())
#endif

// aratılır:

if (!pChar->IsPet() && (true == pChar->IsMonster() || true == pChar->IsStone()))

// değiştirilir:

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
				if (!pChar->IsPet() && !pChar->IsMount() && (true == pChar->IsMonster() || true == pChar->IsStone()))
#else				
				if (!pChar->IsPet() && (true == pChar->IsMonster() || true == pChar->IsStone()))
#endif