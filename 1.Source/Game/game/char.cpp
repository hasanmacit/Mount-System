/// arat

#include "DragonSoul.h"

// altýna ekle
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
#include "MountSystem.h"
#endif


///arat:
	m_pointsInstant.iDragonSoulActiveDeck = -1;

/// altýna ekle:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	m_mountSystem = 0;
	m_bIsMount = false;
#endif


///arat:
	if (m_pkDungeon)
	{
		SetDungeon(NULL);
	}

/// altýna ekle:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (m_mountSystem)
	{
		m_mountSystem->Destroy();
		delete m_mountSystem;

		m_mountSystem = 0;
	}
	
	if(GetMountVnum())
	{
		RemoveAffect(AFFECT_MOUNT);
		RemoveAffect(AFFECT_MOUNT_BONUS);
	}
	HorseSummon(false);
#endif


///arat:
	MessengerManager::instance().Logout(GetName());

/// altýna ekle:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if(GetMountVnum())
	{
		RemoveAffect(AFFECT_MOUNT);
		RemoveAffect(AFFECT_MOUNT_BONUS);
	}
#endif


///arat:
#ifdef __PET_SYSTEM__
	// NOTE: ?? ???? PC? ???? PetSystem? ??? ?. ?? ??? ??? ?????? NPC?? ?? ?..
	if (m_petSystem)
	{
		m_petSystem->Destroy();
		delete m_petSystem;
	}

	m_petSystem = M2_NEW CPetSystem(this);
#endif

/// altýna ekle:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (m_mountSystem)
	{
		m_mountSystem->Destroy();
		delete m_mountSystem;
	}

	m_mountSystem = M2_NEW CMountSystem(this);
#endif


///arat:
	if (IsPC())
	{
		// ? ?? ?? ?? ?? ??? ?? ?? ???? ??? ?? ???.
		// ??? ?? ?? ??? ?? ?????, ??/??? ?? ?? ??
		// ????? ? ???? ? ???.
		if (GetMountVnum()) 
		{
			if (GetHorseST() > GetPoint(POINT_ST))
				PointChange(POINT_ST, GetHorseST() - GetPoint(POINT_ST));

			if (GetHorseDX() > GetPoint(POINT_DX))
				PointChange(POINT_DX, GetHorseDX() - GetPoint(POINT_DX));

			if (GetHorseHT() > GetPoint(POINT_HT))
				PointChange(POINT_HT, GetHorseHT() - GetPoint(POINT_HT));

			if (GetHorseIQ() > GetPoint(POINT_IQ))
				PointChange(POINT_IQ, GetHorseIQ() - GetPoint(POINT_IQ));
		}

	}

/// deðiþtir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	if (IsPC())
	{
		if (GetMountVnum() && !GetWear(WEAR_COSTUME_MOUNT))
		{
			if (GetHorseST() > GetPoint(POINT_ST))
				PointChange(POINT_ST, GetHorseST() - GetPoint(POINT_ST));

			if (GetHorseDX() > GetPoint(POINT_DX))
				PointChange(POINT_DX, GetHorseDX() - GetPoint(POINT_DX));

			if (GetHorseHT() > GetPoint(POINT_HT))
				PointChange(POINT_HT, GetHorseHT() - GetPoint(POINT_HT));

			if (GetHorseIQ() > GetPoint(POINT_IQ))
				PointChange(POINT_IQ, GetHorseIQ() - GetPoint(POINT_IQ));
		}

	}
#endif

///arat:
BYTE CHARACTER::GetChatCounter() const
{
	return m_bChatCounter;
}

/// altýna ekle:

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
BYTE CHARACTER::GetMountCounter() const
{
	return m_bMountCounter;
}

void CHARACTER::ResetMountCounter()
{
	m_bMountCounter = 0;
}

BYTE CHARACTER::IncreaseMountCounter()
{
	return ++m_bMountCounter;
}
#endif

///arat:
	m_bChatCounter = 0;

/// altýna ekle:

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	m_bMountCounter = 0;
#endif


/// dosyanýn en sonuna ekle.
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
void CHARACTER::MountSummon(LPITEM mountItem)
{
	if (IsPolymorphed() == true)
	{
		ChatPacket(CHAT_TYPE_INFO, LC_TEXT("donusmuskenbinegebinemezsin."));
		return; 
	}
	if (GetMapIndex() == 113)
		return;
	
	if (CArenaManager::instance().IsArenaMap(GetMapIndex()) == true)
		return;

	CMountSystem* mountSystem = GetMountSystem();
	DWORD mobVnum = 0;
	
	if (!mountSystem || !mountItem)
		return;
	
	if(mountItem->GetValue(1) != 0)
		mobVnum = mountItem->GetValue(1);
	
	if (IsHorseRiding())
		StopRiding();
	
	if (GetHorse())
		HorseSummon(false);
	
	mountSystem->Summon(mobVnum, mountItem, false);
}

void CHARACTER::MountUnsummon(LPITEM mountItem)
{
	CMountSystem* mountSystem = GetMountSystem();
	DWORD mobVnum = 0;
	
	if (!mountSystem || !mountItem)
		return;
	
	if(mountItem->GetValue(1) != 0)
		mobVnum = mountItem->GetValue(1);
	
	if (GetMountVnum() == mobVnum)
		mountSystem->Unmount(mobVnum);

	mountSystem->Unsummon(mobVnum);
}

void CHARACTER::CheckMount()
{
	CMountSystem* mountSystem = GetMountSystem();
	LPITEM mountItem = GetWear(WEAR_COSTUME_MOUNT);
	DWORD mobVnum = 0;
	
	if (!mountSystem || !mountItem)
		return;
	
	if(mountItem->GetValue(1) != 0)
		mobVnum = mountItem->GetValue(1);
	
	if(mountSystem->CountSummoned() == 0)
	{
		mountSystem->Summon(mobVnum, mountItem, false);
	}
}

bool CHARACTER::IsRidingMount()
{
	return (GetWear(WEAR_COSTUME_MOUNT) || FindAffect(AFFECT_MOUNT));
}
#endif




