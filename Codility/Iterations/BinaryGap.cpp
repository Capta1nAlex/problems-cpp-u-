int solution(int N) {
	int maxSum = 0, tempSum = 0;
	int binaryNum[32];
	int count = 0;
	while (N > 0) {
		binaryNum[count] = N % 2;
		N /= 2;
		count++;
	}
	for (int i = count-1; i >= 0; i--) {
		if (binaryNum[i] == 0) {
			tempSum++;
		}
		else {
			if (tempSum >= maxSum) {
				maxSum = tempSum;
			}
			tempSum = 0;
		}
	}
    return maxSum;
}
