///arat�l�r:
				if (!pChar->IsPet() && (true == pChar->IsMonster() || true == pChar->IsStone()))

///de�i�tirilir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
				if (!pChar->IsPet() && !pChar->IsMount() && (true == pChar->IsMonster() || true == pChar->IsStone()))
#else
				if (!pChar->IsPet() && (true == pChar->IsMonster() || true == pChar->IsStone()))
#endif
