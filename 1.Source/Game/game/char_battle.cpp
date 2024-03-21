//aratılır:
void CHARACTER::Dead(LPCHARACTER pkKiller, bool bImmediateDead)
{
	if (IsDead())
		return;

	{
		if (IsHorseRiding())
		{
			StopRiding();
		}
		else if (GetMountVnum())
		{
			RemoveAffect(AFFECT_MOUNT_BONUS);
			m_dwMountVnum = 0;
			UnEquipSpecialRideUniqueItem();

			UpdatePacket();
		}
	}

//Koşul komple değiştirilir:

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
void CHARACTER::Dead(LPCHARACTER pkKiller, bool bImmediateDead)
{
	if (IsDead())
		return;

	{
		if (IsHorseRiding())
		{
			StopRiding();
		}
		else if (GetMountVnum())
		{
			RemoveAffect(AFFECT_MOUNT); // ölünce binek kaybolma fixed
			RemoveAffect(AFFECT_MOUNT_BONUS);
			m_dwMountVnum = 0;
			UnEquipSpecialRideUniqueItem();

			UpdatePacket();
		}
	}
#endif

// aratılır

		pkItem = GetWear(WEAR_UNIQUE2);

		if (pkItem && pkItem->GetVnum() == UNIQUE_ITEM_SKIP_ITEM_DROP_PENALTY)
		{
			SyncQuickslot(QUICKSLOT_TYPE_ITEM, WEAR_UNIQUE2, 255);
			vec_item.push_back(std::make_pair(pkItem->RemoveFromCharacter(), EQUIPMENT));
		}

// altına eklenir

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		pkItem = GetWear(WEAR_COSTUME_MOUNT);

		if (pkItem && pkItem->GetVnum() == UNIQUE_ITEM_SKIP_ITEM_DROP_PENALTY)
		{
			SyncQuickslot(QUICKSLOT_TYPE_ITEM, WEAR_COSTUME_MOUNT, 255);
			vec_item.push_back(std::make_pair(pkItem->RemoveFromCharacter(), EQUIPMENT));
		}
#endif