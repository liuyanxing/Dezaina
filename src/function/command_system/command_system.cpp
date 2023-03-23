class CommandSystem
{
public:
		CommandSystem();
		~CommandSystem();

		void executeCommand(int command_id);
		void executeCommand(const char* command, const char* args);

		int registerCommand(Command* command);
};