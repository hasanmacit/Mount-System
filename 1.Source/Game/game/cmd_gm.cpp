///aratýlýr:
		if (pkChr->IsNPC() && !pkChr->IsPet() && pkChr->GetRider() == NULL)

///deðiþtirilir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if (pkChr->IsNPC() && !pkChr->IsPet() && !pkChr->IsMount() && pkChr->GetRider() == NULL)
#else
		if (pkChr->IsNPC() && !pkChr->IsPet() && pkChr->GetRider() == NULL)
#endif

///aratýlýr:
ACMD(do_horse_summon)
{

///altýna eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (ch->IsRidingMount())
		return;
#endif
