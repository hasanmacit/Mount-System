///arat�l�r:
		if (pkChr->IsNPC() && !pkChr->IsPet() && pkChr->GetRider() == NULL)

///de�i�tirilir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if (pkChr->IsNPC() && !pkChr->IsPet() && !pkChr->IsMount() && pkChr->GetRider() == NULL)
#else
		if (pkChr->IsNPC() && !pkChr->IsPet() && pkChr->GetRider() == NULL)
#endif

///arat�l�r:
ACMD(do_horse_summon)
{

///alt�na eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (ch->IsRidingMount())
		return;
#endif
