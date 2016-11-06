
class LIS_stack {
private:
	static const int SIZE = maxn;//最大长度
	int len;//长度
	int Stack[SIZE];
public:
	LIS_stack() {
		len = 0;
		memset(Stack,0,sizeof(Stack));
	}
	void push(int num) {
		if(len == 0 || Stack[len - 1] < num) {
			Stack[len++] = num;
		} else {
			for(int i = 0;i < len;i++) {
				if(Stack[i] > num) {
					Stack[i] = num;
					break;
				}
			}
		}
	}
	int lenth() {
		return len;
	}

};

int LIS(int *a,int len) {
	LIS_stack s;
	for(int i = 0;i < len;i++) 
		s.push(a[i]);
	return s.lenth();
}
