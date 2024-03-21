///aratılır:
	int horse_ride(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

///altına eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if (ch->IsRidingMount())
			return 0;
		if (ch->GetMapIndex() == 113)
			return 0;
#endif

///aratılır:
	int horse_summon(lua_State* L)
	{
		LPCHARACTER ch = CQuestManager::instance().GetCurrentCharacterPtr();

///altına eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		if (ch->IsRidingMount())
			return 0;
		if (ch->GetMapIndex() == 113)
			return 0;
#endif