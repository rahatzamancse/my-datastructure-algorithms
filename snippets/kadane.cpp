/// Name: Kadane's Algorithm
/// Description: Finds the maximum sum subarray.
/// Detail: Given an array of positive and negetive values, it finds the sequencial subarray with maximum sum.
/// Guarantee: int kadane(
pair<int, pair<int, int> > kadane(const vector<int> &a) {
	if(a.size() == 0) return {0, {-1, -1}};
	if(a.size() == 1) {
		if(a[0] < 0) return {0, {-1, -1}};
		else return {a[0], {0, 0}};
	}
	int max_so_far = INT_MIN,
		max_ending_here = 0,
		start =0,
		end = 0,
		s=0;
	for (int i=0; i< a.size(); i++) {
		max_ending_here += a[i];
		if (max_so_far < max_ending_here) {
			max_so_far = max_ending_here;
			start = s;
			end = i;
		}
		if (max_ending_here <= 0) {
			max_ending_here = 0;
			s = i + 1;
		}
	}
	return {max_so_far, {start, end}};
}