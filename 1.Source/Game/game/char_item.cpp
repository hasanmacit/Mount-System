///arat�l�r:
		if (UNIQUE_SPECIAL_RIDE == item->GetSubType() && IS_SET(item->GetFlag(), ITEM_FLAG_QUEST_USE))
		{
			quest::CQuestManager::instance().UseItem(GetPlayerID(), item, false);
		}

///de�i�tirilir:
		if (COSTUME_MOUNT == item->GetSubType())
		{
			quest::CQuestManager::instance().UseItem(GetPlayerID(), item, false);
		}
		if ((ITEM_UNIQUE == item->GetType() && UNIQUE_SPECIAL_RIDE == item->GetSubType() && IS_SET(item->GetFlag(), ITEM_FLAG_QUEST_USE))
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		|| (ITEM_COSTUME == item->GetType() && COSTUME_MOUNT == item->GetSubType()))
#endif
		{
			quest::CQuestManager::instance().UseItem(GetPlayerID(), item, false);
		}

///arat�l�r:
				static BYTE abSlot[] = 

///i�ine eklenir:
				static BYTE abSlot[] = ,WEAR_COSTUME_MOUNT

///arat�l�r:
	{
		LPITEM u = GetWear(WEAR_UNIQUE2);

		if (u && u->GetVnum() == dwItemVnum)
			return true;
	}

///alt�na eklenir:

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	{
		LPITEM u = GetWear(WEAR_COSTUME_MOUNT);

		if (u && u->GetVnum() == dwItemVnum)
			return true;
	}
#endif

///arat�l�r:
	{
		LPITEM u = GetWear(WEAR_UNIQUE2);

		if (u && u->GetSpecialGroup() == (int)dwGroupVnum)
			return true;
	}

///alt�na eklenir:

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	{
		LPITEM u = GetWear(WEAR_COSTUME_MOUNT);

		if (u && u->GetSpecialGroup() == (int)dwGroupVnum)
			return true;
	}
#endif

///arat�l�r:
bool CHARACTER::UnEquipSpecialRideUniqueItem()
{
	LPITEM Unique1 = GetWear(WEAR_UNIQUE1);
	LPITEM Unique2 = GetWear(WEAR_UNIQUE2);

///alt�na eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	LPITEM Unique3 = GetWear(WEAR_COSTUME_MOUNT);
#endif

///arat�l�r:
	if (NULL != Unique2)
	{
		if (UNIQUE_GROUP_SPECIAL_RIDE == Unique2->GetSpecialGroup())
		{
			return UnequipItem(Unique2);
		}
	}

///alt�na eklenir:

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (NULL != Unique3)
	{
		if (UNIQUE_GROUP_SPECIAL_RIDE == Unique3->GetSpecialGroup())
		{
			return UnequipItem(Unique3);
		}
	}
#endif

///arat�l�r:
		if ((GetWear(WEAR_UNIQUE1) && GetWear(WEAR_UNIQUE1)->IsSameSpecialGroup(item)) ||
			(GetWear(WEAR_UNIQUE2) && GetWear(WEAR_UNIQUE2)->IsSameSpecialGroup(item)))


///de�i�tirilir:
		if ((GetWear(WEAR_UNIQUE1) && GetWear(WEAR_UNIQUE1)->IsSameSpecialGroup(item)) ||
			(GetWear(WEAR_UNIQUE2) && GetWear(WEAR_UNIQUE2)->IsSameSpecialGroup(item)) ||
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			(GetWear(WEAR_COSTUME_MOUNT) && GetWear(WEAR_COSTUME_MOUNT)->IsSameSpecialGroup(item)))
#endif

//arat�l�r:

		case ITEM_QUEST:

//alt�na eklenir:

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			if (GetWear(WEAR_COSTUME_MOUNT))
			{
				if (item->GetVnum() == 50051 || item->GetVnum() == 50052 || item->GetVnum() == 50053)
				{
					ChatPacket(CHAT_TYPE_INFO, LC_TEXT("YOU_CANNOT_USE_THIS_WHILE_RIDING"));
					return false;
				}
			}
#endif

