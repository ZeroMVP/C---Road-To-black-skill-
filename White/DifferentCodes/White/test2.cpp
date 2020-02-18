
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	// 1. ���� �������� �������� ������ 2 ���������, ������� �� �������
	int range_length = range_end - range_begin;
	if (range_length < 2) {
		return;
	}

	// 2. ������� ������, ���������� ��� �������� �������� ���������
	vector<typename RandomIt::value_type> elements(range_begin, range_end);

	// 3. ��������� ������ �� ��� ������ �����
	auto mid = elements.begin() + range_length / 2;

	// 4. �������� ������� MergeSort �� ������ �������� �������
	MergeSort(elements.begin(), mid);
	MergeSort(mid, elements.end());

	// 5. � ������� ��������� merge ������� ��������������� ��������
	// � �������� ��������
	// merge -> http://ru.cppreference.com/w/cpp/algorithm/merge
	merge(elements.begin(), mid, mid, elements.end(), range_begin);
}