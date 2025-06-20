
#ifndef SENECA_MAILSERVER_H
#define SENECA_MAILSERVER_H
#include <string>

namespace seneca
{
	struct Message;
	class Plugin;

	class MailServer
	{
		std::string m_userName{};
		std::string m_userAddress{};

		
		Message* m_inbox{};
		size_t m_cnt{};

		void (*onNewMailArrived)(const Message&) {};

	
		Plugin* m_plugins[2]{};
	public:
		MailServer(const char* name, const char* address);
		MailServer(const MailServer& other);
		MailServer& operator=(const MailServer& other);
		MailServer(MailServer&& other) noexcept;
		MailServer& operator=(MailServer&& other) noexcept;
		~MailServer();
	
		void receiveMail(Message msg);

		void addPlugin(Plugin* thePlugin);
		void setObserver(void(*observer)(const Message&));

		Message& operator[](size_t idx);

		size_t getInboxSize() const;
		void showInbox() const;
	};
}

#endif