///arat�l�r:

class CPetSystem;

// alt�na eklenir.

#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
class CMountSystem;
#endif


///arat�l�r:
		BYTE			GetChatCounter() const;

///alt�na eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		void			ResetMountCounter();
		BYTE			IncreaseMountCounter();
		BYTE			GetMountCounter() const;
#endif

///arat�l�r:
		BYTE			m_bChatCounter;

///alt�na eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
		BYTE			m_bMountCounter;
#endif

///arat�l�r:
#ifdef __PET_SYSTEM__
	public:
		CPetSystem*			GetPetSystem()				{ return m_petSystem; }

	protected:
		CPetSystem*			m_petSystem;

	public:
#endif

///alt�na eklenir:
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

///arat�l�r:
#ifdef __PET_SYSTEM__
	private:
		bool m_bIsPet;
	public:
		void SetPet() { m_bIsPet = true; }
		bool IsPet() { return m_bIsPet; }
#endif

///alt�na eklenir:
#ifdef ENABLE_MOUNT_COSTUME_SYSTEM
	private:
		bool m_bIsMount;
	public:
		void SetMount() { m_bIsMount = true; }
		bool IsMount() { return m_bIsMount; }
#endif



