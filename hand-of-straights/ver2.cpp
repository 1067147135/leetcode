class Solution {
public:
    public:
	bool isNStraightHand(vector<int>& hand, int groupSize) {
		int length = hand.size();
		std::sort(hand.begin(), hand.end());

		int Data[10001]{};
		int Cnt[10001]{};

		Data[0] = hand[0];
		int DataIdx = 0;
		Cnt[0] = 1;
		//Data[n]记录不重复的数字
		//Cnt[n]记录Data[n]出现的次数
		for (int idx = 1; idx < length; ++idx)
		{
			if (hand[idx] != hand[idx - 1])
				Data[++DataIdx] = hand[idx];
			++Cnt[DataIdx];
		}

		/*判断方法：
		从Data[n]开始，以该数字的出现次数Cnt[n]为基准
		后面连续数字出现的次数Cnt[n+1] ~ Cnt[n+groupSize-1]分别减去Cnt[n]
		不连续或者减完<0则不符合条件，剔除。
		*/
		for (int idx = 0; idx <= DataIdx; )
		{
			int Mark = idx;
			int StartCnt = Cnt[idx];
			Cnt[idx] = 0;
			for (int inner = idx + 1; inner < idx + groupSize; ++inner)
			{
				if (Data[inner] != Data[inner - 1] + 1)
				{
					return false;
				}
				Cnt[inner] -= StartCnt;
				if (Cnt[inner] < 0)
				{
					return false;
				}
				//对于Cnt减完等于0的情况，可以从该组最后一个被消耗完的数字开始下一次的测试，
				//减少循环的执行次数，并且进行一次剪枝，如果一个groupsize内，后一个为cnt被减为0 ，而前一个不是0
				//那么以前一个为开始的顺子肯定会断掉，所以可以剪掉
				else if (Cnt[inner] == 0)
				{
					if (Cnt[inner - 1] == 0)
						Mark = inner + 1;
					else
						return false;
				}
			}
			if (Mark != idx)
				idx = Mark;
			else
				++idx;
		}

		return true;
	}
};
