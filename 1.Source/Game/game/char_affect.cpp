///aratýlýr:
	if ( CArenaManager::instance().IsArenaMap(GetMapIndex()) == true )
	{
		RemoveGoodAffect();
	}

///altýna eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	RemoveAffect(AFFECT_MOUNT);
	RemoveAffect(AFFECT_MOUNT_BONUS);
#endif

