def binary_search(arr, value, *, start = 0, end = None):
	if not end:
		end = len(arr)

	length = (end - start)

	if length <= 0:
		return False

	pos = start + (length // 2)

	if arr[pos] == value:
		return pos
	elif arr[pos] > value:
		return binary_search(arr, value, start = start, end = pos)
	elif arr[pos] < value:
		return binary_search(arr, value, start = pos+1, end = end)
