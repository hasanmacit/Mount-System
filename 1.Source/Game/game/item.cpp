///arat�l�r:
		else if (GetSubType() == COSTUME_HAIR)
			return WEAR_COSTUME_HAIR;

///alt�na eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		else if (GetSubType() == COSTUME_MOUNT)
			return WEAR_COSTUME_MOUNT;
#endif

///arat�l�r:
		long value = m_pProto->aApplies[i].lValue;

///�st�ne eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if(IsMountItem())
			continue;
#endif

///arat�l�r:
	m_pOwner->ComputeBattlePoints();

///�st�ne eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (IsMountItem())
		ch->MountSummon(this);
#endif

///arat�l�r:
	if (this != m_pOwner->GetWear(GetCell() - INVENTORY_MAX_NUM))
	{
		sys_err("m_pOwner->GetWear() != this");
		return false;
	}

///alt�na eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (IsMountItem())
		m_pOwner->MountUnsummon(this);
#endif

///arat�l�r:
bool CItem::IsRideItem()
{
	if (ITEM_UNIQUE == GetType() && UNIQUE_SPECIAL_RIDE == GetSubType())
		return true;
	if (ITEM_UNIQUE == GetType() && UNIQUE_SPECIAL_MOUNT_RIDE == GetSubType())
		return true;

///alt�na eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (ITEM_COSTUME == GetType() && COSTUME_MOUNT == GetSubType())
		return true;
#endif


//arat�l�r:

bool CItem::IsRamadanRing()

///kod blo�unun alt�na eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
bool CItem::IsMountItem()
{
	if (GetType() == ITEM_COSTUME && GetSubType() == COSTUME_MOUNT)
		return true;
	
	return false;
}
#endif