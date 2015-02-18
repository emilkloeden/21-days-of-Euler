#!/usr/bin/env ruby

# Parse file into a two dimensional array and convert str to int
# store in variable named 'triangle'
triangle = IO.readlines('../67.txt').map {|line| line.split(' ')}.map{|array| array.map{|str| str.to_i}}

# Define a function to find the maximum path whilst iterating
# over a triangle
def find_max_path (triangle)
    # iterate from the bottom up (largest array to smallest)
    i = triangle.length - 1
    while i > 0;
        j = 0
        current_array = triangle[i]
        next_array = triangle[i-1]
        combined_array = [];
        
        # iterate over each array and the one above it
        # grabbing the max sum of adjacent numbers and
        # placing them into a new, summed array
        while j < current_array.length - 1;
            current_cell = current_array[j]
            next_cell = current_array[j+1]
            shared_cell = next_array[j]
            if current_cell > next_cell;
                max_cell = current_cell + shared_cell
            else
                max_cell = next_cell + shared_cell
            end
            combined_array.push(max_cell)
            j += 1

        end

        # replace last two arrays with the summed array
        triangle.pop
        triangle.pop
        triangle.push(combined_array)
        i -= 1
    end

    # return the value within the final dimension of the 2D array
    return triangle[0][0]
end

# Print result
p find_max_path(triangle)