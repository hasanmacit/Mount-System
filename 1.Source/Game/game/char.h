///aratýlýr:

class CPetSystem;

// altýna eklenir.

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
class CMountSystem;
#endif


///aratýlýr:
		BYTE			GetChatCounter() const;

///altýna eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		void			ResetMountCounter();
		BYTE			IncreaseMountCounter();
		BYTE			GetMountCounter() const;
#endif

///aratýlýr:
		BYTE			m_bChatCounter;

///altýna eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		BYTE			m_bMountCounter;
#endif

///aratýlýr:
#ifdef __PET_SYSTEM__
	public:
		CPetSystem*			GetPetSystem()				{ return m_petSystem; }

	protected:
		CPetSystem*			m_petSystem;

	public:
#endif

///altýna eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	public:
		CMountSystem*		GetMountSystem() { return m_mountSystem; }
		
		void 				MountSummon(LPITEM mountItem);
		void 				MountUnsummon(LPITEM mountItem);
		void 				CheckMount();
		bool 				IsRidingMount();
	protected:
		CMountSystem*		m_mountSystem;
#endif

///aratýlýr:
#ifdef __PET_SYSTEM__
	private:
		bool m_bIsPet;
	public:
		void SetPet() { m_bIsPet = true; }
		bool IsPet() { return m_bIsPet; }
#endif

///altýna eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	private:
		bool m_bIsMount;
	public:
		void SetMount() { m_bIsMount = true; }
		bool IsMount() { return m_bIsMount; }
#endif



