// arat齦齬

#ifdef __AUCTION__
#include "auction_manager.h"
#endif

///alt齨a eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
#include "MountSystem.h"
#endif

// arat齦齬 toplam 5 kere

				ch->ReviveInvisible(5);

// 黶t黱e eklenir toplam 5 kere

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
				ch->CheckMount();
#endif

///arat齦齬:
ACMD(do_unmount)
{

///parantezin alt齨a eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if(ch->GetWear(WEAR_COSTUME_MOUNT))
	{
		CMountSystem* mountSystem = ch->GetMountSystem();
		LPITEM mount = ch->GetWear(WEAR_COSTUME_MOUNT);
		DWORD mobVnum = 0;
		
		if (!mountSystem && !mount)
			return;

		if(mount->GetValue(1) != 0)
			mobVnum = mount->GetValue(1);

		if (ch->GetMountVnum())
		{
			if(mountSystem->CountSummoned() == 0)
			{
				mountSystem->Unmount(mobVnum);
			}
		}
		return;
	}
#endif

// arat齦齬

	LPITEM item2 = ch->GetWear(WEAR_UNIQUE2);

// alt齨a eklenir

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	LPITEM item3 = ch->GetWear(WEAR_COSTUME_MOUNT);
#endif

// arat齦齬

	if (item2 && item2->IsRideItem())
	{
		ch->UnequipItem(item2);
	}

// alt齨a eklenir

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (item3 && item3->IsMountItem())
	{
		ch->UnequipItem(item3);
	}
#endif

///arat齦齬:
	CItem* pHair = ch->GetWear(WEAR_COSTUME_HAIR);

///alt齨a eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	CItem* pMount = ch->GetWear(WEAR_COSTUME_MOUNT);
#endif

///arat齦齬:
	if (pBody)
	{
		const char* itemName = pBody->GetName();
		ch->ChatPacket(CHAT_TYPE_INFO, "  BODY : %s", itemName);

		if (pBody->IsEquipped() && arg1[0] == 'b')
			ch->UnequipItem(pBody);
	}

///alt齨a eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (pMount)
	{
		const char* itemName = pMount->GetName();
		ch->ChatPacket(CHAT_TYPE_INFO, "  MOUNT : %s", itemName);

		if (pMount->IsEquipped() && arg1[0] == 'm')
			ch->UnequipItem(pMount);
	}
#endif

///arat齦齬:
ACMD(do_ride)
{
	[...]
}

///de餴⺶irilir:
ACMD(do_ride)
{
	dev_log(LOG_DEB0, "[DO_RIDE] start");
	if (ch->IsDead() || ch->IsStun())
		return;

	if (ch->GetMapIndex() == 113)
		return;

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (ch->IsPolymorphed() == true){
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("donusmuskenbinegebinemezsin."));
		return;
	}
	if(ch->GetWear(WEAR_COSTUME_MOUNT))
	{
		CMountSystem* mountSystem = ch->GetMountSystem();
		LPITEM mount = ch->GetWear(WEAR_COSTUME_MOUNT);
		DWORD mobVnum = 0;
		
		if (!mountSystem && !mount)
			return;
		
		if(mount->GetValue(1) != 0)
			mobVnum = mount->GetValue(1);
		
		if (ch->GetMountVnum())
		{
			if(mountSystem->CountSummoned() == 0)
			{
				mountSystem->Unmount(mobVnum);
			}
		}
		else
		{
			if(mountSystem->CountSummoned() == 1)
			{
				mountSystem->Mount(mobVnum, mount);
			}
		}
		
		return;
	}
#endif

	if (ch->IsHorseRiding())
	{
		ch->StopRiding();
		return;
	}

	if (ch->GetHorse() != NULL)
	{
		ch->StartRiding();
		return;
	}

	for (BYTE i=0; i<INVENTORY_MAX_NUM; ++i)
	{
		LPITEM item = ch->GetInventoryItem(i);
		if (NULL == item)
			continue;

		if (item->GetType() == ITEM_COSTUME && item->GetSubType() == COSTUME_MOUNT)	{
			ch->UseItem(TItemPos (INVENTORY, i));
			return;
		}
	}

	ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("富阑 刚历 家券秦林技夸."));
}


