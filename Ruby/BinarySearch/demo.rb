require './BinarySearch.rb'

100.times do |i|
  puts "#{i}: #{binary_search([*0..90], i)}"
end
