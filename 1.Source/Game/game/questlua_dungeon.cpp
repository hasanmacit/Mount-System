///aratýlýr:
				if (!pChar->IsPet() && (true == pChar->IsMonster() || true == pChar->IsStone()))

///deðiþtirilir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
				if (!pChar->IsPet() && !pChar->IsMount() && (true == pChar->IsMonster() || true == pChar->IsStone()))
#else
				if (!pChar->IsPet() && (true == pChar->IsMonster() || true == pChar->IsStone()))
#endif
