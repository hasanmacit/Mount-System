// aratılır:

if ( lpChar->IsMonster() == true && !lpChar->IsPet())

// değiştirilir

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			if (lpChar->IsMonster() == true && !lpChar->IsPet() && !lpChar->IsMount())
#else
			if ( lpChar->IsMonster() == true && !lpChar->IsPet())
#endif

// aratılır:

if ( lpChar->IsNPC() == true && !lpChar->IsPet())

// değiştirilir

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			if (lpChar->IsNPC() == true && !lpChar->IsPet() && !lpChar->IsMount())
#else
			if ( lpChar->IsNPC() == true && !lpChar->IsPet())
#endif