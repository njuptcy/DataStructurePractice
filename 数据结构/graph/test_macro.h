#define TEST_MACRO( exp )  \
	cout << "expression:"<<#exp << endl; \
	cout << "result:" << exp << endl;\


//NAME�����ᱻ�滻��##
//#define COMMAND(NAME)  { #NAME, NAME ## _command }
//
//struct command
//{
//	char *name;
//	void(*function) (void);
//};


//struct command commands[] =
//{
//	COMMAND(quit),
//	COMMAND(help)
//};
