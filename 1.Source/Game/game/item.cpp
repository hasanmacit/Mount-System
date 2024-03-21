///aratýlýr:
		else if (GetSubType() == COSTUME_HAIR)
			return WEAR_COSTUME_HAIR;

///altýna eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		else if (GetSubType() == COSTUME_MOUNT)
			return WEAR_COSTUME_MOUNT;
#endif

///aratýlýr:
		long value = m_pProto->aApplies[i].lValue;

///üstüne eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if(IsMountItem())
			continue;
#endif

///aratýlýr:
	m_pOwner->ComputeBattlePoints();

///üstüne eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (IsMountItem())
		ch->MountSummon(this);
#endif

///aratýlýr:
	if (this != m_pOwner->GetWear(GetCell() - INVENTORY_MAX_NUM))
	{
		sys_err("m_pOwner->GetWear() != this");
		return false;
	}

///altýna eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (IsMountItem())
		m_pOwner->MountUnsummon(this);
#endif

///aratýlýr:
bool CItem::IsRideItem()
{
	if (ITEM_UNIQUE == GetType() && UNIQUE_SPECIAL_RIDE == GetSubType())
		return true;
	if (ITEM_UNIQUE == GetType() && UNIQUE_SPECIAL_MOUNT_RIDE == GetSubType())
		return true;

///altýna eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (ITEM_COSTUME == GetType() && COSTUME_MOUNT == GetSubType())
		return true;
#endif


//aratýlýr:

bool CItem::IsRamadanRing()

///kod bloðunun altýna eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
bool CItem::IsMountItem()
{
	if (GetType() == ITEM_COSTUME && GetSubType() == COSTUME_MOUNT)
		return true;
	
	return false;
}
#endif