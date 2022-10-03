def binary_search(arr, value, from: 0, to: nil)
  to = arr.length if to.nil?

  len = (to - from)

  if len <= 0 then
    return false
  end

  pos = from + (len / 2)

  if arr[pos] == value then
    return pos
  elsif arr[pos] > value then
    return binary_search(arr, value, from: from, to: pos)
  elsif arr[pos] < value then
    return binary_search(arr, value, from: pos+1, to: to)
  end
end
