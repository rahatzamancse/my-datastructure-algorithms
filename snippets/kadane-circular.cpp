/// Name: Kadane's Algorithm for Circular Array
/// Description: Finds the maximum sum subarray from circular subarrray.
/// Detail: Given a circular array of positive and negetive values, it finds the sequencial subarray with maximum sum.
/// Dependencies: kadane
/// Guarantee: int circularKadane(
pair<int, pair<int, int> > circularKadane(vector<int> a) {
	if(a.size() == 0) return {0, {-1, -1}};
	if(a.size() == 1) {
		if(a[0] < 0) return {0, {-1, -1}};
		else return {a[0], {0, 0}};
	}
	auto nowrap_kadane = kadane(a);
	int sum = accumulate(a.begin(), a.end(), 0);
	
	transform(a.begin(), a.end(), a.begin(), [](const auto &i) {return -i;});
	auto wrap_kadane = kadane(a);
	wrap_kadane.first = sum + wrap_kadane.first;
	int &wrap_start = wrap_kadane.second.first;
	int &wrap_end = wrap_kadane.second.second;

	if(wrap_start > 0 && wrap_end < a.size()-1) { // this means subarray is strictly inside
		wrap_start--, wrap_end++;
		swap(wrap_start, wrap_end);
	}
	else { // subarray is touching one or both side of the main array
		if(wrap_start == 0 && wrap_end == a.size() - 1) { // subarray == whole array
			wrap_start = -1, wrap_end = -1;
		}
		else if(wrap_start == 0) { // subarray is on left of array
			wrap_start = wrap_end + 1;
			wrap_end = a.size() - 1;
		}
		else { // subarray is on right of array
			wrap_end = wrap_start-1;
			wrap_start = 0;
		}
	}

	return max(wrap_kadane, nowrap_kadane);
}