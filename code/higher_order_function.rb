def call_block
    puts "Start of method."
    yield
    puts "End of method."
end 
call_block do 
    puts "I am inside call_block method."
end

def calculate(a,b)
  c = yield(a,b)
  p c
end

calculate(10,15) {
  |a,b| 
  b-a
}

#Shitty code for factorial - done to do 
def factorial
  yield
end

n = gets.to_i
factorial do
  puts (1..n).inject(:*)
end



