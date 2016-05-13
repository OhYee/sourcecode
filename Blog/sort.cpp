//冒泡排序，输入待排序数组，和待排序数据量
void BubbleSort(int a[],int n) {
	int ThisSwapPosition = n - 1;//本轮最后一个交换的位置
	bool HasSwap = false;
	for(int i = 0;i < n;i++) {
		HasSwap = false;
		int LastSwapPosition = ThisSwapPosition;//上轮最后一个交换的位置
		for(int j = 1;j < LastSwapPosition;j++) {
			if(a[j - 1] > a[j]) {
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
				ThisSwapPosition = j;
				HasSwap = true;//本轮发生交换
			}
		}
		if(!HasSwap)
			break;
	}
}