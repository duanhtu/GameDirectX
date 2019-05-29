#include<Windows.h>

class Delay
{
private:
	DWORD startTime;
	DWORD tickPerFrame;
	bool ready, terminated;
public:
	// bat dau
	void start(DWORD time = -1);
	// khi thoi gian dinh san ket thuc
	bool isTerminated();
	void setIsTerminated(bool isTerminated);
	// trong thoi gian chay
	bool isOnTime();
	// goi trong object update
	void update();
	void init(DWORD time = -1);
	Delay();
	~Delay();
};


