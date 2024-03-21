///aratılır:

	int pc_get_special_ride_vnum(lua_State* L)
	{
		LPCHARACTER pChar = CQuestManager::instance().GetCurrentCharacterPtr();

		if (NULL != pChar)
		{
			LPITEM Unique1 = pChar->GetWear(WEAR_UNIQUE1);
			LPITEM Unique2 = pChar->GetWear(WEAR_UNIQUE2);

//altına eklenir:

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			LPITEM Unique3 = pChar->GetWear(WEAR_COSTUME_MOUNT);
#endif

//aratılır:

			if (NULL != Unique2)
			{
				if (UNIQUE_GROUP_SPECIAL_RIDE == Unique2->GetSpecialGroup())
				{
					lua_pushnumber(L, Unique2->GetVnum());
					lua_pushnumber(L, Unique2->GetSocket(2));
					return 2;
				}
			}

//altına eklenir:

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
			if (NULL != Unique3)
			{
				if (UNIQUE_GROUP_SPECIAL_RIDE == Unique3->GetSpecialGroup())
				{
					lua_pushnumber(L, Unique3->GetVnum());
					lua_pushnumber(L, Unique3->GetSocket(2));
					return 2;
				}
			}
#endif
